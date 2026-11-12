#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEventLogAbstractField.h"

// Поле int32_t в оперативной памяти, начальное значение 0.
class FlprogEventLogLongValueField : public FlprogEventLogAbstractField
{

public:
    virtual int32_t longValue() override { return _value; };
    virtual void setLongValue(int32_t value) override { _value = value; };

protected:
        int32_t _value = 0;
};
