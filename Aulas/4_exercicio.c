/*
    Mostrar valores de uma matriz 4 por 5 e soma das linhas e colunas.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int mat[4][5];
    int somaLinha[4];
    int somaColuna[5];
    int acumuloLinha;
    int acumuloColuna;

    for (int l = 0; l < 4; l++) {
        for (int c = 0; c < 5; c++) {
            // printf("Digite o valor de mat[%d][%d]: ", l, c);
            // scanf("%d", &mat[l][c]);
            mat[l] [c] = rand() %10; //gera valores aleatórios para a Matriz.
        }
    }

    printf("========================\n");
    printf("    MATRIZ ALEATORIA    \n");
    printf("========================\n");
    //mostra matriz e a soma das linhas.
    for (int l = 0; l < 4; l++) {
        acumuloLinha = 0;
        for (int c = 0; c < 5; c++) {
            printf("%d   ",mat[l][c]); 
            acumuloLinha += mat[l][c];
        }
        somaLinha[l] = acumuloLinha; //recebe acumulo de linhas.
        printf("  %d", somaLinha[l]);
        printf("\n"); //pula uma linha após a exibição da primeira linha da matriz.
    }

    printf("\n");
    //soma das colunas.
    for (int c = 0; c < 5; c++) {
        acumuloColuna = 0;
        for (int l = 0; l < 4; l++) {
            acumuloColuna += mat[l][c];
        }
        somaColuna[c] = acumuloColuna; //recebe acumulo de colunas.
        printf("%d  ", somaColuna[c]);
    }
    printf("\n========================\n");

    return 0;
}