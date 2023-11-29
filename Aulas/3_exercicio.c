/*
    Crie um programa em C que permita ao usuário realizar 
    apostas na mega sena. As apostas são de 10 números.
    Depois de coletar a aposta, gere um vetor de 6 números,
    gerados aleatóriamente até 60 e verifique quantos números
    foram sorteados com acertos.
    Exiba, ao final, ambos os dados: aposta e sorteados.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int aposta[10];
    int resultado[6];

    printf("--------------------\n");
    printf("      MEGA SENA     \n");
    printf("--------------------\n");

    for (int i = 0; i < 10; i++) {
        printf("Digite um valor de aposta: ");
        scanf("%d", &aposta[i]); //coleta a aposta do usuário (10 números)
    }

    for (int i = 0; i < 6; i++) {
        resultado[i] = rand() % 60; //valores da aposta gerados aleatóriamente
    }

    printf("--------------------\n");

    printf("Valores Oficiais: ");
    for (int i = 0; i < 6; i++) { 
        printf("%d ", resultado[i]);
    }
    
    printf("\nValores de Aposta: ");
    for (int i = 0; i < 10; i++) { 
        printf("%d ", aposta[i]);
    }

    printf("\nValores Sorteados: ");
    for (int i = 0; i < 10; i++) {
        for(int j = 0; j < 6; j++) {
            if(resultado[j] == aposta[i]) {  //verifica quantos números foram sorteados.
                printf("%d ", resultado[j]);
            }
        }
    }
    printf("\n--------------------");

    return 0;
}