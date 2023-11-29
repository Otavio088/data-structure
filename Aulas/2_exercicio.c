/*
    Crie um vetor A de 10 elementos, e preencha-os:
    a) mostre elementos do vetor A;
    b) mostre elementos em ordem inversa;
    c) declare um segundo vetor B de elementos de mesmo tamanho e preencha-o;
    d) crie um vetor C que receba a soma de A + B;
    e) mostre, lado a lado, cada vetor.
    Exemplo:  A  B  C
              4  2  6
              3  5  7
*/

#include <stdio.h>
#include <stdlib.h> //Essa biblioteca permite gerar números aleatórios.

int main() {
    int a[10]; //Vetor A de 10 elementos.
    int b[10]; //Vetor B de elementos de mesmo tamanho.
    int c[10]; //Vetor C de elementos de mesmo tamanho.

    printf("-------------------\n");
    for (int i = 0; i < 10; i++) {
        a[i] = rand() % 8; //preenche vetor A.
        b[i] = rand() % 8; //preenche vetor B.
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);  //mostra elementos do vetor A.
    }

    printf("\n");

    for (int i = 9; i >= 0; i--) {
        printf("%d ", a[i]); //mostra elementos do vetor A na ordem inversa.
    }

    printf("\n-------------------");

    for (int i = 0; i < 10; i++) {
        c[i] = (a[i] + b[i]); //recebe a soma de A + B;
    }

    printf("\nA  B  C");
    printf("\n-------");
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%d  %d  %d", a[i], b[i], c[i]);
        printf("\n");
    }

    printf("-------------------");

    return 0;
}