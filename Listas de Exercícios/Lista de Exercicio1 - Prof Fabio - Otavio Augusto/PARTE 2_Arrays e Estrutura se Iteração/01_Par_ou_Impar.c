/*
    1. Construa uma programa em C que armazene
    15 números em um vetor e imprima uma listagem 
    numerada contendo o número e uma das mensagens: 
    par ou ímpar.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int v[15];

    for (int i = 0; i < 15; i++) {
        v[i] = rand() %60;
    }

    printf("=========================================\n");
    printf("=           LISTAGEM DO VETOR           =\n");
    printf("=========================================\n");
    for (int i = 0; i < 15; i++) {
        if (v[i]%2 == 0) {
            printf("v[%d] = %d (par)\n", i, v[i]);
        } else {
            printf("v[%d] = %d (impar)\n", i, v[i]);
        }
    }
    printf("=========================================\n");

    return 0;
}