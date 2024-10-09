#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "utilites\flprogEventLogEvent.h"
#include "utilites\flprogEventLogAbstractRecord.h"

class FlprogAbstractEventLog
{
public:
    void setTimeField(uint8_t index);
    void setByteField(uint8_t index);
    void setIntegerField(uint8_t index);
    void setBooleanField(uint8_t index);
    void setLongField(uint8_t index);
    void setUnLongField(uint8_t index);
    void setEventDescription(uint16_t index, String description);

    FlprogEventLogAbstractRecord *addNewEvent(uint16_t index);

    void setBooleanValue(uint16_t index, uint8_t fieldIndex, bool value);
    void setLastBooleanValue(uint8_t fieldIndex, bool value) { setBooleanValue(0, fieldIndex, value); };

    void setByteValue(uint16_t index, uint8_t fieldIndex, uint8_t value);
    void setLastByteValue(uint8_t fieldIndex, uint8_t value) { setByteValue(0, fieldIndex, value); };

    void setIntValue(uint16_t index, uint8_t fieldIndex, int16_t value);
    void setLastIntValue(uint8_t fieldIndex, int16_t value) { setIntValue(0, fieldIndex, value); };

    void setLongValue(uint16_t index, uint8_t fieldIndex, int32_t value);
    void setLastLongValue(uint8_t fieldIndex, int32_t value) { setLongValue(0, fieldIndex, value); };

    void setUnLongValue(uint16_t index, uint8_t fieldIndex, uint32_t value);
    void setLastUnLongValue(uint8_t fieldIndex, uint32_t value) { setUnLongValue(0, fieldIndex, value); };

    void setTimeValue(uint16_t index, uint8_t fieldIndex, uint32_t value) { setUnLongValue(index, fieldIndex, value); };
    void setLastTimeValue(uint8_t fieldIndex, uint32_t value) { setTimeValue(0, fieldIndex, value); };

    FlprogEventLogAbstractField *getField(uint16_t index, uint8_t fieldIndex);
    FlprogEventLogEvent *getEvent(uint16_t index);

    bool getBooleanValue(uint16_t index, uint8_t fieldIndex);
    uint8_t getByteValue(uint16_t index, uint8_t fieldIndex);
    int16_t getIntValue(uint16_t index, uint8_t fieldIndex);
    int32_t getLongValue(uint16_t index, uint8_t fieldIndex);
    uint32_t getUnLongValue(uint16_t index, uint8_t fieldIndex);
    uint32_t getTimeValue(uint16_t index, uint8_t fieldIndex) { return getUnLongValue(index, fieldIndex); };

    bool hasEvent(uint16_t index);
    uint16_t event(uint16_t index);
    uint16_t getUsedRecordsSize();
    String getEventDescription(uint16_t index);

    void resetRecord(uint16_t index);
    void clearEventLog();

protected:
    virtual FlprogEventLogAbstractRecord *getRecord(uint16_t index) = 0;
    FlprogEventLogAbstractRecord *getRecordWithVirtualIndex(uint16_t index);
    uint16_t getMaxWeight();
    void sortVirtualIndexes();
    void checkWeight();
    void resetWeight();
    FlprogEventLogEvent *_events;
    uint16_t _eventsSize;
    uint16_t _recordsSize;
    uint8_t _fieldsSize;
    uint16_t *_virtualIndexes;
    bool _isSorted = false;
};
