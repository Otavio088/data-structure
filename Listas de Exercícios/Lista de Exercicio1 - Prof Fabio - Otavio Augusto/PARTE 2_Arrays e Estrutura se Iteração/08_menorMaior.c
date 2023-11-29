/*
    8. Construa um programa que leia dados para 
    um vetor de 100 elementos inteiros. Imprimir 
    o maior e o menor, sem ordenar, o percentual 
    de números pares e a média dos elementos do vetor.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int v[100];

    for (int i = 0; i < 100; i++) {
        v[i] = rand() %200;
    }

    int maiorValor = 0;
    int menorValor = v[0];
    float percPares = 0;
    float media = 0;
    for (int i = 0; i < 100; i++) {

        if (maiorValor < v[i]) {
            maiorValor = v[i];
        }

        if (menorValor > v[i]) {
            menorValor = v[i];
        }

        if (v[i]%2 == 0) {
            percPares = percPares + 1;
        }

        media += v[i];

    }

    percPares = ((percPares/100)*100);
    media = (media/100);

    printf("===============================================\n");
    printf("Maior valor do vetor: %d\n", maiorValor);
    printf("Menor valor do vetor: %d\n", menorValor);
    printf("Percentual de numeros pares: %0.2f%%\n", percPares);
    printf("Media dos elementos do vetor: %0.2f\n", media);
    printf("===============================================\n");

    return 0;
}