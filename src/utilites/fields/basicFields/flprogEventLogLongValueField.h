#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEventLogAbstractField.h"

class FlprogEventLogLongValueField : public FlprogEventLogAbstractField
{

public:
    virtual int32_t longValue() { return _value; };
    virtual void setLongValue(int32_t value) { _value = value; };

protected:
        int32_t _value;
};
