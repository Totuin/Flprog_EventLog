#include "flprogEepromEventLogLongValueField.h"

int32_t FlprogEepromEventLogLongValueField::longValue()
{
    if (_chip == 0)
    {
        return false;
    }
    return _chip->readLong(_addres);
}

void FlprogEepromEventLogLongValueField::setLongValue(int32_t value)
{
    if (_chip == 0)
    {
        return;
    }
    _chip->saveLong(_addres, value);
}