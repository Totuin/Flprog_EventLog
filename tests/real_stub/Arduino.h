#pragma once
#include <cstdint>
#include <cstring>
#include <string>
#include <climits>
class String: public std::string {
public:
 using std::string::string;
 String(const std::string& s):std::string(s){}
 char charAt(size_t i)const{return at(i);}
 void concat(char c){push_back(c);}
};
#define bitRead(value,bit) (((value) >> (bit)) & 1u)
#define bitWrite(value,bit,val) ((val) ? (value) |= (1u<<(bit)) : (value) &= ~(1u<<(bit)))
inline uint8_t highByte(int16_t x){return static_cast<uint16_t>(x)>>8;}
inline uint8_t lowByte(int16_t x){return static_cast<uint16_t>(x)&255;}
inline uint16_t word(uint8_t hi,uint8_t lo){return (uint16_t(hi)<<8)|lo;}
