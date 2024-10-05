#include "flprogEepromEventLogAbstractField.h"

void FlprogEepromEventLogAbstractField::setEeprom(FLProgAbstractEEPROM *chip, uint16_t address, uint8_t bit)
{
    (void)bit;
    _chip = chip;
    _addres = address;
}