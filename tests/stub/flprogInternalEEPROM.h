#pragma once
#include "flprogEEPROM.h"
class FLProgInternalEEPROM:public FLProgAbstractEEPROM {
public:
  FLProgInternalEEPROM(uint16_t capacity, uint8_t marker):FLProgAbstractEEPROM(capacity){(void)marker;}
};
