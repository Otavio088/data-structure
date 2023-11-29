/*
    2. Faça um programa que armazene 8 números em
    um vetor e imprima todos os números. Ao final, 
    imprima o total de números múltiplos de seis.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int v[8];

    for (int i = 0; i < 8; i++) {
        v[i] = rand() %60;
    }

    printf("=====================================\n");

    printf("V[8]: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", v[i]);
    }

    printf("\n=====================================\n");

    printf("Multiplos de 6: ");
    for (int i = 0; i < 8; i++) {
        if (v[i]%6 == 0) {
            printf("%d ", v[i]);
        }
    }

    printf("\n=====================================\n");

    return 0;
}