#include <stdint.h>

#include "tm4c_cmsis.h"
#include "bsp.h"

// All #define statements moved to bsp.h header file

int main()
{
  // GPIO set up
  SYSCTL->RCGC2 |= (1U << 5);
  SYSCTL->GPIOHSCTL |= (1U << 5); 
  GPIOF_HS->DIR |= (1U << 3)|(1U << 2)|(1U << 1);    
  GPIOF_HS->DEN |= (1U << 3)|(1U << 2)|(1U << 1);
  
  /* Setting up new SysTick registers
  Set up SysTick control register (interrupt, counter and clock source to SysTick enabled)*/
  SysTick->CTRL = (1U << 2)|(1U << 1)|(1U << 0);
  
  // SysTick Reload gets half of clock value (half of a second). This value fits within 24 bits and doesn't overflow counter range
  SysTick->LOAD = (SYSCLOCK_HZ/2) - 1;  
  
  // Always cleared no matter what is written to it  
  SysTick->VAL = 0x00;
  
  __iar_builtin_enable_interrupt();
  
  SysTick_Handler();
    
  // While loop is executed in-between each interrupt call 
  while(1) 
  {
     // This has the effect of dimming the LED. LED is toggled during interrupts from SysTick and within while loop  
     GPIOF_HS->DATA_Bits[G_LED] ^= G_LED;
     GPIOF_HS->DATA_Bits[G_LED] ^= G_LED;
  }
    
}
