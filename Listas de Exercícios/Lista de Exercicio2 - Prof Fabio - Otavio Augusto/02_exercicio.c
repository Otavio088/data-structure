/*
    2. Gere um vetor W de 100 posições de valores inteiros, 
    gerados de modo randômico entre 0 e 1000, verifique e 
    exiba, os números primos contidos no vetor W.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int W[100];

    for (int i = 0; i < 100; i++) {
        W[i] = rand() %1000;
    }

    int cont;
    printf("Numeros primos do vetor: ");
    for (int i = 0; i < 100; i++) {
        cont = 0;
        for (int j = 1; j <= W[i]; j++) {
            if (W[i]%j == 0) {
                cont++;
            }
        }
        if (cont == 2) {
            printf("%d ", W[i]);
        }
    }

    return 0;
}