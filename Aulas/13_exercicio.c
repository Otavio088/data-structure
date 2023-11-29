//Metodo de Ordenação Basico Bubble Sort

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 1000

// void bubbleSort1(int *v);
void bubbleSortAteOrdenar(int *v);
void gerarDadosInteiros(int *v);

int main() {
    int v[1000];

    gerarDadosInteiros(v);
    // bubbleSort1(v);
    bubbleSortAteOrdenar(v);

    return 0;
}

void gerarDadosInteiros(int *v) {
    int i;
    for (i = 0; i < TAMANHO; i++) {
        v[i] = rand() % 9999;
    }
}

// void bubbleSort1(int *v) {
//     int i, k;
//     int cont = 0;
//     for (k = 0; k < TAMANHO; k++) {
//         for (i = 0; i < TAMANHO-1; i++) {
//             cont++;
//             if (v[i] > v[i+1]) {
//                 int temp = v[i];
//                 v[i] = v[i+1];
//                 v[i+1] = temp;
//             }
//         }
//     }
//     printf("\nBubble sort 1 (interacoes): %d", cont);
// }

void bubbleSortAteOrdenar(int *v) {
    int i;
    int cont = 0;
    int ordenado = 0; //0 = não ordenado, 1 = ordenado.
    while (ordenado == 0) {
        ordenado = 1;
        for (i = 0; i < TAMANHO-1; i++) {
            cont++;
            if (v[i] > v[i+1]) {
                ordenado = 0;
                int temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
            }
        }
    }
    printf("\nBubble sort 1 (interacoes): %d", cont);
}