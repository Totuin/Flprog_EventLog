#include <cassert>
#include <iostream>
#include <cstring>
#include "flprogEepromEventLog.h"
#include "flprogEEPROM.h"
class RealApiEEPROM : public FLProgAbstractEEPROM {
public:
 explicit RealApiEEPROM(uint16_t size){_size=size;_data=new uint8_t[size]();_dataChanged=new bool[size]();}
 void begin() override{}
 void pool() override{}
 void cloneTo(RealApiEEPROM& another)const{
  assert(_size==another._size);
  std::memcpy(another._data,_data,_size);
 }
};
int main(){
 RealApiEEPROM mem(256);
 FlprogEepromEventLog log(5,10,6);
 log.setTimeField(0);log.setByteField(1);log.setIntegerField(2);log.setBooleanField(3);log.setLongField(4);log.setUnLongField(5);
 assert(log.setEEprom(&mem,1)==183);
 assert(log.addNewEvent(2));log.setLastTimeValue(0,0x12345678u);
 log.setLastByteValue(1,77);log.setLastIntValue(2,-567);
 log.setLastBooleanValue(3,true);log.setLastLongValue(4,INT32_MIN);log.setLastUnLongValue(5,UINT32_MAX);
 RealApiEEPROM fresh(256);mem.cloneTo(fresh);
 FlprogEepromEventLog restored(5,10,6);
 restored.setTimeField(0);restored.setByteField(1);restored.setIntegerField(2);restored.setBooleanField(3);restored.setLongField(4);restored.setUnLongField(5);
 assert(restored.setEEprom(&fresh,1)==183);
 assert(restored.getUsedRecordsSize()==1 && restored.event(0)==2);
 assert(restored.getTimeValue(0,0)==0x12345678u);
 assert(restored.getByteValue(0,1)==77);
 assert(restored.getIntValue(0,2)==-567);
 assert(restored.getBooleanValue(0,3));
 assert(restored.getLongValue(0,4)==INT32_MIN);
 assert(restored.getUnLongValue(0,5)==UINT32_MAX);
 std::cout<<"REAL_EEPROM_API_PASS\n";
}
