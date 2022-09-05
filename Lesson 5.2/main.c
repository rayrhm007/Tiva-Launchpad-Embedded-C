//LED Blink

#include "tm4c123gh6pm.h"       //Including our header file

/*
#define RCGC_GPIO *((unsigned int *)0x400FE608u)        RCGCGPIO now dereferences and uses the location 0x400FE608 for data manipulation
#define GPIO_DIR *((unsigned int *)0x40025400u)         GPIODIR now dereferences and uses the location 0x40025400 for data manipulation (GPIODIR_F + 0x400)
#define GPIO_DEN *((unsigned int *)0x4002551Cu)         GPIODEN now dereferences and uses location 0x4002551Cu for data manipultion (GPIODEN_F + 0x51C)


*///Commenting all this out because we included the header file. Need to replace all macros we made like GPIO_DEN and GPIODATA_F by their names in the header file

#define GPIODATA_F *((unsigned int volatile *)0x40025038u)       /*GPIODATA port F register + appropriate offset (0x038) to allow LED data 
                                                                 to be written to pins PF1, PF2 and PF3* (GPIOF + 0x038)*/
                                                          
int main()
{
  //Enable RCGGPIO for clock signal to port F using typecasting and then dereferencing
  SYSCTL_RCGCGPIO_R = 0x20u;       //u to indicate unsigned
  
  //Set bits/pins 1,2,3 as output in GPIODIR port F register
  GPIO_PORTF_DIR_R = 0x0Eu;
  
  GPIO_PORTF_DEN_R = 0x0Eu;       //Digital function register?
  
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
    
    count = 0;
    
    //For green LED
    GPIODATA_F = 0x08u;
    
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
    
    count = 0;
  
    //For blue LED
    GPIODATA_F = 0x0Eu;
    
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
}
