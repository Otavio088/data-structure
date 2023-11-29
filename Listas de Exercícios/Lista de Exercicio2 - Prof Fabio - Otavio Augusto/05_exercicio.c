/*
    5. Crie um programa que gere 2 vetores de 10 posições, 
    w e k, aleatórios ou informados pelo usuário, e calcule:
    9
    ∑ (𝑤[𝑖] + 𝑘[9 − 𝑖])
    𝑖=𝑜
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int w[10], k[10];   
    int somatorio = 0;

    for (int i = 0; i < 10; i++) {
        w[i] = rand() % 30;
        k[i] = rand() % 30;
    } 

    for (int i = 0; i < 10; i++) {
        somatorio += (w[i] + k[9 - i]);
    }

    printf("%d", somatorio);

    return 0;
}