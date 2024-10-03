#include "flprogEepromEventLogRecord.h"

void FlprogEepromEventLogRecord::setFieldSize(uint8_t fieldsSize)
{
    _fieldsSize = fieldsSize;
    _fields = new FlprogEepromEventLogAbstractField[_fieldsSize];
}

void FlprogEepromEventLogRecord::setTimeField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = FlprogEepromEventLogTimeField();
}

void FlprogEepromEventLogRecord::setByteField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = FlprogEepromEventLogByteValueField();
}

void FlprogEepromEventLogRecord::setIntegerField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = FlprogEepromEventLogIntValueField();
}

void FlprogEepromEventLogRecord::setBooleanField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = FlprogEepromEventLogBooleanValueField();
}

void FlprogEepromEventLogRecord::setLongField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = FlprogEepromEventLogLongValueField();
}

void FlprogEepromEventLogRecord::setUnLongField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = FlprogEepromEventLogUnLongteValueField();
}

FlprogEventLogAbstractField *FlprogEepromEventLogRecord::getField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return 0;
    }
    return &_fields[index];
}
