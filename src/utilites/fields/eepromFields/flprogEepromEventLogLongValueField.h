#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEepromEventLogAbstractField.h"

// EEPROM-поле int32_t: 4 байта.
class FlprogEepromEventLogLongValueField : public FlprogEepromEventLogAbstractField
{

public:
    virtual int32_t longValue() override;
    virtual uint8_t eepromSize() override { return 4; };
    virtual void setLongValue(int32_t value) override;

protected:
};
