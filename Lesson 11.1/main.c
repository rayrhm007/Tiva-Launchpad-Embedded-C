#include "tm4c123gh6pm.h"
#include <stdint.h>

#define R_LED (1u << 1) //shift 1 (0001) by 1 unit to turn on red led (0010)
#define G_LED (1u << 3) //shift 1 (0001) by 3 units to turn on green led (1000)
#define B_LED (1u << 2) //shift 1 (0001) by 2 units to turn on blue led (0100)

// Structures in embedded C. This one is used to represent points in an LCD
typedef struct point
{
  uint8_t y;
  uint16_t x;
  
}point;

void delay(void)
{
  int volatile count = 0;
  
  while(count < 1000000)
  {
    count++;
  }
}


int main()
{ 
  point p1;
  
  p1.x = sizeof(point);
  p1.y = 0xAAu;
  
  SYSCTL_RCGCGPIO_R |= 0x20u;
  
  SYSCTL_GPIOHBCTL_R |= 0x20u;  
  
  GPIO_PORTF_AHB_DIR_R |= 0x0Eu;
  
  GPIO_PORTF_AHB_DEN_R |= 0x0Eu;       
 
  while(1)
  {
    
    //For red LED
    *(GPIO_PORTF_AHB_DATA_BITS_R + 0x02) |= R_LED;   
     
    delay();
    
    *(GPIO_PORTF_AHB_DATA_BITS_R + 0x02) &= 0x00u;
    
  }
  
  
  return 0;
}
