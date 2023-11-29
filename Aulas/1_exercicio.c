/*
  Crie um programa que solicite ao usuário informar um valor inteiro positivo e:
  a) realize a soma de todos os valores entre 0 e o valor informado. (incluindo o valor informado)
  b) calcule o valor medio. (total dividido pela quantidade que foi somado)
  c) soma dos impares.
  d) soma dos pares.
  e) diferença da soma de pares pela soma dos impares
*/

#include <stdio.h>
int main() {
  int valor = 0, soma = 0, valormedio = 0, somaimpares = 0, somapares = 0, diferenca = 0;

  printf("--------------------------------------");
  printf("\nDigite um valor inteiro positivo: ");
  scanf("%d", &valor);
  printf("--------------------------------------");

  for (int i = 0; i <= valor; i++) {
    soma += i; //soma de todos os valores entre 0 e o valor informado. (incluindo o valor informado)
    
    if ((i % 2) == 0) {
      somapares = (somapares + i); //soma dos pares.
    } else {
      somaimpares = (somaimpares + i); //soma dos impares.
    }
  }

  valormedio = (soma / valor); //calcule o valor medio. (total dividido pela quantidade que foi somado)
  diferenca = (somapares - somaimpares);  //diferença da soma de pares pela soma dos impares

  printf("\nSoma de todos os numeros: %d", soma);
  printf("\nValor medio: %d", valormedio);
  printf("\nSoma dos impares: %d", somaimpares);
  printf("\nSoma dos pares: %d", somapares);
  printf("\nDiferenca entre a soma dos pares e impares: %d", diferenca);
  printf("\n--------------------------------------");

  return 0;
}