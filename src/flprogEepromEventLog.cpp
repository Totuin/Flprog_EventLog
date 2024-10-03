#include "flprogEepromEventLog.h"

FlprogEepromEventLog::FlprogEepromEventLog(uint16_t eventsSize, uint16_t recordsSize, uint8_t fieldsSize)
{
    _eventsSize = eventsSize;
    _recordsSize = recordsSize;
    _events = new FlprogEventLogEvent[_eventsSize];
    _records = new FlprogEepromEventLogRecord[_recordsSize];
    _fieldsSize = fieldsSize;
    for (uint16_t i = 0; i < _recordsSize; i++)
    {
        _records[i].setFieldSize(_fieldsSize);
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