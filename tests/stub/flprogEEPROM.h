#pragma once
#include <Arduino.h>
#include <vector>
#include <cassert>
class FLProgAbstractEEPROM {
public:
 explicit FLProgAbstractEEPROM(unsigned size=4096):data(size,0){}
 virtual ~FLProgAbstractEEPROM() {}
 virtual void begin(){}
 virtual void pool(){}
 std::vector<uint8_t> data;
 bool readBoolean(uint16_t a,uint8_t b){assert(b<8);return readByte(a)&(1u<<b);}
 uint8_t readByte(uint16_t a){return data.at(a);}
 int16_t readInteger(uint16_t a){return static_cast<int16_t>((uint16_t(readByte(a))<<8)|readByte(a+1));}
 int32_t readLong(uint16_t a){return static_cast<int32_t>(readUnsignedLong(a));}
 uint32_t readUnsignedLong(uint16_t a){uint32_t x=0;for (int i=0;i<4;++i)x|=(uint32_t(readByte(a+i))<<(i*8));return x;}
 void saveBoolean(uint16_t a,uint8_t b,bool v){uint8_t x=readByte(a);saveByte(a,v?(x|(1u<<b)):(x&~(1u<<b)));}
 void saveByte(uint16_t a,uint8_t v){data.at(a)=v;}
 void saveInteger(uint16_t a,int16_t v){saveByte(a,static_cast<uint16_t>(v)>>8);saveByte(a+1,v&255);}
 void saveLong(uint16_t a,int32_t v){saveUnsignedLong(a,static_cast<uint32_t>(v));}
 void saveUnsignedLong(uint16_t a,uint32_t v){for(int i=0;i<4;++i)saveByte(a+i,(v>>(i*8))&255);}
};
