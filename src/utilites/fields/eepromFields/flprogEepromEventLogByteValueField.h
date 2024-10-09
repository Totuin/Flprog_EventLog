#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEepromEventLogAbstractField.h"

class FlprogEepromEventLogByteValueField : public FlprogEepromEventLogAbstractField
{
public:
    virtual uint8_t byteValue();
    virtual uint8_t eepromSize() { return 1; };
    virtual void setByteValue(uint8_t value);

protected:

};
