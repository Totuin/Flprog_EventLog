#include "flprogEepromEventLog.h"
#include "flprogInternalEEPROM.h"

FlprogEepromEventLog logData(5, 10, 6);

FLProgInternalEEPROM eeprom(110, 123);

void setup()
{
    logData.setEventDescription(0, "Событие 1");
    logData.setEventDescription(1, "Событие 2");
    logData.setEventDescription(2, "Событие 3");
    logData.setEventDescription(3, "Событие 4");
    logData.setEventDescription(4, "Событие 5");

    logData.setTimeField(0);
    logData.setByteField(1);
    logData.setIntegerField(2);
    logData.setBooleanField(3);
    logData.setLongField(4);
    logData.setUnLongField(5);
  

    logData.setEEprom(&eeprom, 1);

    eeprom.begin();
}

void loop()
{

    eeprom.pool();

    logData.addNewEvent(2);
    logData.setLastBooleanValue(3, false);
    logData.setLastByteValue(1, 25);
    logData.setLastIntValue(2, 25);
    logData.setLastLongValue(4, 25);
    logData.setLastUnLongValue(5, 25);
    logData.setLastTimeValue(0, 25);
}