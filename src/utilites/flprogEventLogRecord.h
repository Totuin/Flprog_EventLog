#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "fields\basicFields\flprogEventLogTimeField.h"
#include "fields\basicFields\flprogEventLogByteValueField.h"
#include "fields\basicFields\flprogEventLogIntValueField.h"
#include "fields\basicFields\flprogEventLogBooleanValueField.h"
#include "fields\basicFields\flprogEventLogLongValueField.h"
#include "fields\basicFields\flprogEventLogUnLongteValueField.h"
#include "flprogEventLogEvent.h"
#include "flprogEventLogAbstractRecord.h"

class FlprogEventLogRecord : public FlprogEventLogAbstractRecord
{
public:
    FlprogEventLogRecord() {};
    virtual void setFieldSize(uint8_t fieldsSize);
    virtual void setTimeField(uint8_t index);
    virtual void setByteField(uint8_t index);
    virtual void setIntegerField(uint8_t index);
    virtual void setBooleanField(uint8_t index);
    virtual void setLongField(uint8_t index);
    virtual void setUnLongField(uint8_t index);
    
      virtual FlprogEventLogAbstractField *getField(uint8_t index);

protected:
  
    FlprogEventLogAbstractField *_fields;
};
