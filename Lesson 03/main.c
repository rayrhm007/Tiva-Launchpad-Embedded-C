//same program as initially, but with pointers
int counter = 0;

int main()
{
  
  int *p; //integer pointer stuff now
  p = &counter; //points to counter
  
  for(int i = 0; i < 10; i++)
  {
    (*p)++; //dereferencing
  }
  
  return 0;
}
