#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEventLogAbstractField.h"

class FlprogEventLogByteValueField : public FlprogEventLogAbstractField
{
public:
    virtual uint8_t byteValue() { return _value; };
    virtual void setByteValue(uint8_t value) { _value = value; };

protected:
     uint8_t _value;
};
