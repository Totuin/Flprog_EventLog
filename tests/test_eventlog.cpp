#include <cassert>
#include <cstdint>
#include <climits>
#include <iostream>
#include "flprogEventLog.h"
#include "flprogEepromEventLog.h"

static void testEmpty() {
  FlprogEventLog log(0,0,0);
  assert(!log.addNewEvent(0));assert(!log.hasEvent(0));assert(log.getUsedRecordsSize()==0);
  assert(log.getField(0,0)==nullptr);log.clearEventLog();log.resetRecord(0);
  FlprogEepromEventLog e(0,0,0);FLProgAbstractEEPROM mem;
  assert(e.setEEprom(&mem,1)==1);
  assert(!e.addNewEvent(0));
}
static void testRam(){
  FlprogEventLog log(3,3,5);
  log.setBooleanField(0);log.setIntegerField(1);log.setLongField(2);log.setUnLongField(3);log.setTimeField(4);
  assert(log.addNewEvent(2));
  log.setLastBooleanValue(0,true);log.setLastIntValue(1,-123);
  log.setLastLongValue(2,INT32_MIN);log.setLastUnLongValue(3,UINT32_MAX);log.setLastTimeValue(4,0xAABBCCDDu);
  assert(log.getBooleanValue(0,0)); assert(log.getIntValue(0,1)==-123);
  assert(log.getLongValue(0,2)==INT32_MIN); assert(log.getUnLongValue(0,3)==UINT32_MAX);
  assert(log.getTimeValue(0,4)==0xAABBCCDDu);
  assert(log.getUsedRecordsSize()==1);
  assert(log.addNewEvent(1)); assert(log.event(0)==1);assert(log.event(1)==2);
  assert(log.addNewEvent(0));assert(log.event(0)==0);assert(log.getUsedRecordsSize()==3);
  assert(log.addNewEvent(2));assert(log.event(0)==2);assert(log.getUsedRecordsSize()==3);
  log.resetRecord(1);assert(log.getUsedRecordsSize()==2);
  assert(log.addNewEvent(0)); assert(log.getUsedRecordsSize()==3);assert(log.event(0)==0);
  log.clearEventLog();assert(log.getUsedRecordsSize()==0);assert(!log.hasEvent(0));
  assert(log.addNewEvent(1)); assert(log.getUsedRecordsSize()==1);
  assert(log.getField(0,8)==nullptr);
  // Повторная смена типа освобождает прошлый объект.
  log.setLongField(2);log.setIntegerField(2);log.setLongField(2);
  assert(log.addNewEvent(256)==nullptr); // в EEPROM индекс хранится одним байтом
  FlprogEventLog only(1,1,0);assert(only.addNewEvent(0));assert(!only.getField(0,0));
  FlprogEventLog bounds(300,1,0);assert(bounds.addNewEvent(255));assert(!bounds.addNewEvent(256));
}
static void testOverflow(){
  FlprogEventLog log(2,3,0);
  auto* a=log.addNewEvent(0);assert(a);a->setWeight(65000);
  // Первая же следующая сортировка должна безопасно перенумеровать веса.
  assert(log.getUsedRecordsSize()==1);
  assert(log.addNewEvent(1)); assert(log.event(0)==1);assert(log.event(1)==0);
  for(int i=0;i<110000;++i){auto* x=log.addNewEvent(i%2);assert(x);assert(log.getUsedRecordsSize()==3);}
}
static void testEeprom(){
  FLProgAbstractEEPROM mem(500);
  FlprogEepromEventLog log(3,4,3);
  log.setBooleanField(0);log.setLongField(1);log.setTimeField(2);
  // Размер: четыре bool бита -> 1 байт; четыре записи по 3+4+4=11 байт
  assert(log.setEEprom(&mem,1)==46);
  assert(log.addNewEvent(1));log.setLastBooleanValue(0,true);
  log.setLastLongValue(1,-321);log.setLastTimeValue(2,123456789u);
  assert(log.getLongValue(0,1)==-321); assert(log.getTimeValue(0,2)==123456789u);
  // В новом объекте те же адреса, сохранённая история не должна стираться.
  FlprogEepromEventLog restored(3,4,3);
  restored.setBooleanField(0); restored.setLongField(1); restored.setTimeField(2);
  assert(restored.setEEprom(&mem,1)==46);
  assert(restored.getUsedRecordsSize()==1);assert(restored.event(0)==1);
  assert(restored.getBooleanValue(0,0));assert(restored.getLongValue(0,1)==-321);
  assert(restored.getTimeValue(0,2)==123456789u);
  restored.clearEventLog();assert(restored.getUsedRecordsSize()==0);
  assert(restored.addNewEvent(2));
  assert(restored.event(0)==2);
  // Отказ от частично некорректной схемы при переполнении адреса.
  FlprogEepromEventLog bad(1,2,1);bad.setLongField(0);
  assert(bad.setEEprom(&mem,65530)==0);
  assert(bad.setEEprom(nullptr,1)==0);
  assert(bad.setEEprom(&mem,0)==0);
  FlprogEepromEventLog missing(1,1,2); assert(missing.setEEprom(&mem,20)==23);
  assert(missing.addNewEvent(0));assert(!missing.getField(0,0));
}
int main(){testEmpty();testRam();testOverflow();testEeprom();std::cout<<"EVENTLOG_TEST_PASS\n";}
