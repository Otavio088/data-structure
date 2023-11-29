/*
    7. Crie um programa gerador de tabuada, o usuário deverá 
    informar o número do qual deseja a tabuada e a saída 
    esperada deverá ser:
    ----------------------------------------
    Digite um número para geração da tabuada: 3
    Tabuada do 3:
    Soma:
    3 + 0 = 3
    3 + 1 = 4
    3 + 2 = 5
    . . .
    3 + 10 = 13
    Multiplicação:
    3 x 0 = 0
    3 x 1 = 3
    . . .
    3 x 10 = 30
    ----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0;

    printf("\nDigite um numero para geracao da tabuada: ");
    scanf("%d", &n);

    printf("\n--------------------------------------------------------");
    printf("\n                 TABUADA DE %d: ", n                     );
    printf("\n--------------------------------------------------------");
    printf("\nSoma: ");
    for (int i = 0; i <= 10; i++) {
        printf("\n%d + %d = %d", n, i, n+i);
    }
    printf("\n--------------------------------------------------------");
    printf("\nMultiplicacao: ");
    for (int i = 0; i <= 10; i++) {
        printf("\n%d x %d = %d", n, i, n*i);
    }
    printf("\n--------------------------------------------------------");

    return 0;
}