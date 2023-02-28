#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

float area_circulo(float raio)
{
    return M_PI * pow(raio, 2);
}

int main()
{
    printf("Insira o raio de um circulo: ");
    float r;
    scanf("%f", &r);

    printf("A área de um círculo de raio %.2f é %.2f.\n", r, area_circulo(r));

    return 0;
}
