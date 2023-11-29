/*
    11.	Escreva um programa que inicialize uma 
    matriz 10 × 10 com 0 em todas as posições. 
    O usuário irá digitar o índice da linha e o 
    índice da coluna e em seguida o valor das posições. 
    A leitura será feita enquanto os índices não forem 
    negativos. Após a leitura imprima a matriz na tela.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    float matriz[10][10] = {0};
    int linha = 0;
    int coluna = 0;
    float valorEscolha = 0;

    printf("=========================================================\n");
    printf("=              ADICIONE UM VALOR NA MATRIZ              =\n");
    printf("=========================================================\n");
    do {
        printf("Indice da linha: ");
        scanf("%d", &linha);
        if (linha < 0) {
            printf("O valor nao pode ser negativo!\n");
        }
    } while (linha < 0);

    do {
        printf("Indice da coluna: ");
        scanf("%d", &coluna);
        if (coluna < 0) {
            printf("O valor nao pode ser negativo!\n");
        }
    } while (coluna < 0);
    printf("Valor da posicao: ");
    scanf("%f", &valorEscolha);
    printf("=================================================================\n");
    printf("=                             MATRIZ                            =\n");
    printf("=================================================================");
    for (int l = 0; l < 10; l++) {
        printf("\n");
        printf("%d    ", l);
        for (int c = 0; c < 10; c++) {

            if (l == linha && c == coluna) {
                matriz[l][c] = valorEscolha;
            }
            printf("%0.2f  ", matriz[l][c]);
        }
    }
    printf("\n\n");
    for (int c = 0; c < 10; c++) {
        printf("     %d", c);
    }

    printf("\n=================================================================\n");

    return 0;
}