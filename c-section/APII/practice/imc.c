# include <stdio.h>

int main() {
  float peso, altura, imc;
  
  printf("Calculo do IMC.\n");
  
  printf("Insira o seu peso, em quilogramas: ");
  scanf("%f", &peso);
  printf("Insira a sua altura, em metros: ");
  scanf("%f", &altura);

  imc = peso / (altura * altura);

  // ".2f" ajuda a limitar o número real para apenas 2 casas decimais
  printf("O IMC de uma pessoa com peso %.2f kg e altura %.2f m é igual a %.2f.\n", peso, altura, imc);

  return 0;
}
