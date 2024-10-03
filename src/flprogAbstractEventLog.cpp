#include "flprogAbstractEventLog.h"

void FlprogAbstractEventLog::setTimeField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    for (uint16_t i = 0; i < _recordsSize; i++)
    {
        FlprogEventLogAbstractRecord *record = getRecord(i);
        if (record != 0)
        {
            record->setTimeField(index);
        }
    }
}

void FlprogAbstractEventLog::setByteField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    for (uint16_t i = 0; i < _recordsSize; i++)
    {
        FlprogEventLogAbstractRecord *record = getRecord(i);
        if (record != 0)
        {
            record->setByteField(index);
        }
    }
}

void FlprogAbstractEventLog::setIntegerField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    for (uint16_t i = 0; i < _recordsSize; i++)
    {
        FlprogEventLogAbstractRecord *record = getRecord(i);
        if (record != 0)
        {
            record->setIntegerField(index);
        }
    }
}

void FlprogAbstractEventLog::setBooleanField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    for (uint16_t i = 0; i < _recordsSize; i++)
    {
        FlprogEventLogAbstractRecord *record = getRecord(i);
        if (record != 0)
        {
            record->setBooleanField(index);
        }
    }
}

void FlprogAbstractEventLog::setLongField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    for (uint16_t i = 0; i < _recordsSize; i++)
    {
        FlprogEventLogAbstractRecord *record = getRecord(i);
        if (record != 0)
        {
            record->setLongField(index);
        }
    }
}

void FlprogAbstractEventLog::setUnLongField(uint8_t index)
{
    if (index >= _fieldsSize)
    {
        return;
    }
    for (uint16_t i = 0; i < _recordsSize; i++)
    {
        FlprogEventLogAbstractRecord *record = getRecord(i);
        if (record != 0)
        {
            record->setUnLongField(index);
        }
    }
}

void FlprogAbstractEventLog::setEventDescription(uint16_t index, String description)
{

    if (index >= _eventsSize)
    {
        return;
    }
    _events[index].setDescription(description);
}

FlprogEventLogAbstractRecord *FlprogAbstractEventLog::addNewEvent(uint16_t index)
{
    if (index >= _eventsSize)
    {
        return 0;
    }
    FlprogEventLogAbstractRecord *target;
    for (int32_t i = (_recordsSize - 2); i >= 0; i--)
    {
        FlprogEventLogAbstractRecord *sourse = getRecord(i);
        target = getRecord(i + 1);
        if (sourse != 0)
        {
            if (target != 0)
            {

                target->copyFrom(sourse);
            }
        }
    }
    target = getRecord(0);
    target->setEvent(index);
    return target;
}

void FlprogAbstractEventLog::setBooleanValue(uint16_t index, uint8_t fieldIndex, bool value)
{
    FlprogEventLogAbstractRecord *record = getRecord(index);
    if (record == 0)
    {
        return;
    }
    record->setBooleanValue(fieldIndex, value);
}

void FlprogAbstractEventLog::setByteValue(uint16_t index, uint8_t fieldIndex, uint8_t value)
{
    FlprogEventLogAbstractRecord *record = getRecord(index);
    if (record == 0)
    {
        return;
    }
    record->setByteValue(fieldIndex, value);
}

void FlprogAbstractEventLog::setIntValue(uint16_t index, uint8_t fieldIndex, int16_t value)
{
    FlprogEventLogAbstractRecord *record = getRecord(index);
    if (record == 0)
    {
        return;
    }
    record->setIntValue(fieldIndex, value);
}

void FlprogAbstractEventLog::setLongValue(uint16_t index, uint8_t fieldIndex, int32_t value)
{
    FlprogEventLogAbstractRecord *record = getRecord(index);
    if (record == 0)
    {
        return;
    }
    record->setLongValue(fieldIndex, value);
}

void FlprogAbstractEventLog::setUnLongValue(uint16_t index, uint8_t fieldIndex, uint32_t value)
{
    FlprogEventLogAbstractRecord *record = getRecord(index);
    if (record == 0)
    {
        return;
    }
    record->setUnLongValue(fieldIndex, value);
}

FlprogEventLogAbstractField *FlprogAbstractEventLog::getField(uint16_t index, uint8_t fieldIndex)
{
    FlprogEventLogAbstractRecord *record = getRecord(index);
    if (record == 0)
    {
        return 0;
    }
    return record->getField(fieldIndex);
}

FlprogEventLogEvent *FlprogAbstractEventLog::getEvent(uint16_t index)
{
    if (index >= _eventsSize)
    {
        return 0;
    }
    return &_events[index];
}

bool FlprogAbstractEventLog::getBooleanValue(uint16_t index, uint8_t fieldIndex)
{
    FlprogEventLogAbstractRecord *record = getRecord(index);
    if (record == 0)
    {
        return false;
    }
    return record->getBooleanValue(fieldIndex);
}

uint8_t FlprogAbstractEventLog::getByteValue(uint16_t index, uint8_t fieldIndex)
{
    FlprogEventLogAbstractRecord *record = getRecord(index);
    if (record == 0)
    {
        return 0;
    }
    return record->getByteValue(fieldIndex);
}

int16_t FlprogAbstractEventLog::getIntValue(uint16_t index, uint8_t fieldIndex)
{
    FlprogEventLogAbstractRecord *record = getRecord(index);
    if (record == 0)
    {
        return 0;
    }
    return record->getIntValue(fieldIndex);
}

int32_t FlprogAbstractEventLog::getLongValue(uint16_t index, uint8_t fieldIndex)
{
    FlprogEventLogAbstractRecord *record = getRecord(index);
    if (record == 0)
    {
        return 0;
    }
    return record->getLongValue(fieldIndex);
}

uint32_t FlprogAbstractEventLog::getUnLongValue(uint16_t index, uint8_t fieldIndex)
{
    FlprogEventLogAbstractRecord *record = getRecord(index);
    if (record == 0)
    {
        return 0;
    }
    return record->getUnLongValue(fieldIndex);
}
