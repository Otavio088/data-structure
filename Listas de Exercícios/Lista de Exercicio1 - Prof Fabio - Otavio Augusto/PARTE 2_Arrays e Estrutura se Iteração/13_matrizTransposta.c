/*
    13.	Escreva um programa que leia todos os elementos 
    de uma matriz 4 × 4, em seguida mostre a matriz e 
    constitua sua matriz transposta. Exemplo:
    Matriz:          Transposta:
    | 0 1 0 2 |      | 0 0 0 0 |
    | 0 1 0 2 |      | 1 1 1 1 |
    | 0 1 0 2 |      | 0 0 0 0 |
    | 0 1 0 2 |      | 2 2 2 2 |           
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int m[4][4] = {
        {0, 1, 0, 2},
        {0, 1, 0, 2},
        {0, 1, 0, 2},
        {0, 1, 0, 2}
    };

    printf("--------------------------\n");
    printf("-         MATRIZ         -\n");
    printf("--------------------------");
    for (int l = 0; l < 4; l++) {
        printf("\n");
        printf("     ");
        for (int c = 0; c < 4; c++) {
            printf("  %d", m[l][c]);
        }
    }

    printf("\n--------------------------\n");
    printf("-    MATRIZ TRANSPOSTA   -\n");
    printf("--------------------------");
    for (int c = 0; c < 4; c++) {
        printf("\n");
        printf("     ");
        for (int l = 0; l < 4; l++) {
            printf("  %d", m[l][c]);
        }
    }
    printf("\n--------------------------\n");

    return 0;
}