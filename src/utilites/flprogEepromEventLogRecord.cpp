#include "flprogEepromEventLogRecord.h"

void FlprogEepromEventLogRecord::setFieldSize(uint8_t fieldsSize)
{
    _fieldsSize = fieldsSize;
    if (fieldsSize != 0)
    {
        _fields = new FlprogEepromEventLogAbstractField *[_fieldsSize];
    }
}

void FlprogEepromEventLogRecord::setTimeField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = new FlprogEepromEventLogTimeField();
}

void FlprogEepromEventLogRecord::setByteField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = new FlprogEepromEventLogByteValueField();
}

void FlprogEepromEventLogRecord::setIntegerField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = new FlprogEepromEventLogIntValueField();
}

void FlprogEepromEventLogRecord::setBooleanField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = new FlprogEepromEventLogBooleanValueField();
}

void FlprogEepromEventLogRecord::setLongField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = new FlprogEepromEventLogLongValueField();
}

void FlprogEepromEventLogRecord::setUnLongField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = new FlprogEepromEventLogUnLongValueField();
}

FlprogEventLogAbstractField *FlprogEepromEventLogRecord::getField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return 0;
    }
    return _fields[index];
}

bool FlprogEepromEventLogRecord::isBoolField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return false;
    }
    return _fields[index]->isBoolField();
}

void FlprogEepromEventLogRecord::setEeprom(uint8_t index, FLProgAbstractEEPROM *chip, uint16_t address, uint8_t bit)
{
    _chip = chip;
    if (index >= _fieldsSize)
    {
        return;
    }
    return _fields[index]->setEeprom(_chip, address, bit);
}

uint8_t FlprogEepromEventLogRecord::eepromSize(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return 0;
    }
    return _fields[index]->eepromSize();
}

void FlprogEepromEventLogRecord::setEvent(uint8_t index)
{
    if (_chip != 0)
    {
        _chip->saveByte(_eventIndexAddress, index);
    }
}

void FlprogEepromEventLogRecord::setWeight(uint16_t value)
{
    if (_chip != 0)
    {
        _chip->saveInteger(_weightAddress, value);
    }
}

uint8_t FlprogEepromEventLogRecord::event()
{
    if (_chip == 0)
    {
        return 0;
    }
    else
    {
        return _chip->readByte(_eventIndexAddress);
    }
}

uint16_t FlprogEepromEventLogRecord::getWeight()
{
    if (_chip == 0)
    {
        return 0;
    }
    else
    {
        return _chip->readInteger(_weightAddress);
    }
}

void FlprogEepromEventLogRecord::setWeightAddress(FLProgAbstractEEPROM *chip, uint16_t address)
{
    _chip = chip;
    _weightAddress = address;
    setWeight(0);
}

void FlprogEepromEventLogRecord::setEventIndexAddress(FLProgAbstractEEPROM *chip, uint16_t address)
{
    _chip = chip;
    _eventIndexAddress = address;
}