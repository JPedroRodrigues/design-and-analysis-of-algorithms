#include <stdio.h>


void tabuada(int n)
{
  printf("\nTabudada do %d\n\n", n);
  
  for (int i = 1; i <= 10; i++)
  {
    printf("%2d x %2d = %3d\n", n, i, n * i);
  }
}


int main()
{
  for (int contador = 1; contador <= 10; contador++)
  {
    tabuada(contador);
  }

  return 0;
}
