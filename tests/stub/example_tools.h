#pragma once
#include "Arduino.h"
struct FakeSerial {void begin(unsigned long){} void println(const char*){} void println(unsigned long){} void print(const char*){} };
static FakeSerial Serial;
inline uint32_t millis(){return 123456u;}
