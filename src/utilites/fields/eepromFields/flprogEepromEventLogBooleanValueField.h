#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEepromEventLogAbstractField.h"

class FlprogEepromEventLogBooleanValueField : public FlprogEepromEventLogAbstractField
{

public:
    virtual bool booleanValue();
    virtual void setBooleanValue(bool value);
    virtual bool isBoolField() { return true; };
    virtual void setEeprom(FLProgAbstractEEPROM *chip, uint16_t address, uint8_t bit = 0);

protected:
    uint8_t _bit;
};
