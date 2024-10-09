#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEventLogAbstractField.h"

class FlprogEventLogAbstractRecord
{
public:
    virtual void setFieldSize(uint8_t fieldsSize) = 0;
    virtual void setTimeField(uint8_t index) = 0;
    virtual void setByteField(uint8_t index) = 0;
    virtual void setIntegerField(uint8_t index) = 0;
    virtual void setBooleanField(uint8_t index) = 0;
    virtual void setLongField(uint8_t index) = 0;
    virtual void setUnLongField(uint8_t index) = 0;

    void setBooleanValue(uint8_t index, bool value);
    void setByteValue(uint8_t index, uint8_t value);
    void setIntValue(uint8_t index, int16_t value);
    void setLongValue(uint8_t index, int32_t value);
    void setUnLongValue(uint8_t index, uint32_t value);
    void setTimeValue(uint8_t index, uint32_t value) { setUnLongValue(index, value); };

    bool getBooleanValue(uint8_t index);
    uint8_t getByteValue(uint8_t index);
    int16_t getIntValue(uint8_t index);
    int32_t getLongValue(uint8_t index);
    uint32_t getUnLongValue(uint8_t index);
    uint32_t getTimeValue(uint8_t index) { return getUnLongValue(index); };

    virtual void setEvent(uint8_t index) = 0;
    virtual void setWeight(uint16_t value) = 0;

    virtual bool hasEvent() = 0;
    virtual uint8_t event() = 0;
    virtual uint16_t getWeight() = 0;

    virtual FlprogEventLogAbstractField *getField(uint8_t index) = 0;

protected:
    uint8_t _fieldsSize = 0;
};
