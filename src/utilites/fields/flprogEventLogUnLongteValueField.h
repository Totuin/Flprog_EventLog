#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEventLogAbstractField.h"

class FlprogEventLogUnLongteValueField : public FlprogEventLogAbstractField
{
public:
    virtual uint32_t unLongValue() { return _value; };
    virtual void setUnLongValue(uint32_t value) { _value = value; };

protected:
    virtual void privateCopyFrom(FlprogEventLogAbstractField *field) { _value = field->unLongValue(); };
    uint32_t _value;
};
