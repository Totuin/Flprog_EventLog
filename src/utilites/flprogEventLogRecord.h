#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "fields\flprogEventLogTimeField.h"
#include "fields\flprogEventLogByteValueField.h"
#include "fields\flprogEventLogIntValueField.h"
#include "fields\flprogEventLogBooleanValueField.h"
#include "fields\flprogEventLogLongValueField.h"
#include "fields\flprogEventLogUnLongteValueField.h"

class FlprogEventLogRecord
{
public:
    void setFielSize(uint8_t fieldsSize);
    void setTimeField(uint8_t index);
    void setByteField(uint8_t index);
    void setIntegerField(uint8_t index);
    void setBooleanField(uint8_t index);
    void setLongField(uint8_t index);
    void setUnLongField(uint8_t index);

    void setBooleanValue(uint8_t index, bool value);
    void setByteValue(uint8_t index, uint8_t value);
    void setIntValue(uint8_t index, int16_t value);
    void setLongValue(uint8_t index, int32_t value);
    void setUnLongValue(uint8_t index, uint32_t value);
    void setTimeValue(uint8_t index, uint32_t value) { setUnLongValue(index, value); };

    void setEvent(uint16_t index);
    void copyFrom(FlprogEventLogRecord *record);

    bool hasEvent() { return _hasEvent; };
    uint16_t event() { return _eventIndex; };

    bool getBooleanValue(uint8_t index);
    uint8_t getByteValue(uint8_t index);
    int16_t getIntValue(uint8_t index);
    int32_t getLongValue(uint8_t index);
    uint32_t getUnLongValue(uint8_t index);
    uint32_t getTimeValue(uint8_t index) { return getUnLongValue(index); };

    FlprogEventLogAbstractField *getField(uint8_t index);

protected:
    uint8_t _fieldsSize = 0;
    bool _hasEvent = false;
    uint16_t _eventIndex;
    FlprogEventLogAbstractField *_fields;
};
