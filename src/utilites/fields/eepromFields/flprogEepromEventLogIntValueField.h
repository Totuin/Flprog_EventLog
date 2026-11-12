#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEepromEventLogAbstractField.h"

// EEPROM-поле int16_t: 2 байта, порядок наследуется от FLProgAbstractEEPROM.
class FlprogEepromEventLogIntValueField : public FlprogEepromEventLogAbstractField
{
public:
    virtual int16_t intValue() override;
    virtual uint8_t eepromSize() override { return 2; };
    virtual void setIntValue(int16_t value) override;

protected:
 
};
