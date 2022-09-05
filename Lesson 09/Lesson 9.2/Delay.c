//Moving delay function to a separate file
#include "delay.h"

void delay(void)
{
  int volatile count = 0;
  
  while(count < 1000000)
  {
    count++;
  }
}