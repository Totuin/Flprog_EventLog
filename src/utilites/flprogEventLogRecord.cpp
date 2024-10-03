#include "flprogEventLogRecord.h"

void FlprogEventLogRecord::setFieldSize(uint8_t fieldsSize)
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

FlprogEventLogAbstractField *FlprogEventLogRecord::getField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return 0;
    }
    return &_fields[index];
}

