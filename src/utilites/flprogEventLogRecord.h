#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "fields/basicFields/flprogEventLogTimeField.h"
#include "fields/basicFields/flprogEventLogByteValueField.h"
#include "fields/basicFields/flprogEventLogIntValueField.h"
#include "fields/basicFields/flprogEventLogBooleanValueField.h"
#include "fields/basicFields/flprogEventLogLongValueField.h"
#include "fields/basicFields/flprogEventLogUnLongValueField.h"
#include "flprogEventLogEvent.h"
#include "flprogEventLogAbstractRecord.h"

// Запись в RAM. Владеет указателями на свои поля и освобождает их в деструкторе.
class FlprogEventLogRecord : public FlprogEventLogAbstractRecord
{
public:
    FlprogEventLogRecord() {};
    ~FlprogEventLogRecord() override;
    virtual void setFieldSize(uint8_t fieldsSize) override;
    virtual void setTimeField(uint8_t index) override;
    virtual void setByteField(uint8_t index) override;
    virtual void setIntegerField(uint8_t index) override;
    virtual void setBooleanField(uint8_t index) override;
    virtual void setLongField(uint8_t index) override;
    virtual void setUnLongField(uint8_t index) override;

    virtual FlprogEventLogAbstractField *getField(uint8_t index) override;

    virtual void setEvent(uint8_t index) override { _eventIndex = index; };
    virtual void setWeight(uint16_t value) override { _weight = value; };

    virtual bool hasEvent() override { return _weight > 0; };
    virtual uint8_t event() override { return _eventIndex; };
    virtual uint16_t getWeight() override { return _weight; };

protected:
    FlprogEventLogAbstractField **_fields = nullptr;
    uint16_t _weight = 0;
    uint8_t _eventIndex = 0;
};
