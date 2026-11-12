#include "flprogEepromEventLogUnLongValueField.h"

uint32_t FlprogEepromEventLogUnLongValueField::unLongValue()
{
    if (_chip == 0)
    {
        return false;
    }
    return _chip->readUnsignedLong(_addres);
}

void FlprogEepromEventLogUnLongValueField::setUnLongValue(uint32_t value)
{
    if (_chip == 0)
    {
        return;
    }
    _chip->saveUnsignedLong(_addres, value);
}
