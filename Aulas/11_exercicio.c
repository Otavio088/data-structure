//Busca sequencial ordenada:

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 100

void gerarNumerosInteiros(int *v);
void ordenarVetor(int *v);
void mostrarArrayOrdenado(int *v);
int buscaSequencialOrdenada (int *v, int chave);

int main() {
    int vetor[TAMANHO];
    int busca;

    gerarNumerosInteiros(vetor);
    ordenarVetor(vetor);
    mostrarArrayOrdenado(vetor);

    printf("\nDigite o valor de busca: ");
    scanf("%d", &busca);
    printf("====================================\n");

    int resultadoOrd = buscaSequencialOrdenada(vetor, busca);

    printf("Resultado Ordenado: %d\n", resultadoOrd);
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
        for (int i = 0; i < TAMANHO-1; i++) { //O "-1" é porque não tem como comparar a ultima posicao do vetor com "o da sua frente"
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

int buscaSequencialOrdenada (int *v, int chave) {
    int i;
    for (i = 0; i < TAMANHO; i++) {
        if (chave == v[i]) {
            printf("Interacoes: %d\n", i + 1);
            return i;
        } else if (chave < v[i]) { //se comparar o valor de busca(chave), e o mesmo for menor que o valor de determinada posição do vetor, quer dizer que não vai estar mais para a frente, visto que a lista está ordenada.
                printf("Interacoes: %d\n", i + 1);
                return -1;
        }
    }
    printf("Interacoes: %d\n", i + 1);
    return -1;
}