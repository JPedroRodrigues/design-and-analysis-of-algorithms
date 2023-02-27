/*
Refinamentos sucessivos top-down

Topo: verificar se um cliente ultrapassou o limite de crédito a partir das suas informações financeiras

1° refinamento:
- Inicializar as variáveis
- Receber as informações do cliente
- Calcular o novo saldo e verificar se ele ultrapassou o limite de crédito

2° Refinamento:

int numero_da_conta;
float saldo_inicial, encargos, creditos, limite_credito, saldo_final;

loop infinito
    recebo numero da conta;
    se o número da conta for igual a -1{
        interrompe o looping
    }
    recebo saldo_inicial;
    recebo encargos;
    recebo creditos;
    leio limite_credito;

    saldo final = saldo_inicial + encargos - limite_credito;
    se saldo_final for maior que limite_credito{
        mostro numero da conta;
        mostro limite de credito;
        mostro o novo saldo;
        imprimo a mensagem "Limite de crédito ultrapassado!"
    }
fim do programa
*/

#include <stdio.h>

int main(){
    int numero_conta;
    float saldo_inicial;
    float encargos;
    float creditos;
    float limite_credito;

    while (1){
        printf("\nDigite o número da sua conta: ");
        scanf("%d", &numero_conta);

        if (numero_conta == -1){
            break;
        }

        printf("Insira seu saldo inicial: ");
        scanf("%f", &saldo_inicial);

        printf("Informe o total de encargos: ");
        scanf("%f", &encargos);

        printf("Informe o total de créditos: ");
        scanf("%f", &creditos);

        printf("Informe o limite de crédito: ");
        scanf("%f", &limite_credito);

        float saldo_final = saldo_inicial + encargos - creditos;

        if (saldo_final > limite_credito){
            printf("\nInformações do usuário\n\n");
            printf("Número da conta: %d\n", numero_conta);
            printf("Limite de crédito: R$%.2f\n", limite_credito);
            printf("Novo saldo: R$%.2f\n", saldo_final);
            printf("\nLIMITE DE CRÉDITO ULTRAPASSADO!\n\n");
        }
    }
    return 0;
}
