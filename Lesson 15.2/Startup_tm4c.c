/* Startup Code */

#include "tm4c_cmsis.h"

extern int CSTACK$$Limit;       // This declares our section symbol, but the variable isn't saved 
                                // in memory due to 'extern'

void __iar_program_start(void); // __iar_program_start is symbol for reset function that takes
                                // no arguements (void)

void Unused_Handler(void);

int const __vector_table[] @ ".intvec" =     //convention for naming startup code and placing it in "intvec" section
{
  (int)&CSTACK$$Limit,
  
  (int)&__iar_program_start,    // typecasted to int for compilation compliance
    
  (int)&NMI_Handler,

  (int)&HardFault_Handler,

  (int)&MemManage_Handler,
  
  (int)&BusFault_Handler,
  
  (int)&UsageFault_Handler,
  
  // Reserved Block from 0x001C to 0x002C
  0,
  0,
  0,
  0,
  
  (int)&SVC_Handler,
  
  (int)&DebugMon_Handler,
  
  0,
  
  (int)&PendSV_Handler,
  
  (int)&SysTick_Handler
  
};

__stackless void HardFault_Handler(void)
{
  assert_failed("HardFault", __LINE__);
}

__stackless void MemManage_Handler(void)
{
  assert_failed("MemManage", __LINE__);
}

__stackless void BusFault_Handler(void)
{
  assert_failed("BusFault", __LINE__);
}

__stackless void UsageFault_Handler(void)
{
  assert_failed("UsageFault", __LINE__);
}

__stackless void Unused_Handler(void)
{
  assert_failed("Unused", __LINE__);
}

// Defining the final unused exception handlers using weak aliases
#pragma weak SVC_Handler = Unused_Handler
#pragma weak DebugMon_Handler = Unused_Handler
#pragma weak PendSV_Handler = Unused_Handler
#pragma weak SysTick_Handler = Unused_Handler