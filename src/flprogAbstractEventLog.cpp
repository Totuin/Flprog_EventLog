#include "flprogAbstractEventLog.h"

FlprogAbstractEventLog::~FlprogAbstractEventLog()
{
    delete[] _events;
    delete[] _virtualIndexes;
}


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
    // Номер события сохраняется в одном байте в обоих типах журнала.
    if (index >= _eventsSize || index > 255 || _recordsSize == 0)
    {
        return 0;
    }
    FlprogEventLogAbstractRecord *record = getRecordWithVirtualIndex(_recordsSize - 1);
    if (record == 0)
    {
        return 0;
    }
    uint16_t maxWeight = getMaxWeight();
    // Экстремальный случай: все 65535 слотов заняты. Освобождаем старейший
    // до перенумерации, иначе новый вес не представим в uint16_t.
    if (maxWeight == 65535)
    {
        record->setWeight(0);
        _isSorted = false;
        sortVirtualIndexes();
        resetWeight();
        maxWeight = getMaxWeight();
    }
    record->setEvent(static_cast<uint8_t>(index));
    record->setWeight(maxWeight + 1);
    _isSorted = false;
    return record;
}

FlprogEventLogAbstractRecord *FlprogAbstractEventLog::getRecordWithVirtualIndex(uint16_t index)
{
    if (index >= _recordsSize || _virtualIndexes == nullptr)
    {
        return 0;
    }
    if (!_isSorted)
    {
        sortVirtualIndexes();
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

// Сортировка по убыванию веса: индекс 0 — самая новая запись,
// последний индекс — самая старая, которую вытеснит следующее событие.
void FlprogAbstractEventLog::sortVirtualIndexes()
{
    if (_virtualIndexes == nullptr || _recordsSize == 0)
    {
        _isSorted = true;
        return;
    }
    // Восстанавливаем физический порядок перед сортировкой: удалённые записи
    // с весом 0 в конце списка не должны мешать новым событиям.
    for (uint16_t i = 0; i < _recordsSize; ++i) _virtualIndexes[i] = i;
    // Insertion sort хорошо работает с короткими кольцевыми журналами.
    for (uint32_t i = 1; i < _recordsSize; ++i)
    {
        uint16_t key = _virtualIndexes[i];
        FlprogEventLogAbstractRecord *entry = getRecord(key);
        const uint16_t weight = entry ? entry->getWeight() : 0;
        uint32_t j = i;
        while (j > 0)
        {
            FlprogEventLogAbstractRecord *prev = getRecord(_virtualIndexes[j - 1]);
            if (prev != nullptr && prev->getWeight() >= weight) break;
            _virtualIndexes[j] = _virtualIndexes[j - 1];
            --j;
        }
        _virtualIndexes[j] = key;
    }
    _isSorted = true;
    checkWeight();
}

void FlprogAbstractEventLog::checkWeight()
{
    if (_recordsSize == 0 || _virtualIndexes == nullptr) return;
    FlprogEventLogAbstractRecord *record = getRecord(_virtualIndexes[0]);
    if (record != nullptr && record->getWeight() >= 65000) resetWeight();
}

void FlprogAbstractEventLog::resetRecord(uint16_t index)
{
    FlprogEventLogAbstractRecord *record = getRecordWithVirtualIndex(index);
    if (record != nullptr)
    {
        record->setWeight(0);
        _isSorted = false;
    }
}

void FlprogAbstractEventLog::clearEventLog()
{
    for (uint16_t i = 0; i < _recordsSize; ++i)
    {
        FlprogEventLogAbstractRecord *record = getRecord(i);
        if (record != nullptr) record->setWeight(0);
    }
    _isSorted = false;
}

void FlprogAbstractEventLog::resetWeight()
{
    // Перенумерация от старейшего события к новейшему. Нулевой вес
    // означает свободный слот и сохраняется. Без переполнения индексов.
    if (_virtualIndexes == nullptr) return;
    uint16_t weight = 0;
    for (uint32_t i = _recordsSize; i > 0; --i)
    {
        FlprogEventLogAbstractRecord *record = getRecord(_virtualIndexes[i - 1]);
        if (record != nullptr && record->getWeight() != 0)
        {
            record->setWeight(++weight);
        }
    }
    _isSorted = false;
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
        FlprogEventLogAbstractRecord *record = getRecordWithVirtualIndex(i);
        if (record != nullptr && record->hasEvent())
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