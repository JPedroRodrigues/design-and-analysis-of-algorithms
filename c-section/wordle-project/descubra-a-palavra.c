/* Projeto Wordle
 * Nome: João Pedro Rodrigues Vieira | TIA: 32281730
 * Turma: 02N | Algoritmos e Programação II
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/*
 * Função que verifica se duas palavras são iguais.
 */
bool palavra_correta(char palavra[], char palpite[], int len)
{
    int igualdade = 0;
    for (int i = 0; i < len; i++) {
        if (palpite[i] == palavra[i]) {
            igualdade++;
        }
    }
    if (igualdade == 5) {
        return true;
    }
    return false;
}

/*
 * Função que verifica se uma palavra pertence à base de dados do programa.
 */
bool palavra_consta(char palpite[], int len) {
    FILE *arquivo;
    char palavra[10];
  
    arquivo = fopen("sem_acentos.txt", "r");
    while(!feof(arquivo)) {
        if (NULL != fgets(palavra, 10, arquivo) && strlen(palavra) - 2 == 5 && palavra_correta(palavra, palpite, len)) {
            return true;
        }
    }
    fclose(arquivo);
    return false;
}

/*
 * Função que imprime na tela o resultado do palpite do jogador.
 */
void resultado_jogo(char palavra[], char palpite[], int len)
{
    char simbolos_palpite[] = {'x', 'x', 'x', 'x', 'x'};
    char simbolos_palavra[] = {'x', 'x', 'x', 'x', 'x'};
    int igualdade = 0;
  
    printf("\n+-----------+\n");
    printf("| %c %c %c %c %c |\n", palpite[0], palpite[1], palpite[2], palpite[3], palpite[4]);
  
    for (int i = 0; i < len; i++) {
        if (palpite[i] == palavra[i]) {
            igualdade++;
            simbolos_palpite[i] = '^';
            simbolos_palavra[i] = '^';
        }
    }

    for (int c = 0; c < len; c ++) {
        for (int j = 0; j < len; j++) {
            if ((palpite[c] == palavra[j] && j != c) && (simbolos_palavra[j] == 'x' && simbolos_palpite[c] == 'x')) {
              simbolos_palavra[j] = '!';
              simbolos_palpite[c] = '!';
          }
      }
    }
    
    printf("|");
    for (int ind = 0; ind < len; ind++) {
        printf(" %c", simbolos_palpite[ind]);
    }
    printf(" |\n");
    printf("+-----------+\n\n");
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
              // printf("Palavra sorteada: %s", palavra);
              break;
          }
      }
    }
    fclose(arq);

    // Início do Jogo
    printf("<------| DESCRUBRA A PALAVRA |------>");
    printf("\n\n");
  
    printf("Digite o seu nome: ");
    fgets(nome, 50, stdin);
    
    for (i = 1; i <= 6; i++) {
        inicio = time(NULL);
      
        // Entrada do palpite pelo usuário
        do {
            printf("Digite uma palavra de 5 letras: ");
            scanf("%s", palpite);
            len = strlen(palpite);
          
            if (!palavra_consta(palpite, len)) {
                printf("\nPalavra inválida! ");
            }
        } while (!palavra_consta(palpite, len));
        
        printf("\n<------| %d° Tentativa |------>\n", i);
        // Mostragem do resultado ao jogador
        resultado_jogo(palavra, palpite, len);
        acerto = palavra_correta(palavra, palpite, len);
        
        if (acerto) {
            fim = time(NULL);
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
