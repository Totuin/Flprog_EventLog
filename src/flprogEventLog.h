#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogAbstractEventLog.h"
#include "utilites\flprogEventLogEvent.h"
#include "utilites\flprogEventLogRecord.h"

class FlprogEventLog : public FlprogAbstractEventLog
{

public:
    FlprogEventLog(uint16_t eventsSize, uint16_t recordsSize, uint8_t fieldsSize);
   virtual FlprogEventLogAbstractRecord *getRecord(uint16_t index);

protected:
    FlprogEventLogRecord *_records;
};
