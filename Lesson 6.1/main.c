#include "tm4c123gh6pm.h"

#define GPIODATA_F *((unsigned int volatile *)0x40025038u)       

int main()
{
  //BITWISE operation
  unsigned int a = 0x5A5A5A5A;
  unsigned int b = 0xDEADBEEF;
  unsigned int c;       //to hold bitwise operation results
  
  c = a | b;    // a OR b
  c = a & b;    // a AND b
  c = a ^ b;    // a XOR b
  c = ~b;       // b NOT
  c = b >> 1;   // b Right shift
  c = b << 3;   // b Left shift
  
  int x = 1024;
  int y = -1024;
  int z;
  
  z = x >> 3;
  z = y >> 3;
  
  
  //Enable RCGGPIO for clock signal to port F using typecasting and then dereferencing
  SYSCTL_RCGCGPIO_R = 0x20u;       //u to indicate unsigned
  
  //Set bits/pins 1,2,3 as output in GPIODIR port F register
  GPIO_PORTF_DIR_R = 0x0Eu;
  
  GPIO_PORTF_DEN_R = 0x0Eu;       //Digital enable function register
  
  int volatile count = 0;
 
  while(1)
  {
    count = 0;
    
    //For red LED
    GPIODATA_F = 0x02u;
    
    //provides delay of 1s
    while(count < 1000000)
    {
      count++;
    }
    
    count = 0;
    
    //For turning off all LED
    GPIODATA_F = 0x00u;
    
    //provides delay of 1s
    while(count < 1000000)
    {
      count++;
    }
    
  }
  
  return 0;
  
  return 0;
}
