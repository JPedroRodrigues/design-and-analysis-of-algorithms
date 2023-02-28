#include <stdio.h>


float celsius_to_fahrenheit(float);


int main()
{
    printf("Informe uma temperatura em celsius: ");
    float temperatura;
    scanf("%f", &temperatura);

    printf("A temperatura de %.2f °C é equivalente a %.2f °F.\n", temperatura, celsius_to_fahrenheit(temperatura));

    return 0;
}


float celsius_to_fahrenheit(float celsius)
{
    return celsius * 9.0 / 5 + 32;
}
