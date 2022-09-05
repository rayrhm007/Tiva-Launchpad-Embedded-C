#include "tm4c123gh6pm.h"

#define GPIODATA_F *((unsigned int volatile *)0x40025038u)

//utilizing shift operation for LED blinking
#define R_LED (1u << 1) //shift 1 (0001) by 1 unit to turn on red led (0010)
#define G_LED (1u << 3) //shift 1 (0001) by 3 units to turn on green led (1000)
#define B_LED (1u << 2) //shift 1 (0001) by 2 units to turn on blue led (0100)

int main()
{ 
  //Enable RCGGPIO for clock signal to port F using typecasting and then dereferencing
  SYSCTL_RCGCGPIO_R |= 0x20u;       //u to indicate unsigned
  
  //Set bits/pins 1,2,3 as output in GPIODIR port F register
  GPIO_PORTF_DIR_R |= 0x0Eu;
  
  GPIO_PORTF_DEN_R |= 0x0Eu;       //Digital function register?
  
  int volatile count = 0;
 
  while(1)
  {
    count = 0;
    
    //For red LED
    GPIODATA_F |= G_LED;        //setting GPIO_DATA as GPIO_DATA || B_LED
    
    //provides delay of 1s
    while(count < 1000000)
    {
      count++;
    }
    
    count = 0;
    
    //For turning off all LED
    GPIODATA_F &= 0x00;
    
    //provides delay of 1s
    while(count < 1000000)
    {
      count++;
    }
    
  }
  
  
  return 0;
}
