#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEepromEventLogAbstractField.h"

class FlprogEepromEventLogUnLongValueField : public FlprogEepromEventLogAbstractField
{
public:
    virtual uint32_t unLongValue();
    virtual void setUnLongValue(uint32_t value);
    virtual uint8_t eepromSize() { return 4; };

protected:
};
