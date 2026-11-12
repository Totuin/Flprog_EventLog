#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "fields/eepromFields/flprogEepromEventLogTimeField.h"
#include "fields/eepromFields/flprogEepromEventLogByteValueField.h"
#include "fields/eepromFields/flprogEepromEventLogIntValueField.h"
#include "fields/eepromFields/flprogEepromEventLogBooleanValueField.h"
#include "fields/eepromFields/flprogEepromEventLogLongValueField.h"
#include "fields/eepromFields/flprogEepromEventLogUnLongValueField.h"
#include "flprogEventLogEvent.h"
#include "flprogEventLogAbstractRecord.h"

// Запись в EEPROM: значения берутся из RAM-копии FLProgAbstractEEPROM.
// Формат: 1 байт номера события + 2 байта веса + значения полей.
class FlprogEepromEventLogRecord : public FlprogEventLogAbstractRecord
{
public:
    ~FlprogEepromEventLogRecord() override;
    virtual void setFieldSize(uint8_t fieldsSize) override;
    virtual void setTimeField(uint8_t index) override;
    virtual void setByteField(uint8_t index) override;
    virtual void setIntegerField(uint8_t index) override;
    virtual void setBooleanField(uint8_t index) override;
    virtual void setLongField(uint8_t index) override;
    virtual void setUnLongField(uint8_t index) override;
    virtual FlprogEventLogAbstractField *getField(uint8_t index) override;

    bool isBoolField(uint8_t index);
    uint8_t eepromSize(uint8_t index);
    void setEeprom(uint8_t index, FLProgAbstractEEPROM *chip, uint16_t address, uint8_t bit = 0);
    void setEventIndexAddress(FLProgAbstractEEPROM *chip, uint16_t address);
    void setWeightAddress(FLProgAbstractEEPROM *chip, uint16_t address);

    virtual void setEvent(uint8_t index) override;
    virtual void setWeight(uint16_t value) override;

    virtual bool hasEvent() override { return getWeight() > 0; };
    virtual uint8_t event() override;
    virtual uint16_t getWeight() override;

protected:
    FlprogEepromEventLogAbstractField **_fields = nullptr;
    FLProgAbstractEEPROM *_chip = 0;
    uint16_t _eventIndexAddress = 0;
    uint16_t _weightAddress = 0;
};
