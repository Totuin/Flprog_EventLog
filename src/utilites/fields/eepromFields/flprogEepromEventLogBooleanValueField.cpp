#include "flprogEepromEventLogBooleanValueField.h"

void FlprogEepromEventLogBooleanValueField::setEeprom(FLProgAbstractEEPROM *chip, uint16_t address, uint8_t bit)
{
    _bit = bit;
    _addres = address;
    _chip = chip;
}

bool FlprogEepromEventLogBooleanValueField::booleanValue()
{
    if (_chip == 0)
    {
        return false;
    }
    return _chip->readBoolean(_addres, _bit);
}

void FlprogEepromEventLogBooleanValueField::setBooleanValue(bool value)
{
    if (_chip == 0)
    {
        return;
    }
    _chip->saveBoolean(_addres, _bit, value);
}