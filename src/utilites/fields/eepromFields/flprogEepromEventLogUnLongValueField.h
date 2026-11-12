#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEepromEventLogAbstractField.h"

// EEPROM-поле uint32_t: 4 байта.
class FlprogEepromEventLogUnLongValueField : public FlprogEepromEventLogAbstractField
{
public:
    virtual uint32_t unLongValue() override;
    virtual void setUnLongValue(uint32_t value) override;
    virtual uint8_t eepromSize() override { return 4; };

protected:
};
