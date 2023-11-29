/*
    9. [ex ℼ.r] Um vetor J contém 100 valores referente 
    a aferições de medidas de um sistema. Como os valores 
    têm variações adversas faz-se necessário conhecer o 
    desvio padrão.             n   
    𝑑𝑒𝑠𝑣𝑖𝑜 𝑝𝑎𝑑𝑟ã𝑜 =  sqrt(1/n-1 ∑ (v[i] - m)^2)
                              i=1
    Onde m é a média dos valores de J.
    A raiz quadrada é calculada pela função sqrt(), 
    para tanto utilize a biblioteca <math.h>
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100

float media(int J[N]);

int main() {
    int J[N];
    float D = 0; //Desvio Padrão.
    int somatorio = 0;

    for (int i = 0; i < N; i++) {
        J[i] = rand() % 2000;
    }

    float m = media(J);

    for (int i = 0; i < N; i++) {
        somatorio += (pow(J[i] - m, 2));
    }

    D = sqrt(somatorio/(N-1)); 

    printf("Desvio padrao: %0.2f", D);

    return 0;
}

float media(int J[N]) {
    int acumulador = 0;

    for (int i = 0; i < N; i++) {
        acumulador += J[i];
    }
    return acumulador/N;
}