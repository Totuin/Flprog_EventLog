#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEepromEventLogAbstractField.h"

class FlprogEepromEventLogBooleanValueField : public FlprogEepromEventLogAbstractField
{

public:
    virtual bool booleanValue() { return _value; };
    virtual void setBooleanValue(bool value) { _value = value; };

protected:
    virtual void privateCopyFrom(FlprogEventLogAbstractField *field) { _value = field->booleanValue(); };
    bool _value;
};
