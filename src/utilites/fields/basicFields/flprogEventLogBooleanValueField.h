#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEventLogAbstractField.h"

class FlprogEventLogBooleanValueField : public FlprogEventLogAbstractField
{

public:
    virtual bool booleanValue() { return _value; };
    virtual void setBooleanValue(bool value) { _value = value; };

protected:
     bool _value;
};
