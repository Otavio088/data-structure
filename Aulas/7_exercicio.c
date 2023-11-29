/*
    Crie uma função que troque o valor de dois números
    inteiros passados por referência.
*/

#include <stdio.h>
#include <stdlib.h>

void trocaValor(int *a, int *b);

int main() {
    int n1 = 10;
    int n2 = 20;

    printf("====================================\n");
    printf("Antes da alteracao: %d, %d\n", n1, n2);

    trocaValor(&n1, &n2);

    printf("Depois da alteracao: %d, %d\n", n1, n2);
    printf("====================================\n");

    return 0;
}

void trocaValor(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}