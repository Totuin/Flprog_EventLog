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

String FlprogAbstractEventLog::getEventDescription(uint16_t index)
{
    if (index >= _eventsSize)
    {
        return "";
    }
    return _events[index].getDescription();
}

FlprogEventLogAbstractRecord *FlprogAbstractEventLog::addNewEvent(uint16_t index)
{
    if (index >= _eventsSize)
    {
        return 0;
    }
    FlprogEventLogAbstractRecord *record = getRecordWithVirtualIndex(_recordsSize - 1);
    if (record == 0)
    {
        return 0;
    }
    uint16_t maxWeight = getMaxWeight();
    record->setEvent(index);
    record->setWeight(maxWeight + 1);
    _isSorted = false;
    return record;
}

FlprogEventLogAbstractRecord *FlprogAbstractEventLog::getRecordWithVirtualIndex(uint16_t index)
{
    if (!_isSorted)
    {
        sortVirtualIndexes();
    }
    if (index >= _recordsSize)
    {
        return 0;
    }
    return getRecord(_virtualIndexes[index]);
}

uint16_t FlprogAbstractEventLog::getMaxWeight()
{
    if (!_isSorted)
    {
        sortVirtualIndexes();
    }
    FlprogEventLogAbstractRecord *record = getRecordWithVirtualIndex(0);
    if (record == 0)
    {
        return 0;
    }
    return record->getWeight();
}

void FlprogAbstractEventLog::sortVirtualIndexes()
{
    uint16_t temp = _recordsSize;
    uint16_t temp1;
    FlprogEventLogAbstractRecord *firstRecord;
    FlprogEventLogAbstractRecord *secondRecord;
    while (temp--)
    {
        bool swapped = false;
        for (int i = 0; i < temp; i++)
        {
            firstRecord = getRecord(_virtualIndexes[i]);
            secondRecord = getRecord(_virtualIndexes[i + 1]);
            if (firstRecord != 0)
            {
                if (secondRecord != 0)
                {
                    if ((firstRecord->getWeight()) < (secondRecord->getWeight()))
                    {
                        temp1 = _virtualIndexes[i];
                        _virtualIndexes[i] = _virtualIndexes[i + 1];
                        _virtualIndexes[i + 1] = temp1;
                        swapped = true;
                    }
                }
            }
        }
        if (swapped == false)
        {
            _isSorted = true;
            checkWeight();
            return;
        }
    }
    checkWeight();
    _isSorted = true;
}

void FlprogAbstractEventLog::checkWeight()
{
    FlprogEventLogAbstractRecord *record = getRecord(_virtualIndexes[0]);
    if (record != 0)
    {
        if ((record->getWeight()) >= 65000)
        {
            resetWeight();
        }
    }
    _isSorted = false;
}

void FlprogAbstractEventLog::resetRecord(uint16_t index)
{
    FlprogEventLogAbstractRecord *record = getRecordWithVirtualIndex(index);
    if (record != 0)
    {
        record->setWeight(0);
    }
}

void FlprogAbstractEventLog::clearEventLog()
{
    FlprogEventLogAbstractRecord *record;
    for (uint16_t i = 0; i < _recordsSize; i++)
    {
        record = getRecord(i);
        if (record != 0)
        {
            record->setWeight(0);
        }
    }
}

void FlprogAbstractEventLog::resetWeight()
{
    uint16_t temp = _recordsSize + 1;
    uint16_t index = 1;
    FlprogEventLogAbstractRecord *record;
    while (temp--)
    {
        record = getRecord(_virtualIndexes[temp - 1]);
        if (record != 0)
        {
            if (record->getWeight() > 0)
            {
                record->setWeight(index);
                index++;
            }
        }
    }
}

void FlprogAbstractEventLog::setBooleanValue(uint16_t index, uint8_t fieldIndex, bool value)
{
    FlprogEventLogAbstractRecord *record = getRecordWithVirtualIndex(index);
    if (record == 0)
    {
        return;
    }
    record->setBooleanValue(fieldIndex, value);
}

void FlprogAbstractEventLog::setByteValue(uint16_t index, uint8_t fieldIndex, uint8_t value)
{
    FlprogEventLogAbstractRecord *record = getRecordWithVirtualIndex(index);
    if (record == 0)
    {
        return;
    }
    record->setByteValue(fieldIndex, value);
}

void FlprogAbstractEventLog::setIntValue(uint16_t index, uint8_t fieldIndex, int16_t value)
{
    FlprogEventLogAbstractRecord *record = getRecordWithVirtualIndex(index);
    if (record == 0)
    {
        return;
    }
    record->setIntValue(fieldIndex, value);
}

void FlprogAbstractEventLog::setLongValue(uint16_t index, uint8_t fieldIndex, int32_t value)
{
    FlprogEventLogAbstractRecord *record = getRecordWithVirtualIndex(index);
    if (record == 0)
    {
        return;
    }
    record->setLongValue(fieldIndex, value);
}

void FlprogAbstractEventLog::setUnLongValue(uint16_t index, uint8_t fieldIndex, uint32_t value)
{
    FlprogEventLogAbstractRecord *record = getRecordWithVirtualIndex(index);
    if (record == 0)
    {
        return;
    }
    record->setUnLongValue(fieldIndex, value);
}

FlprogEventLogAbstractField *FlprogAbstractEventLog::getField(uint16_t index, uint8_t fieldIndex)
{
    FlprogEventLogAbstractRecord *record = getRecordWithVirtualIndex(index);
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
    FlprogEventLogAbstractRecord *record = getRecordWithVirtualIndex(index);
    if (record == 0)
    {
        return false;
    }
    if (!(record->hasEvent()))
    {
        return false;
    }
    return record->getBooleanValue(fieldIndex);
}

uint8_t FlprogAbstractEventLog::getByteValue(uint16_t index, uint8_t fieldIndex)
{
    FlprogEventLogAbstractRecord *record = getRecordWithVirtualIndex(index);
    if (record == 0)
    {
        return 0;
    }
    if (!(record->hasEvent()))
    {
        return 0;
    }
    return record->getByteValue(fieldIndex);
}

int16_t FlprogAbstractEventLog::getIntValue(uint16_t index, uint8_t fieldIndex)
{
    FlprogEventLogAbstractRecord *record = getRecordWithVirtualIndex(index);
    if (record == 0)
    {
        return 0;
    }
    if (!(record->hasEvent()))
    {
        return 0;
    }
    return record->getIntValue(fieldIndex);
}

int32_t FlprogAbstractEventLog::getLongValue(uint16_t index, uint8_t fieldIndex)
{
    FlprogEventLogAbstractRecord *record = getRecordWithVirtualIndex(index);
    if (record == 0)
    {
        return 0;
    }
    if (!(record->hasEvent()))
    {
        return 0;
    }
    return record->getLongValue(fieldIndex);
}

uint32_t FlprogAbstractEventLog::getUnLongValue(uint16_t index, uint8_t fieldIndex)
{
    FlprogEventLogAbstractRecord *record = getRecordWithVirtualIndex(index);
    if (record == 0)
    {
        return 0;
    }
    if (!(record->hasEvent()))
    {
        return 0;
    }
    return record->getUnLongValue(fieldIndex);
}

bool FlprogAbstractEventLog::hasEvent(uint16_t index)
{
    FlprogEventLogAbstractRecord *record = getRecordWithVirtualIndex(index);
    if (record == 0)
    {
        return false;
    }
    return record->hasEvent();
}

uint16_t FlprogAbstractEventLog::event(uint16_t index)
{
    FlprogEventLogAbstractRecord *record = getRecordWithVirtualIndex(index);
    if (record == 0)
    {
        return 0;
    }
    if (!(record->hasEvent()))
    {
        return _eventsSize + 1;
    }
    return record->event();
}

uint16_t FlprogAbstractEventLog::getUsedRecordsSize()
{
    uint16_t result = 0;
    for (uint16_t i = 0; i < _recordsSize; i++)
    {
        if (getRecordWithVirtualIndex(i)->hasEvent())
        {
            result++;
        }
        else
        {
            return result;
        }
    }
    return result;
}