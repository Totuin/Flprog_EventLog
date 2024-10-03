#include "flprogEventLog.h"

FlprogEventLog::FlprogEventLog(uint16_t eventsSize, uint16_t recordsSize, uint8_t fieldsSize)
{
    _eventsSize = eventsSize;
    _recordsSize = recordsSize;
    _events = new FlprogEventLogEvent[_eventsSize];
    _records = new FlprogEventLogRecord[_recordsSize];
    _fieldsSize = fieldsSize;
    for (uint16_t i = 0; i < _recordsSize; i++)
    {
        _records[i].setFielSize(_fieldsSize);
    }
}

void FlprogEventLog::setTimeField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    for (uint16_t i = 0; i < _recordsSize; i++)
    {
        _records[i].setTimeField(index);
    }
}

void FlprogEventLog::setByteField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    for (uint16_t i = 0; i < _recordsSize; i++)
    {
        _records[i].setByteField(index);
    }
}

void FlprogEventLog::setIntegerField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    for (uint16_t i = 0; i < _recordsSize; i++)
    {
        _records[i].setIntegerField(index);
    }
}

void FlprogEventLog::setBooleanField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    for (uint16_t i = 0; i < _recordsSize; i++)
    {
        _records[i].setBooleanField(index);
    }
}

void FlprogEventLog::setLongField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    for (uint16_t i = 0; i < _recordsSize; i++)
    {
        _records[i].setLongField(index);
    }
}

void FlprogEventLog::setUnLongField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    for (uint16_t i = 0; i < _recordsSize; i++)
    {
        _records[i].setUnLongField(index);
    }
}

void FlprogEventLog::setEventDescription(uint16_t index, String description)
{

    if (index >= _eventsSize)
    {
        return;
    }
    _events[index].setDescription(description);
}

FlprogEventLogRecord *FlprogEventLog::addNewEvent(uint16_t index)
{
    if (index >= _eventsSize)
    {
        return 0;
    }
    for (int32_t i = (_recordsSize - 2); i >= 0; i--)
    {
        _records[i + 1].copyFrom(&_records[i]);
    }
    _records[0].setEvent(index);
    return &_records[0];
}

void FlprogEventLog::setBooleanValue(uint16_t index, uint8_t fieldIndex, bool value)
{
    if (index >= _recordsSize)
    {
        return;
    }
    _records[index].setBooleanValue(fieldIndex, value);
}

void FlprogEventLog::setByteValue(uint16_t index, uint8_t fieldIndex, uint8_t value)
{
    if (index >= _recordsSize)
    {
        return;
    }
    _records[index].setByteValue(fieldIndex, value);
}

void FlprogEventLog::setIntValue(uint16_t index, uint8_t fieldIndex, int16_t value)
{
    if (index >= _recordsSize)
    {
        return;
    }
    _records[index].setIntValue(fieldIndex, value);
}

void FlprogEventLog::setLongValue(uint16_t index, uint8_t fieldIndex, int32_t value)
{
    if (index >= _recordsSize)
    {
        return;
    }
    _records[index].setLongValue(fieldIndex, value);
}

void FlprogEventLog::setUnLongValue(uint16_t index, uint8_t fieldIndex, uint32_t value)
{
    if (index >= _recordsSize)
    {
        return;
    }
    _records[index].setUnLongValue(fieldIndex, value);
}

FlprogEventLogRecord *FlprogEventLog::getRecord(uint16_t index)
{
    if (index >= _recordsSize)
    {
        return 0;
    }
    return &_records[index];
}

FlprogEventLogAbstractField *FlprogEventLog::getField(uint16_t index, uint8_t fieldIndex)
{
    if (index >= _recordsSize)
    {
        return 0;
    }
    return _records[index].getField(fieldIndex);
}

FlprogEventLogEvent *FlprogEventLog::getEvent(uint16_t index)
{
    if (index >= _eventsSize)
    {
        return 0;
    }
    return &_events[index];
}

bool FlprogEventLog::getBooleanValue(uint16_t index, uint8_t fieldIndex)
{
    if (index >= _recordsSize)
    {
        return false;
    }
    return _records[index].getBooleanValue(fieldIndex);
}

uint8_t FlprogEventLog::getByteValue(uint16_t index, uint8_t fieldIndex)
{
    if (index >= _recordsSize)
    {
        return 0;
    }
    return _records[index].getByteValue(fieldIndex);
}

int16_t FlprogEventLog::getIntValue(uint16_t index, uint8_t fieldIndex)
{
    if (index >= _recordsSize)
    {
        return 0;
    }
    return _records[index].getIntValue(fieldIndex);
}

int32_t FlprogEventLog::getLongValue(uint16_t index, uint8_t fieldIndex)
{
    if (index >= _recordsSize)
    {
        return 0;
    }
    return _records[index].getLongValue(fieldIndex);
}

uint32_t FlprogEventLog::getUnLongValue(uint16_t index, uint8_t fieldIndex)
{
    if (index >= _recordsSize)
    {
        return 0;
    }
    return _records[index].getUnLongValue(fieldIndex);
}
