#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEepromEventLogAbstractField.h"

class FlprogEepromEventLogIntValueField : public FlprogEepromEventLogAbstractField
{
public:
    virtual int16_t intValue();
    virtual uint8_t eepromSize() { return 2; };
    virtual void setIntValue(int16_t value);

protected:
 
};
