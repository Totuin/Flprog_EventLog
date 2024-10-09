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