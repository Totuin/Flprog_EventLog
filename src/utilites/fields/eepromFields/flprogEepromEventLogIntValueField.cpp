#include "flprogEepromEventLogIntValueField.h"

int16_t FlprogEepromEventLogIntValueField::intValue()
{
    if (_chip == 0)
    {
        return false;
    }
    return _chip->readInteger(_addres);
}

void FlprogEepromEventLogIntValueField::setIntValue(int16_t value)
{
    if (_chip == 0)
    {
        return;
    }
    _chip->saveInteger(_addres, value);
}