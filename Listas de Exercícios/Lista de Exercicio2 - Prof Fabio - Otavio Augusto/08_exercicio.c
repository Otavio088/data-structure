/*
    8. Crie um programa que gere 2 vetores, W e J, 
    de 100 posições, gere valores randômicos entre
    0 e 100 e calcule e retorne t, onde:

    𝑡 = 𝑚𝑎𝑥(𝑊) * [𝑚𝑖𝑛(𝐽) + 1]
       ------------------------
        𝑚𝑒𝑑𝑖𝑎(𝑊) + 𝑚𝑒𝑑𝑖𝑎(𝐽)
*/

#include <stdio.h>
#include <stdlib.h>

int max(int W[100]); //acredito que seja para achar o maior valor do array, já que nao foi especificado.
int min(int J[100]); //acredito que seja para achar o menor valor do array, já que nao foi especificado.
float media(int W[100]);

int main() {
    int W[100], J[100];
    float t = 0;

    for (int i = 0; i < 100; i++) {
        W[i] = rand() % 101;
        J[i] = rand() % 101;
    }

    t = (max(W) * (min(J) + 1)) / (media(W) + media(J));

    printf("\nResposta: %0.2f", t);

    return 0;
}

int max(int W[100]) {
    int maior = 0;

    for (int i = 0; i < 100; i++) {
        if (maior < W[i]) {
            maior = W[i];
        }
    }

    return maior;
}

int min(int J[100]){
    int menor = J[0];

    for (int i = 0; i < 100; i++) {
        if (menor > J[i]) {
            menor = J[i];
        }
    }

    return menor;
}

float media(int W[100]) {
    int acumulador = 0;

    for (int i = 0; i < 100; i++) {
        acumulador += W[i];
    }
    return acumulador/100;
}