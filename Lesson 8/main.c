#include "tm4c123gh6pm.h"

//utilizing shift operation for LED blinking
#define R_LED (1u << 1) //shift 1 (0001) by 1 unit to turn on red led (0010)
#define G_LED (1u << 3) //shift 1 (0001) by 3 units to turn on green led (1000)
#define B_LED (1u << 2) //shift 1 (0001) by 2 units to turn on blue led (0100)

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
  //Enable RCGGPIO for clock signal to port F using typecasting and then dereferencing
  SYSCTL_RCGCGPIO_R |= 0x20u;       //u to indicate unsigned
  
  //Enable AHB for GPIO port F (indicated by bit 5 of GPIOHBCTL)
  SYSCTL_GPIOHBCTL_R |= 0x20u;  
  
  //Set bits/pins 1,2,3 as output in GPIODIR port F register (AHB)
  GPIO_PORTF_AHB_DIR_R |= 0x0Eu;
  
  //Digital function enable register (AHB)
  GPIO_PORTF_AHB_DEN_R |= 0x0Eu;       
 
  while(1)
  {
    
    //For red LED
    *(GPIO_PORTF_AHB_DATA_BITS_R + 0x02) = R_LED;   //using AHB to set portf pins
     
    //set a breakpoint here and see how delay works
    delay();
    
    //For turning off all LED
    *(GPIO_PORTF_AHB_DATA_BITS_R + 0x02) &= 0x00;
    
    //provides delay of 1s
    delay();
    
    *(GPIO_PORTF_AHB_DATA_BITS_R + 0x08) = G_LED;
    
    delay();
    
    *(GPIO_PORTF_AHB_DATA_BITS_R + 0x08) &= 0x00;
    
    delay();
    
  }
  
  
  return 0;
}
