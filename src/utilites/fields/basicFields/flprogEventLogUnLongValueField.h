#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEventLogAbstractField.h"

// Поле uint32_t в оперативной памяти, начальное значение 0.
class FlprogEventLogUnLongteValueField : public FlprogEventLogAbstractField
{
public:
    virtual uint32_t unLongValue() override { return _value; };
    virtual void setUnLongValue(uint32_t value) override { _value = value; };

protected:
    uint32_t _value = 0;
};
