#include "flprogEepromEventLogByteValueField.h"

uint8_t FlprogEepromEventLogByteValueField::byteValue()
{
    if (_chip == 0)
    {
        return false;
    }
    return _chip->readByte(_addres);
}

void FlprogEepromEventLogByteValueField::setByteValue(uint8_t value)
{
    if (_chip == 0)
    {
        return;
    }
    _chip->saveByte(_addres, value);
}