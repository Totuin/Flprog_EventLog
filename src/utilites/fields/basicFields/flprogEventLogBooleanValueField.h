#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEventLogAbstractField.h"

// Поле bool в оперативной памяти, начальное значение false.
class FlprogEventLogBooleanValueField : public FlprogEventLogAbstractField
{

public:
    virtual bool booleanValue() override { return _value; };
    virtual void setBooleanValue(bool value) override { _value = value; };

protected:
     bool _value = 0;
};
