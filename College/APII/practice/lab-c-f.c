#include <stdio.h>


float c2f(float celsius)
{
  return celsius * 9.0 / 5 + 32;
}


float f2c(float fahrenheit)
{
  return 5.0 / 9 * (fahrenheit - 32);
}


int main()
{
  int opcao;
  float temperatura;

  printf("MENU DE OPÇÕES\n");
  printf("(1) Converter de Celsius para Fahrenheit.\n");
  printf("(2) Converter de Fahrenheit para Celsius.\n");

  printf("Digite uma opção: ");
  scanf("%d", &opcao);

switch (opcao)
{
  case 1:
    printf("\nConversor Celsius - Fahrenheit\n");
    printf("Digite uma temperatura em Celsius: ");
    scanf("%f", &temperatura);
    
    printf("%.2f °C equivale a %.2f °F.\n", temperatura, c2f(temperatura));
    break;
    
  case 2:
    printf("\nConversor Fahrenheit - Celsius\n");
    printf("Digite uma temperatura em Fahrenheit: ");
    scanf("%f", &temperatura);

    printf("%.2f em °F equivale a %.2f °C.\n", temperatura, f2c(temperatura));
    break;

  default:
    printf("Opção Inválida.\n");
  }

  return 0;
}
