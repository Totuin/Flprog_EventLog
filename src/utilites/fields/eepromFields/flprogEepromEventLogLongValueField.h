#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEepromEventLogAbstractField.h"

class FlprogEepromEventLogLongValueField : public FlprogEepromEventLogAbstractField
{

public:
    virtual int32_t longValue() { return _value; };
    virtual void setLongValue(int32_t value) { _value = value; };

protected:
    virtual void privateCopyFrom(FlprogEventLogAbstractField *field) { _value = field->longValue(); };
    int32_t _value;
};
