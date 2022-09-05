#include <stdint.h>

#include "tm4c_cmsis.h"
#include "delay.h"

#define R_LED (1U << 1)
#define B_LED (1U << 2)
#define G_LED (1U << 3)

typedef struct point
{
  uint8_t x;
  uint16_t y;
}Point;

Point p1 = {123U, 0xABCD};

typedef struct Window
{
  Point top;
  Point bottom;
}Window;

 

int main()
{
  Window w1 = { {p1.x, p1.y}, {234, 0xCACA} };
  Window w2;
  
  // enable clock for GPIOF
  SYSCTL->RCGC2 |= 0x20;
  
  // enable AHB for GPIOF 
  SYSCTL->GPIOHSCTL |= 0x20; 
  
  // Data output direction
  GPIOF_HS->DIR |= 0x0E;    
  
  // Data enable 
  GPIOF_HS->DEN |= 0x0E;

  while(1) 
  {
    GPIOF_HS->DATA_Bits[0x02] = R_LED;
    
    delay(500000);

    GPIOF_HS->DATA_Bits[0x02] = 0;
    
    delay(500000);
    
  }
    
}
