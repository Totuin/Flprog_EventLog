#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "fields\eepromFields\flprogEepromEventLogTimeField.h"
#include "fields\eepromFields\flprogEepromEventLogByteValueField.h"
#include "fields\eepromFields\flprogEepromEventLogIntValueField.h"
#include "fields\eepromFields\flprogEepromEventLogBooleanValueField.h"
#include "fields\eepromFields\flprogEepromEventLogLongValueField.h"
#include "fields\eepromFields\flprogEepromEventLogUnLongteValueField.h"
#include "flprogEventLogEvent.h"
#include "flprogEventLogAbstractRecord.h"

class FlprogEepromEventLogRecord : public FlprogEventLogAbstractRecord
{
public:
    virtual void setFieldSize(uint8_t fieldsSize);
    virtual void setTimeField(uint8_t index);
    virtual void setByteField(uint8_t index);
    virtual void setIntegerField(uint8_t index);
    virtual void setBooleanField(uint8_t index);
    virtual void setLongField(uint8_t index);
    virtual void setUnLongField(uint8_t index);
    virtual FlprogEventLogAbstractField *getField(uint8_t index);

protected:
    FlprogEepromEventLogAbstractField *_fields;
};
