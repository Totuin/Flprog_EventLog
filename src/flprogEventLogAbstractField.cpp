#include "flprogEventLogAbstractField.h"

void FlprogEventLogAbstractField::copyFrom(FlprogEventLogAbstractField *field)
{
    if (field == 0)
    {
        return;
    }
    privateCopyFrom(field);
}