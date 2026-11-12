#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "flprogEventLogUnLongValueField.h"

// Поле времени — тот же uint32_t, специального двоичного формата нет.
class FlprogEventLogTimeField : public FlprogEventLogUnLongteValueField
{

public:
protected:
};
