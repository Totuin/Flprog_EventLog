#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEepromEventLogAbstractField.h"

// EEPROM-поле uint8_t: 1 байт.
class FlprogEepromEventLogByteValueField : public FlprogEepromEventLogAbstractField
{
public:
    virtual uint8_t byteValue() override;
    virtual uint8_t eepromSize() override { return 1; };
    virtual void setByteValue(uint8_t value) override;

protected:

};
