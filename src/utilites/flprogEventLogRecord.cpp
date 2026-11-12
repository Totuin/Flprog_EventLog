#include "flprogEventLogRecord.h"


// Освобождаем поля, которыми владеет запись: в том числе при повторной настройке.
FlprogEventLogRecord::~FlprogEventLogRecord()
{
    for (uint8_t i = 0; i < _fieldsSize; ++i) delete _fields[i];
    delete[] _fields;
}

void FlprogEventLogRecord::setFieldSize(uint8_t fieldsSize)
{
    // Пустые позиции должны быть nullptr: тип поля может быть не задан.
    for (uint8_t i = 0; i < _fieldsSize; ++i) delete _fields[i];
    delete[] _fields;
    _fieldsSize = fieldsSize;
    _fields = fieldsSize ? new FlprogEventLogAbstractField *[fieldsSize]() : nullptr;
}

void FlprogEventLogRecord::setTimeField(uint8_t index)
{
    if (index >= _fieldsSize || _fields == nullptr)
    {
        return;
    }
    delete _fields[index];
    _fields[index] = new FlprogEventLogTimeField();
}

void FlprogEventLogRecord::setByteField(uint8_t index)
{
    if (index >= _fieldsSize || _fields == nullptr)
    {
        return;
    }
    delete _fields[index];
    _fields[index] = new FlprogEventLogByteValueField();
}

void FlprogEventLogRecord::setIntegerField(uint8_t index)
{
    if (index >= _fieldsSize || _fields == nullptr)
    {
        return;
    }
    delete _fields[index];
    _fields[index] = new FlprogEventLogIntValueField();
}

void FlprogEventLogRecord::setBooleanField(uint8_t index)
{
    if (index >= _fieldsSize || _fields == nullptr)
    {
        return;
    }
    delete _fields[index];
    _fields[index] = new FlprogEventLogBooleanValueField();
}

void FlprogEventLogRecord::setLongField(uint8_t index)
{
    if (index >= _fieldsSize || _fields == nullptr)
    {
        return;
    }
    delete _fields[index];
    _fields[index] = new FlprogEventLogLongValueField();
}

void FlprogEventLogRecord::setUnLongField(uint8_t index)
{
    if (index >= _fieldsSize || _fields == nullptr)
    {
        return;
    }
    delete _fields[index];
    _fields[index] = new FlprogEventLogUnLongteValueField();
}

FlprogEventLogAbstractField *FlprogEventLogRecord::getField(uint8_t index)
{
    if (index >= _fieldsSize || _fields == nullptr)
    {
        return 0;
    }
    return _fields[index];
}
