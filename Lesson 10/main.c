#include "tm4c123gh6pm.h"
#include <stdint.h>

// Defining types
int8_t s8a;
int16_t s16a;
int32_t s32a;
uint8_t u8a;

int main()
{ 
  
  // Checking sizeof types
  u8a = sizeof(uint8_t);
  s8a = sizeof(int8_t);
  s32a = sizeof(int32_t);
  
  // Assigning values to variables
  u8a = 0xfcU;
  s16a = 0xbff5;
  s32a = 0xcacacaca;
  
  
  s32a = s8a;
  s8a = u8a;
  
  return 0;
}
