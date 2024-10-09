#include "flprogEventLog.h"

FlprogEventLog::FlprogEventLog(uint16_t eventsSize, uint16_t recordsSize, uint8_t fieldsSize)
{
    _eventsSize = eventsSize;
    _recordsSize = recordsSize;
    _events = new FlprogEventLogEvent[_eventsSize];
    _records = new FlprogEventLogRecord[_recordsSize];
    _virtualIndexes = new uint16_t[_recordsSize];
    _fieldsSize = fieldsSize;
    for (uint16_t i = 0; i < _recordsSize; i++)
    {
        _records[i].setFieldSize(_fieldsSize);
        _virtualIndexes[i] = i;
    }
}

FlprogEventLogAbstractRecord *FlprogEventLog::getRecord(uint16_t index)
{
    if (index >= _recordsSize)
    {
        return 0;
    }
    return &_records[index];
}