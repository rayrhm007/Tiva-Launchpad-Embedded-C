/* Board Support Package */

#include "tm4c_cmsis.h"
#include "bsp.h"

__stackless void assert_failed (char const *file, int line)
{
  /* This code is modified by user according to project requirements */
  
  NVIC_SystemReset(); //System reset by TMSIS
}

// Systick handler functions for when interrupts happen
void SysTick_Handler(void)
{
  // Use of new XOR operator (^=) to toggle LED on/off
    GPIOF_HS->DATA_Bits[G_LED] ^= G_LED;
}
