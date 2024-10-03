#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"

class FlprogEventLogEvent
{
public:
    void setDescription(String description) { _description = description; };
    String getDescription() { return _description; };

protected:
    String _description = "";
};
