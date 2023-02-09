#include <stdio.h>

int main() {
  float celsius, fahren;

  printf("Insira uma temperatura em Celsius: ");
  scanf("%f", &celsius);

  fahren = (celsius * 9.0 / 5) + 32;

  printf("Uma temperatura de %.1f graus Celsius equivale a %.1f graus Fahrenheit.\n", celsius, fahren);

  return 0;
}