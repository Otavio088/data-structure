/*
    Forma uma Fila de codigos com no maximo 11 codigos na fila.
*/

#include <stdio.h>
#include <stdlib.h>

#define N 11

struct fila {
    int inicio, final;
    int tamanho[N];
};
typedef struct fila Fila;

Fila* criarFila();
int filaCheia(Fila* fila);
int filaVazia(Fila* fila);
int push(Fila* fila, int codigo);
int pop(Fila* fila);
void imprimeFila(Fila* fila);

int main() {
    Fila* fila = criarFila();
    int x, r = 0;

    while (r != 3) {

        imprimeFila(fila);
        
        printf("[1] Inserir na fila\n");
        printf("[2] Remover da fila\n");
        printf("[3] Sair\n");
        printf("-------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &r);
        system("cls");

        switch (r){
            case 1:
                imprimeFila(fila);
                printf("codigo para fila: ");
                scanf("%d", &x);
                system("cls");
                push(fila, x);
            break;
            case 2:
                pop(fila);
                printf("Primeiro elemento removido!\n");
            break;
            case 3:
                printf("Programa finalizado!\n");
                return 0;
            break;
            default:
                printf("Valor invalido!\n");
            break;
        }
    }

    return 0;
}

Fila* criarFila() {
    Fila* fila = (Fila*) malloc(sizeof(Fila));

    if (fila != NULL) {
        fila->inicio = 0;
        fila->final = 0;
    }

    return fila;
}

int filaCheia(Fila* fila) {
    if (fila == NULL) {
        return -1;
    }
    
    if (fila->inicio == (fila->final + 1) % N) {
        return 1;
    } else {
        return 0;
    }
}

int filaVazia(Fila* fila) {
    if (fila == NULL) {
        return -1;
    }
    
    if (fila->inicio == fila->final) {
        printf("Fila vazia!\n");
        return 1;
    }

    return 0;
}

int push(Fila* fila, int codigo) {
    if (fila == NULL) {
        printf("Fila inexistente!");
        return 0;
    }

    if (filaCheia(fila)) {
        printf("Fila cheia!\n");
        return 0;
    }

    fila->tamanho[fila->final] = codigo;
    fila->final = (fila->final + 1) % N;

    return 1;
}

int pop(Fila* fila) {
    if (fila == NULL || filaVazia(fila)) {
        return 0;
    }

    fila->inicio = (fila->inicio + 1) % N;

    return 1;
}

void imprimeFila(Fila* fila) {
    if (fila == NULL) {
        return 0;
    }

    int i = fila->inicio;

    printf("\n-------------------------\n");
    printf("FILA: ");
    while (i != fila->final) {
        printf("%d ", fila->tamanho[i]);
        i = (i + 1) % N;
    }
    printf("\n-------------------------\n");
}
