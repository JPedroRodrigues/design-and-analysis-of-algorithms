#include <stdio.h>

int main(){
    int aulasTotais;
    printf("Número total de aulas: ");
    scanf("%d", &aulasTotais);

    int presenca;
    printf("N° de aulas em que o aluno esteve presente: ");
    scanf("%d", &presenca);

    float taxa = 1.0 * presenca / aulasTotais;
    if (taxa >= 0.75){
        printf("Dentro do limite de faltas.\n");
    } // fim do if
    else {
        printf("Reprovado por faltas!\n");
    } // fim do else
    printf("Fim!\n");

    return 0;
}
