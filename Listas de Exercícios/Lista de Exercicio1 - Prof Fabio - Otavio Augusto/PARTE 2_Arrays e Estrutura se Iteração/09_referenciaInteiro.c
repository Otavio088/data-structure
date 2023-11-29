/*
    9. Faça um programa que leia 10 números inteiros, armazene-os 
    em um vetor, solicite um valor de referência inteiro e:
    a. imprima os números do vetor que são maiores que o valor referência
    b. retorne quantos números armazenados no vetor são menores que o valor de referência
    c. retorne quantas vezes o valor de referência aparece no vetor
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int inteiros[10];
    int referencia = 0;
    int menorReferencia = 0;
    int qtdRepeticao = 0;

    for (int i = 0; i < 10; i++) {
        inteiros[i] = rand() %35;
    }

    printf("===============================================================================\n");
    printf("Informe um valor de referencia: ");
    scanf("%d", &referencia);
    printf("===============================================================================\n");

    printf("a. Numeros maiores que o valor de referencia: ");
    for (int i = 0; i < 10; i++) {

        if (inteiros[i] > referencia) {
            printf("%d ", inteiros[i]);
        }
        if (inteiros[i] < referencia) {
            menorReferencia += 1;
        }
        if (referencia == inteiros[i]) {
            qtdRepeticao++;
        }

    }
    printf("\nb. Quantidade de numeros menores que o valor de referencia: %d\n", menorReferencia);
    printf("c. Quantidade de vezes que o valor de referencia aparece no vetor: %d\n", qtdRepeticao);
    printf("===============================================================================\n");

    return 0;
}