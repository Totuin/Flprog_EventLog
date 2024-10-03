#include "flprogEventLogRecord.h"

void FlprogEventLogRecord::setFielSize(uint8_t fieldsSize)
{
    _fieldsSize = fieldsSize;
    _fields = new FlprogEventLogAbstractField[_fieldsSize];
}

void FlprogEventLogRecord::setTimeField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = FlprogEventLogTimeField();
}

void FlprogEventLogRecord::setByteField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = FlprogEventLogByteValueField();
}

void FlprogEventLogRecord::setIntegerField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = FlprogEventLogIntValueField();
}

void FlprogEventLogRecord::setBooleanField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = FlprogEventLogBooleanValueField();
}

void FlprogEventLogRecord::setLongField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = FlprogEventLogIntValueField();
}

void FlprogEventLogRecord::setUnLongField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = FlprogEventLogUnLongteValueField();
}

void FlprogEventLogRecord::setEvent(uint16_t index)
{
    _hasEvent = true;
    _eventIndex = index;
}

void FlprogEventLogRecord::copyFrom(FlprogEventLogRecord *record)
{
    _hasEvent = record->hasEvent();
    _eventIndex = record->event();
    for (uint8_t i = 0; i < _fieldsSize; i++)
    {
        FlprogEventLogAbstractField *field = record->getField(i);
        if (field != 0)
        {
            _fields[i].copyFrom(field);
        }
    }
}

FlprogEventLogAbstractField *FlprogEventLogRecord::getField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return 0;
    }
    return &_fields[index];
}

void FlprogEventLogRecord::setBooleanValue(uint8_t index, bool value)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index].setBooleanValue(value);
}

void FlprogEventLogRecord::setByteValue(uint8_t index, uint8_t value)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index].setByteValue(value);
}

void FlprogEventLogRecord::setIntValue(uint8_t index, int16_t value)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index].setIntValue(value);
}

void FlprogEventLogRecord::setLongValue(uint8_t index, int32_t value)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index].setLongValue(value);
}

void FlprogEventLogRecord::setUnLongValue(uint8_t index, uint32_t value)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index].setUnLongValue(value);
}

bool FlprogEventLogRecord::getBooleanValue(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return false;
    }
    return _fields[index].booleanValue();
}

uint8_t FlprogEventLogRecord::getByteValue(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return 0;
    }
    return _fields[index].byteValue();
}

int16_t FlprogEventLogRecord::getIntValue(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return 0;
    }
    return _fields[index].intValue();
}

int32_t FlprogEventLogRecord::getLongValue(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return 0;
    }
    return _fields[index].longValue();
}

uint32_t FlprogEventLogRecord::getUnLongValue(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return 0;
    }
    return _fields[index].unLongValue();
}
