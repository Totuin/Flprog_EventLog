#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEEPROM.h"
#include "flprogAbstractEventLog.h"
#include "utilites/flprogEventLogEvent.h"
#include "utilites/flprogEepromEventLogRecord.h"

// Журнал событий поверх FLProgAbstractEEPROM: не владеет объектом EEPROM.
// Перед setEEprom() необходимо определить типы всех полей.
// Привязка не должна очищать уже сохранённые события.
class FlprogEepromEventLog : public FlprogAbstractEventLog
{

public:
    FlprogEepromEventLog(uint16_t eventsSize, uint16_t recordsSize, uint8_t fieldsSize);
    ~FlprogEepromEventLog() override;
    virtual FlprogEventLogAbstractRecord *getRecord(uint16_t index) override;
    // Привязать разметку в EEPROM (начальный адрес >= 1).
    // Возвращает первый свободный адрес; 0 — ошибка разметки/переполнения.
    // Размер реального чипа здесь проверить невозможно — его проверяет вызывающий код.
    uint16_t setEEprom(FLProgAbstractEEPROM *chip, uint16_t addres);

protected:
    FlprogEepromEventLogRecord *_records = nullptr;
};
