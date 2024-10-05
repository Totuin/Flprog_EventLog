#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEEPROM.h"
#include "flprogEventLogAbstractField.h"

class FlprogEepromEventLogAbstractField : public FlprogEventLogAbstractField
{
public:
    virtual bool isBoolField() { return false; };
    virtual uint8_t eepromSize() { return 0; };
    virtual void setEeprom(FLProgAbstractEEPROM *chip, uint16_t address, uint8_t bit = 0);

protected:
    FLProgAbstractEEPROM *_chip = 0;
    uint16_t _addres;
};
