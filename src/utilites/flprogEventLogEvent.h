#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"

// Описание типа события для отображения в интерфейсе FLProg.
// Оно хранится только в RAM, а не в памяти EEPROM.
class FlprogEventLogEvent
{
public:
    void setDescription(String description) { _description = description; };
    String getDescription() { return _description; };

protected:
    String _description = "";
};
