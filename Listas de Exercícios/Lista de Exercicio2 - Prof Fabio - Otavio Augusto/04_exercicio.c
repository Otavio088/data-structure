/*
    4. Crie um programa que gere 20 números aleatórios, 
    armazene em um vetor, e os exiba em ordem inversa.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int v[20];

    for (int i = 0; i < 20; i++) {
        v[i] = rand() % 100;
    }

    printf("-----------------------------------------------------------\n");
    printf("Vetor normal: \n");
    for (int i = 0; i < 20; i++) {
        printf ("%d ", v[i]);
    }
    printf("\n-----------------------------------------------------------\n");
    printf("Vetor inverso: \n");
    for (int i = 19; i >= 0; i--) {
        printf ("%d ", v[i]);
    }
    printf("\n-----------------------------------------------------------\n");

    return 0;
}