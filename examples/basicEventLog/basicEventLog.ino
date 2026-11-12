#include <flprogEventLog.h>

// RAM-журнал: 5 типов событий, 10 записей, 6 полей на запись.
FlprogEventLog logData(5, 10, 6);

void setup()
{
  Serial.begin(115200);
  // Тип каждого поля задаётся до первого добавления события.
  logData.setTimeField(0);
  logData.setByteField(1);
  logData.setIntegerField(2);
  logData.setBooleanField(3);
  logData.setLongField(4);
  logData.setUnLongField(5);
  logData.setEventDescription(2, "Тестовое событие");

  if (logData.addNewEvent(2) != nullptr)
  {
    // Логический индекс 0 = последняя добавленная запись.
    logData.setLastBooleanValue(3, true);
    logData.setLastByteValue(1, 25);
    logData.setLastIntValue(2, -25);
    logData.setLastLongValue(4, -100000);
    logData.setLastUnLongValue(5, 4000000000UL);
    logData.setLastTimeValue(0, millis());
  }
  Serial.println(logData.getUsedRecordsSize());
}

void loop()
{
  // Новые события добавляются по факту события, не на каждом проходе loop().
}
