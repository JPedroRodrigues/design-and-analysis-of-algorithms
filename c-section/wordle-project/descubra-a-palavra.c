#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/*
 * Função que verifica se uma letra de dois vetores distintos é igual e se encontra na mesma posição.
 */
bool mesma_posicao(char palavra[], char palpite[], int indice)
{
  if (palpite[indice] == palavra[indice]) {
      return true;
  }
  return false;
}

/*
 * Função que verifica se uma letra pertence a outra palavra e se está em uma posição diferente em caso afirmativo.
 */
bool pertence(char palavra[], char palpite[], int tam, int indice)
{
    for (int i = 0; i < tam; i++) {
        if (palpite[indice] == palavra[i] && indice != i) {
            return true;
        }
    }
    return false;
}

/*
 * Função que verifica e informa se o usuário acertou a palavra, além de formatar a saída.
 */
bool resultado_jogo(char palavra[], char palpite[])
{
    char simbolos[6];
    int i, igualdade = 0;
    int len = strlen(palpite);
  
    printf("\n+-----------+\n");
    printf("| %c %c %c %c %c |\n", palpite[0], palpite[1], palpite[2], palpite[3], palpite[4]);
    printf("|");
    for (i = 0; i < len; i++) {
        if (palpite[i] == palavra[i]) {
              igualdade++;
        }
        if (mesma_posicao(palavra, palpite, i)) {
            printf(" ^");
        }
        else if (pertence(palavra, palpite, len, i)){
            printf(" !");
        }
        else {
            printf(" x");
        }
    }
    printf(" |\n");
    printf("+-----------+\n");

    if (igualdade == 5) {
        return true;
    }
    return false;
}


int main()
{   
    srand(time(NULL));
  
    FILE *arq, *score;
    char palavra[20], palpite[20], nome[50];
    int len, i, n_aleatorio, cont = 0;
    bool acerto;
    time_t inicio, fim;
    
    arq = fopen("sem_acentos.txt","r");

    // Gerar um número aleatório para sortear a palavra
    n_aleatorio = rand() % 1521 + 1;

    // Percorrer o arquivo e selecionar a palavra sorteada
    while (!feof(arq)){
      if (NULL != fgets(palavra, 20, arq) && strlen(palavra) - 2 == 5) {
          cont++;
          if (cont == n_aleatorio) {
              //printf("Palavra sorteada: %s", palavra);
              break;
          }
      }
    }
    fclose(arq);

    // Início do Jogo
    for (i = 0; i < 12; i++) {
        printf("-");
        if (i == 5) {
            printf("| DESCRUBRA A PALAVRA |");
        }
    }
    printf("\n\n");
  
    printf("Digite o seu nome: ");
    fgets(nome, 50, stdin);
    
    for (i = 1; i <= 6; i++) {
        do {
            inicio = time(NULL);
            
            printf("Digite uma palavra de 5 letras: ");
            scanf("%s", palpite);
            len = strlen(palpite);
        } while (len != 5);
      
        acerto = resultado_jogo(palavra, palpite);
      
        fim = time(NULL);
        
        if (acerto) {
            printf("Parabéns, você acertou!\n");
            // Escrita do resultado no arquivo
            score = fopen("scores.txt", "a");
          
            fprintf(score, "Nome: %s", nome);
            fprintf(score, "Palavra: %s", palavra);
            fprintf(score, "Tentativas: %d\n", i);
            fprintf(score, "Tempo de jogo: %ds\n\n", ((int) (fim - inicio)));
          
            fclose(score);
            break;
        }
    }
    return 0;
}
