#include <stdio.h>

void listar()
{
  FILE *arq;
  char livro[100];

  arq = fopen("livros.txt", "r");

  printf("Livros cadastrados:\n");

  while (!feof(arq)) {
    if (NULL != fgets(livro, 100, arq)) {
      printf("- %s", livro);
    }
  }
  fclose(arq);
}

void cadastrar()
{
  FILE *arq;
  arq = fopen("livros.txt", "a");

  char livro[100];
  printf("Digite o nome do livro: ");
  fgets(livro, 100, stdin);
  fprintf(arq, "%s", livro);

  printf("# Livro cadastrado com sucesso!\n");
  fclose(arq);
}

int main()
{
  printf("# MENU\n");
  printf("(1) Cadastrar\n");
  printf("(2) Listar\n");
  printf("(3) Sair\n");

  printf("# Escolha uma opção: ");
  int opcao;
  char op[3];
  fgets(op, 3, stdin);

  opcao = atoi(op);

  if (opcao == 1) {
    cadastrar();
  }
  if (opcao == 2) {
    listar();
  }
}