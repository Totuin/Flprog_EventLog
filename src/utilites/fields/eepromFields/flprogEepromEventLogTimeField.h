#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEepromEventLogUnLongValueField.h"

// Время в EEPROM: uint32_t, те же 4 байта.
class FlprogEepromEventLogTimeField : public FlprogEepromEventLogUnLongValueField
{

public:
protected:
};
