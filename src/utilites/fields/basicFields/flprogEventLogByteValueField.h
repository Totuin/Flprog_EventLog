#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEventLogAbstractField.h"

// Поле uint8_t в оперативной памяти, начальное значение 0.
class FlprogEventLogByteValueField : public FlprogEventLogAbstractField
{
public:
    virtual uint8_t byteValue() override { return _value; };
    virtual void setByteValue(uint8_t value) override { _value = value; };

protected:
     uint8_t _value = 0;
};
