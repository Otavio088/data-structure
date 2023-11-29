/*
    12.	Escreva um programa que preencha, com valores 
    aleatórios até 1000, de uma matriz 10 × 10. Em seguida, 
    mostra o índice da linha e o índice da coluna e o 
    valor das posições não nulas.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    float m[10][10];

    for (int l = 0; l < 10; l++) {
        for (int c = 0; c < 10; c++) {
            m[l][c] = rand() % 1000;
        }
    }

    for (int c = 0; c < 10; c++) {
        printf("       %d", c);
    }
    printf("\n    ------------------------------------------------------------------------------");

    for (int l = 0; l < 10; l++) {
        printf("\n");
        printf("%d | ", l);
        for (int c = 0; c < 10; c++) {
            if (m[l][c] != 0) {
                printf ("%0.2f  ", m[l][c]);
            } else {
                printf("         ");
            }
        }
    }

    return 0;
}