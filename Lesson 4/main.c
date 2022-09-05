//LED Blink

int main()
{
  //Enable RCGGPIO for clock signal to port F using typecasting and then dereferencing
  *((unsigned int *)0x400FE608u) = 0x20u;       //u to indicate unsigned
  
  //Set bits 1,2,3 at address 0x40025400 and 0x4002541C using typecasting and then dereferencing
  *((unsigned int *)0x40025400u) = 0x0Eu;       //GPIO F Pin direction register
  
  *((unsigned int *)0x4002541Cu) = 0x0Eu;       //Digital function register?
  
  int count = 0;
 
  while(1)
  {
    count = 0;
    
    //For red LED
    *((unsigned int *)0x400253FCu) = 0x02u;
    
    //provides delay of 1s
    while(count < 1000000)
    {
      count++;
    }
    
    count = 0;
    
    //For turning off all LED
    *((unsigned int *)0x400253FCu) = 0x00u;
    
    //provides delay of 1s
    while(count < 1000000)
    {
      count++;
    }
    
    count = 0;
    
    //For green LED
    *((unsigned int *)0x400253FCu) = 0x08u;
    
    //provides delay of 1s
    while(count < 1000000)
    {
      count++;
    }
    
    count = 0;
    
    //For turning off all LED
    *((unsigned int *)0x400253FCu) = 0x00u;
    
    //provides delay of 1s
    while(count < 1000000)
    {
      count++;
    }
    
    count = 0;
  
    //For blue LED
    *((unsigned int *)0x400253FCu) = 0x0Eu;
    
    //provides delay of 1s
    while(count < 1000000)
    {
      count++;
    }
    
    count = 0;
    
    //For turning off all LED
    *((unsigned int *)0x400253FCu) = 0x00u;
    
    //provides delay of 1s
    while(count < 1000000)
    {
      count++;
    }
  
  }
  
  return 0;
}
