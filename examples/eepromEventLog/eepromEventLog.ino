#include <flprogEepromEventLog.h>
#include <flprogInternalEEPROM.h>

FlprogEepromEventLog logData(5, 10, 6);
// Для 10 записей с этой схемой нужно 183 байта, включая адрес старта 1.
// Выделяем 256 байт с запасом, если платформа располагает таким объёмом.
FLProgInternalEEPROM eeprom(256, 123);

bool layoutReady = false;
bool loggedOnce = false;

void setup()
{
  Serial.begin(115200);
  logData.setEventDescription(2, "Тестовое событие");
  logData.setTimeField(0);
  logData.setByteField(1);
  logData.setIntegerField(2);
  logData.setBooleanField(3);
  logData.setLongField(4);
  logData.setUnLongField(5);

  // Привязка адресов должна выполняться ДО begin(). Она не очищает историю.
  const uint16_t nextAddress = logData.setEEprom(&eeprom, 1);
  if (nextAddress == 0 || nextAddress > 256)
  {
    Serial.println("EEPROM: неверная разметка");
    return;
  }
  eeprom.begin();
  layoutReady = true;
  Serial.print("Записей после загрузки: ");
  Serial.println(logData.getUsedRecordsSize());
}

void loop()
{
  if (!layoutReady) return;
  // Вызывать регулярно: запись из RAM-копии в физическую EEPROM отложена.
  eeprom.pool();
  if (!loggedOnce && logData.addNewEvent(2) != nullptr)
  {
    logData.setLastBooleanValue(3, true);
    logData.setLastByteValue(1, 25);
    logData.setLastIntValue(2, -25);
    logData.setLastLongValue(4, -100000);
    logData.setLastUnLongValue(5, 4000000000UL);
    logData.setLastTimeValue(0, millis());
    loggedOnce = true;
  }
}
