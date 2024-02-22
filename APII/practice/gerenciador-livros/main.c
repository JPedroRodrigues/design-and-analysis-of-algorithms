#include <stdio.h>

/* Escrever um programa que:
  - Peça para que o usuário digite o seu nome;
  - Peça para o usuário digitar a sua idade;
  - Adicione o nome e a idade do usuário no final do arquivo contatos.txt
*/

int main0(void) {
  // Declarar a variável para receber o nome e a idade
  char nome[30];
  int idade;
  
  // Pedir o nome do usuário
  printf("Digite o seu nome completo: ");
  fgets(nome, 30, stdin);
  
  // Pedir a idade
  printf("Digite a sua idade: ");
  scanf("%d", &idade);
  
  // Declarar a variável para o arquivo
  FILE *arquivo;
  
  // Abrir o arquivo
  arquivo = fopen("contatos.txt", "a");
  
  // Escrever o arquivo
  fprintf(arquivo, "Nome: %s", nome);
  fprintf(arquivo, "Idade: %d\n", idade);
  
  // Fechar o arquivo
  fclose(arquivo);
  
  return 0;
}
