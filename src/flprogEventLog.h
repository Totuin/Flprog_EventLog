#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogAbstractEventLog.h"
#include "utilites/flprogEventLogEvent.h"
#include "utilites/flprogEventLogRecord.h"

// Журнал в оперативной памяти. Буфер и таблицы полей принадлежат объекту.
// После заполнения новый элемент вытесняет самый старый.
class FlprogEventLog : public FlprogAbstractEventLog
{

public:
    FlprogEventLog(uint16_t eventsSize, uint16_t recordsSize, uint8_t fieldsSize);
    ~FlprogEventLog() override;
   virtual FlprogEventLogAbstractRecord *getRecord(uint16_t index) override;

protected:
    FlprogEventLogRecord *_records = nullptr;
};
