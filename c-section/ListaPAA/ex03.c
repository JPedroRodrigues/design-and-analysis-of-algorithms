#include <stdio.h>
#include <stdbool.h>

#define TAM 2

typedef struct {
        int matricula, digito;
} MatriculaAluno;


void lerDados(MatriculaAluno v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nº de matrícula: ");
        scanf("%d", &v[i].matricula);

        printf("Dígito verificador: ");
        scanf("%d", &v[i].digito);
    }
}


bool digitoValido(MatriculaAluno aluno) {
    int n = aluno.matricula;
    int verificador = aluno.digito;
    int soma = 0, peso = 2;
    
    while (n != 0) {
        soma += (n % 10) * peso;
        peso++;
        n = n / 10;
    }
    int restoSoma = soma % 11;
    int ver = 11 - restoSoma;

    if (ver == verificador) return true;
    else return false;
}


int main() {
    MatriculaAluno v[TAM];
    lerDados(v, TAM);

    printf("Número\t\tMensagem\n");
    for (int i = 0; i < TAM; i++) {
        if (digitoValido(v[i])) {
            printf("%d-%d\tDigito verificador correto\n", v[i].matricula, v[i].digito);
        } else {
            printf("%d-%d\tDigito verificador incorreto\n", v[i].matricula, v[i].digito);
        }
    }
    
    return 0;
}