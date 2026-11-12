#include "flprogEepromEventLog.h"

FlprogEepromEventLog::FlprogEepromEventLog(uint16_t eventsSize, uint16_t recordsSize, uint8_t fieldsSize)
{
    _eventsSize = eventsSize;
    _recordsSize = recordsSize;
    _events = new FlprogEventLogEvent[_eventsSize];
    _records = new FlprogEepromEventLogRecord[_recordsSize];
    _virtualIndexes = new uint16_t[_recordsSize];
    _fieldsSize = fieldsSize;
    for (uint16_t i = 0; i < _recordsSize; i++)
    {
        _records[i].setFieldSize(_fieldsSize);
        _virtualIndexes[i] = i;
    }
}

// Удаление объектов полей выполняется деструкторами записей.
FlprogEepromEventLog::~FlprogEepromEventLog()
{
    delete[] _records;
}

FlprogEventLogAbstractRecord *FlprogEepromEventLog::getRecord(uint16_t index)
{
    if (index >= _recordsSize)
    {
        return 0;
    }
    return &_records[index];
}

uint16_t FlprogEepromEventLog::setEEprom(FLProgAbstractEEPROM *chip, uint16_t addres)
{
    // Предварительно считаем размер схемы, не привязывая ни одного поля:
    // при переполнении адресов не допускаем частичную конфигурацию.
    if (chip == nullptr || addres == 0) return 0;
    uint32_t bits = 0;
    uint32_t otherBytes = 0;
    for (uint16_t i = 0; i < _recordsSize; ++i)
    {
        for (uint16_t f = 0; f < _fieldsSize; ++f)
        {
            if (_records[i].isBoolField(static_cast<uint8_t>(f))) ++bits;
            else otherBytes += _records[i].eepromSize(static_cast<uint8_t>(f));
        }
    }
    const uint32_t endAddress = static_cast<uint32_t>(addres) +
        ((bits + 7u) / 8u) + static_cast<uint32_t>(_recordsSize) * 3u + otherBytes;
    // Возвращаемый адрес — EXCLUSIVE; 65536 в uint16_t не помещается.
    if (endAddress > 65535u) return 0;

    uint16_t startAddres = addres;
    uint8_t startBit = 0;
    for (uint16_t i = 0; i < _recordsSize; i++)
    {
        for (uint8_t f = 0; f < _fieldsSize; f++)
        {
            if (_records[i].isBoolField(f))
            {
                _records[i].setEeprom(f, chip, startAddres, startBit);
                startBit++;
                if (startBit > 7)
                {
                    startBit = 0;
                    startAddres++;
                }
            }
        }
    }
    if (startBit > 0)
    {
        startAddres++;
    }
    for (uint16_t i = 0; i < _recordsSize; i++)
    {
        _records[i].setEventIndexAddress(chip, startAddres);
        startAddres++;
        _records[i].setWeightAddress(chip, startAddres);
        startAddres = startAddres + 2;
        for (uint8_t f = 0; f < _fieldsSize; f++)
        {
            if (!_records[i].isBoolField(f))
            {
                _records[i].setEeprom(f, chip, startAddres);
                startAddres = startAddres + (_records[i].eepromSize(f));
            }
        }
    }
    return startAddres;
}