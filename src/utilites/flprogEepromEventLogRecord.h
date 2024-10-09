#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "fields\eepromFields\flprogEepromEventLogTimeField.h"
#include "fields\eepromFields\flprogEepromEventLogByteValueField.h"
#include "fields\eepromFields\flprogEepromEventLogIntValueField.h"
#include "fields\eepromFields\flprogEepromEventLogBooleanValueField.h"
#include "fields\eepromFields\flprogEepromEventLogLongValueField.h"
#include "fields\eepromFields\flprogEepromEventLogUnLongValueField.h"
#include "flprogEventLogEvent.h"
#include "flprogEventLogAbstractRecord.h"

class FlprogEepromEventLogRecord : public FlprogEventLogAbstractRecord
{
public:
    virtual void setFieldSize(uint8_t fieldsSize);
    virtual void setTimeField(uint8_t index);
    virtual void setByteField(uint8_t index);
    virtual void setIntegerField(uint8_t index);
    virtual void setBooleanField(uint8_t index);
    virtual void setLongField(uint8_t index);
    virtual void setUnLongField(uint8_t index);
    virtual FlprogEventLogAbstractField *getField(uint8_t index);

    bool isBoolField(uint8_t index);
    uint8_t eepromSize(uint8_t index);
    void setEeprom(uint8_t index, FLProgAbstractEEPROM *chip, uint16_t address, uint8_t bit = 0);
    void setEventIndexAddress(FLProgAbstractEEPROM *chip, uint16_t address);
    void setWeightAddress(FLProgAbstractEEPROM *chip, uint16_t address);

    virtual void setEvent(uint8_t index);
    virtual void setWeight(uint16_t value);

    virtual bool hasEvent() { return getWeight() > 0; };
    virtual uint8_t event();
    virtual uint16_t getWeight();

protected:
    FlprogEepromEventLogAbstractField **_fields;
    FLProgAbstractEEPROM *_chip = 0;
    uint16_t _eventIndexAddress;
    uint16_t _weightAddress;
};
