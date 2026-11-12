#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEepromEventLogAbstractField.h"

// Битовая упаковка bool: адрес байта и номер бита (0..7).
class FlprogEepromEventLogBooleanValueField : public FlprogEepromEventLogAbstractField
{

public:
    virtual bool booleanValue() override;
    virtual void setBooleanValue(bool value) override;
    virtual bool isBoolField() override { return true; };
    virtual void setEeprom(FLProgAbstractEEPROM *chip, uint16_t address, uint8_t bit = 0) override;

protected:
    uint8_t _bit;
};
