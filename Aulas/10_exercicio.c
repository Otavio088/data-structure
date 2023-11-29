//Busca sequencial linear:

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 100

void gerarNumerosInteiros(int *v);
void mostrarArray(int *v);
int buscaLinear (int *v, int chave);

int main() {
    int vetor[TAMANHO];
    int busca;

    gerarNumerosInteiros(vetor);
    mostrarArray(vetor);

    printf("\nDigite o item de busca: ");
    scanf("%d", &busca);
    printf("====================================\n");

    int resultado = buscaLinear(vetor, busca);

    printf("Resultado Linear: %d\n", resultado);
    printf("====================================\n");

    return 0;
}

void gerarNumerosInteiros(int *v) {
    for (int i = 0; i < TAMANHO; i++) {
        v[i] = rand() % 9999;
    }
}

void mostrarArray(int *v) {
    printf("==========ARRAY DE INTEIRO==========\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", v[i]);
    }
}

int buscaLinear (int *v, int chave) {
    int i;
    for (i = 0; i < TAMANHO; i++) {
        if (v[i] == chave) {
            printf("Interacoes: %d\n", i + 1);
            return i;
        }
    }
    printf("Interacoes: %d\n", i);
    return -1;
}