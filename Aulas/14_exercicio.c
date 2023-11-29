//Metodo de Ordenação Sofisticado Selection Sort

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 1000

void selectionSort(int *v);
void gerarDadosInteiros(int *v);
void mostrarArrayOrdenado(int *v);

int main() {
    int v[1000];

    gerarDadosInteiros(v);
    selectionSort(v);
    // mostrarArrayOrdenado(v);

    return 0;
}

void gerarDadosInteiros(int *v) {
    int i;
    for (i = 0; i < TAMANHO; i++) {
        v[i] = rand() % 9999;
    }
}

void selectionSort(int *v) {
    int i, j, menor, troca;
    int cont = 0;

    for (i = 0; i < TAMANHO-1; i++) {
        menor = i;
        for (j = i+1; j < TAMANHO; j++) {
            cont++;
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        if (i != menor) {
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
    printf("\nSelection sort 1 (interacoes): %d", cont);
}

void mostrarArrayOrdenado(int *v) {
    printf("\n===========ARRAY ORDENADO===========\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", v[i]);
    }
}