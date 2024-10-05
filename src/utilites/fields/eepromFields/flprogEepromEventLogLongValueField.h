#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEepromEventLogAbstractField.h"

class FlprogEepromEventLogLongValueField : public FlprogEepromEventLogAbstractField
{

public:
    virtual int32_t longValue();
    virtual uint8_t eepromSize() { return 4; };
    virtual void setLongValue(int32_t value);

protected:
    virtual void privateCopyFrom(FlprogEventLogAbstractField *field) { setLongValue(field->longValue()); };
};
