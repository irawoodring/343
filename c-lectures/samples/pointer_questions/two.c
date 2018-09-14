# include <stdio.h>
void fun(int *ptr)
{
    *ptr = 30;
}
 
int main(int argc, char** argv)
{
  int y = 20;
  fun(&y);
  printf("%d", y);
 
  return 0;
}
