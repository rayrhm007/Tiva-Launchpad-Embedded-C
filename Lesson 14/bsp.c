/* Board Support Package */

#include "tm4c_cmsis.h"

__stackless void assert_failed (char const *file, int line)
{
  /* This code is modified by user according to project requirements */
  
  NVIC_SystemReset(); //System reset by TMSIS
}
