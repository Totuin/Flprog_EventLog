#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEventLogAbstractField.h"

class FlprogEventLogIntValueField : public FlprogEventLogAbstractField
{
public:
    virtual int16_t intValue() { return _value; };
    virtual void setIntValue(int16_t value) { _value = value; };

protected:
    virtual void privateCopyFrom(FlprogEventLogAbstractField *field) { _value = field->intValue(); };
    int16_t _value;
};
