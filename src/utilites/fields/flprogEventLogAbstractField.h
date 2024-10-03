#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"

class FlprogEventLogAbstractField
{
public:
    void copyFrom(FlprogEventLogAbstractField *field);
    virtual bool booleanValue() { return false; };
    virtual uint8_t byteValue() { return 0; };
    virtual int16_t intValue() { return 0; };
    virtual int32_t longValue() { return 0; };
    virtual uint32_t unLongValue() { return 0; };
    virtual uint32_t timeValue() { return unLongValue(); };

    virtual void setBooleanValue(bool value) { (void)value; };
    virtual void setByteValue(uint8_t value) { (void)value; };
    virtual void setIntValue(int16_t value) { (void)value; };
    virtual void setLongValue(int32_t value) { (void)value; };
    virtual void setUnLongValue(uint32_t value) { (void)value; };
    virtual void setTimeValue(uint32_t value) { setUnLongValue(value); };

protected:
    virtual void
    privateCopyFrom(FlprogEventLogAbstractField *field) { (void)field; };
};
