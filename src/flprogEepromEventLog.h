#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEEPROM.h"
#include "flprogAbstractEventLog.h"
#include "utilites\flprogEventLogEvent.h"
#include "utilites\flprogEepromEventLogRecord.h"

class FlprogEepromEventLog : public FlprogAbstractEventLog
{

public:
    FlprogEepromEventLog(uint16_t eventsSize, uint16_t recordsSize, uint8_t fieldsSize);
    virtual FlprogEventLogAbstractRecord *getRecord(uint16_t index);
    uint16_t setEEprom(FLProgAbstractEEPROM *chip, uint16_t addres);

protected:
    FlprogEepromEventLogRecord *_records;
};
