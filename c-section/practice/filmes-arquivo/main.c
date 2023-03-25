#include <stdio.h>

// Manipulando arquivos em C
int main(void) {
  // Declarar a variável para acessar o arquivo
  FILE *arquivo;
  // Abrir o arquivo
  arquivo = fopen("doc.txt", "a");
  if (arquivo == NULL) {
    printf("Erro ao tentar abrir o arquivo doc.txt\n");
    return -1;
  }
  // Escrever no arquivo
  fprintf(arquivo, "Squid Game\n");
  fprintf(arquivo, "Gossip Girl\n");
  fprintf(arquivo, "O pacificador\n");
  fprintf(arquivo, "Stranger Things\n");
  fprintf(arquivo, "The Last of Us\n");
  // Fechar o arquivo
  fclose(arquivo);
  return 0;
}
