#include "flprogEventLogAbstractRecord.h"

void FlprogEventLogAbstractRecord::setEvent(uint16_t index)
{
    _hasEvent = true;
    _eventIndex = index;
}

void FlprogEventLogAbstractRecord::setBooleanValue(uint8_t index, bool value)
{
    FlprogEventLogAbstractField *field = getField(index);
    if (field == 0)
    {
        return;
    }
    field->setBooleanValue(value);
}

void FlprogEventLogAbstractRecord::setByteValue(uint8_t index, uint8_t value)
{
    FlprogEventLogAbstractField *field = getField(index);
    if (field == 0)
    {
        return;
    }
    field->setByteValue(value);
}

void FlprogEventLogAbstractRecord::setIntValue(uint8_t index, int16_t value)
{
    FlprogEventLogAbstractField *field = getField(index);
    if (field == 0)
    {
        return;
    }
    field->setIntValue(value);
}

void FlprogEventLogAbstractRecord::setLongValue(uint8_t index, int32_t value)
{
    FlprogEventLogAbstractField *field = getField(index);
    if (field == 0)
    {
        return;
    }
    field->setLongValue(value);
}

void FlprogEventLogAbstractRecord::setUnLongValue(uint8_t index, uint32_t value)
{
    FlprogEventLogAbstractField *field = getField(index);
    if (field == 0)
    {
        return;
    }
    field->setUnLongValue(value);
}

bool FlprogEventLogAbstractRecord::getBooleanValue(uint8_t index)
{
    FlprogEventLogAbstractField *field = getField(index);
    if (field == 0)
    {
        return false;
    }
    return field->booleanValue();
}

uint8_t FlprogEventLogAbstractRecord::getByteValue(uint8_t index)
{
    FlprogEventLogAbstractField *field = getField(index);
     if (field == 0)
    {
        return 0;
    }
    return field->byteValue();
}

int16_t FlprogEventLogAbstractRecord::getIntValue(uint8_t index)
{
    FlprogEventLogAbstractField *field = getField(index);
    if (field == 0)
    {
        return 0;
    }
    return field->intValue();
}

int32_t FlprogEventLogAbstractRecord::getLongValue(uint8_t index)
{
    FlprogEventLogAbstractField *field = getField(index);
    if (field == 0)
    {
        return 0;
    }
    return field->longValue();
}

uint32_t FlprogEventLogAbstractRecord::getUnLongValue(uint8_t index)
{
    FlprogEventLogAbstractField *field = getField(index);
    if (field == 0)
    {
        return 0;
    }
    return field->unLongValue();
}

void FlprogEventLogAbstractRecord::copyFrom(FlprogEventLogAbstractRecord *record)
{
    _hasEvent = record->hasEvent();
    _eventIndex = record->event();
    for (uint8_t i = 0; i < _fieldsSize; i++)
    {
        FlprogEventLogAbstractField *field = record->getField(i);
        FlprogEventLogAbstractField *target = getField(i);
        if (field != 0)
        {
            if (target != 0)
            {

                target->copyFrom(field);
            }
        }
    }
}