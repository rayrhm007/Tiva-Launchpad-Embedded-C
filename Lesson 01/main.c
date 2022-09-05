
int main()
{
  volatile int counter = 0;
  
  for(int i = 0; i < 10; i++)
  {
    counter++;
  }
  
  return 0;
}
