#include "flprogEventLogRecord.h"


void FlprogEventLogRecord::setFieldSize(uint8_t fieldsSize)
{
    _fieldsSize = fieldsSize;
    if (fieldsSize != 0)
    {
        _fields = new FlprogEventLogAbstractField *[_fieldsSize];
    }
}

void FlprogEventLogRecord::setTimeField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = new FlprogEventLogTimeField();
}

void FlprogEventLogRecord::setByteField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = new FlprogEventLogByteValueField();
}

void FlprogEventLogRecord::setIntegerField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = new FlprogEventLogIntValueField();
}

void FlprogEventLogRecord::setBooleanField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = new FlprogEventLogBooleanValueField();
}

void FlprogEventLogRecord::setLongField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = new FlprogEventLogIntValueField();
}

void FlprogEventLogRecord::setUnLongField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    _fields[index] = new FlprogEventLogUnLongteValueField();
}

FlprogEventLogAbstractField *FlprogEventLogRecord::getField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return 0;
    }
    return _fields[index];
}
