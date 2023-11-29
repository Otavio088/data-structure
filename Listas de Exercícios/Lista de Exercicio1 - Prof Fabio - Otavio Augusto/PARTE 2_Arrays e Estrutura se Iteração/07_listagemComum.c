/*
    7.	Faça um programa em C que leia dois 
    conjuntos de números inteiros, tendo cada 
    um 10 elementos. Ao final o programa deve 
    listar os elementos comuns aos conjuntos.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int numerosInt[10];
    int numerosInt2[10];

    for (int i = 0; i < 10; i++) {
        numerosInt[i] = rand() %20;
        numerosInt2[i] = rand() %20;
    }

    printf("-------------------------------------------------------\n");
    printf("Elementos em comum entre os dois conjuntos: ");
    for (int i = 0; i < 10; i++) {

        for (int j = 0; j < 10; j++) {

            if (numerosInt[i] == numerosInt2[j]) {
                printf("%d ", numerosInt[i]);
            }
            
        }

    }

    printf("\n-------------------------------------------------------\n");
    printf("Primeiro conjunto de numeros: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numerosInt[i]);
    }
    
    printf("\nSegundo conjunto de numeros: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numerosInt2[i]);
    }
    printf("\n-------------------------------------------------------\n");

    return 0;
}