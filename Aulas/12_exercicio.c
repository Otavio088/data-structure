//busca binária:

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 100

void gerarNumerosInteiros(int *v);
void ordenarVetor(int *v);
void mostrarArrayOrdenado(int *v);
int buscaBinaria(int *v, int chave);

int main() {
    int vetor[TAMANHO];
    int busca;

    gerarNumerosInteiros(vetor);
    ordenarVetor(vetor);
    mostrarArrayOrdenado(vetor);

    printf("\nDigite o item de busca: ");
    scanf("%d", &busca);
    printf("====================================\n");

    int resultadoBin = buscaBinaria(vetor, busca);

    printf("Resultado por busca Binaria: %d\n", resultadoBin);
    printf("====================================\n");

    return 0;
}


void gerarNumerosInteiros(int *v) {
    for (int i = 0; i < TAMANHO; i++) {
        v[i] = rand() % 9999;
    }
}

void ordenarVetor(int *v) {
    for (int j = 0; j < TAMANHO; j++) {
        for (int i = 0; i < TAMANHO-1; i++) {
            if (v[i+1] < v[i]) {
                int temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
            }
        }
    }
}

void mostrarArrayOrdenado(int *v) {
    printf("\n===========ARRAY ORDENADO===========\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", v[i]);
    }
}

int buscaBinaria(int *v, int chave) {
    int i = 0, inicio = 0, meio = 0, final = TAMANHO-1;

    while (inicio <= final) {
        i++;
        meio = (inicio + final)/2;

        if (chave < v[meio]) {
            final = meio-1;
        } else if (chave > v[meio]) {
                inicio = meio+1;
            } else {
                printf("Interacoes: %d\n", i);
                return meio;
            }
        }
    printf("Interacoes: %d\n", i);
    return -1;
}