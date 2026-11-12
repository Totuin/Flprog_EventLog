#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEventLogAbstractField.h"

// Поле int16_t в оперативной памяти, начальное значение 0.
class FlprogEventLogIntValueField : public FlprogEventLogAbstractField
{
public:
    virtual int16_t intValue() override { return _value; };
    virtual void setIntValue(int16_t value) override { _value = value; };

protected:
      int16_t _value = 0;
};
