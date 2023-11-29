/*
    10.	Leia duas matrizes 2x3 de números double. 
    Imprima a soma destas duas matrizes.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    double m1[2][3];
    double m2[2][3];
    double mSoma[2][3];

    for(int l = 0; l < 2; l++) {
        for (int c = 0; c < 3; c++) {
            m1[l][c] = rand() % 200/10.0;
            m2[l][c] = rand() % 200/10.0;
            mSoma[l][c] = (m1[l][c] + m2[l][c]);
        }
    }

    printf("-------------------------------\n");
    printf("    Soma das duas Matrizes     \n");
    printf("-------------------------------");
    for(int l = 0; l < 2; l++) {
        printf("\n");
        for (int c = 0; c < 3; c++) {
            printf("   %0.2lf  ", mSoma[l][c]);
        }
    }

    printf("\n\n-------------------------------\n");
    printf("        Primeira Matriz        \n");
    printf("-------------------------------");
    for(int l = 0; l < 2; l++) {
        printf("\n");
        for (int c = 0; c < 3; c++) {
            printf("   %0.2lf  ", m1[l][c]);
        }
    }

    printf("\n\n-------------------------------\n");
    printf("        Segunda Matriz         \n");
    printf("-------------------------------");
    for(int l = 0; l < 2; l++) {
        printf("\n");
        for (int c = 0; c < 3; c++) {
            printf("   %0.2lf  ", m2[l][c]);
        }
    }
    printf("\n-------------------------------\n");

    return 0;
}