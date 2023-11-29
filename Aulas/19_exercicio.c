//Aprendendo Fila Estática

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct aluno {
    int matricula;
    float n1, n2, n3;
};
typedef struct aluno Aluno;

struct fila {
    int inicio;
    int final;
    Aluno dados[MAX];
};
typedef struct fila Fila;

Fila* criarFila();
int inserirFila(Fila *fila, Aluno novoAluno);
int removerFila(Fila *fila);
int filaVazia(Fila *fila);
int filaCheia(Fila *fila);
int tamanhoFila(Fila *fila);
void imprimirFila(Fila *fila);

int main() {
    Fila *fila = criarFila();

    Aluno aluno1 = {10, 8.5, 9.9, 8.0};
    Aluno aluno2 = {20, 6.2, 8.5, 8.8};
    Aluno aluno3 = {30, 7.8, 8.5, 10.0};
    Aluno aluno4 = {40, 5.8, 8.0, 8.9};

    inserirFila(fila, aluno1);
    inserirFila(fila, aluno2);
    inserirFila(fila, aluno3);
    inserirFila(fila, aluno4);

    imprimirFila(fila);

    removerFila(fila);

    imprimirFila(fila);

    return 0;
}

Fila* criarFila() {
    Fila *fila = (Fila*) malloc(sizeof(Fila));

    if (fila != NULL) {
        fila->inicio = 0;
        fila->final = 0;
    }

    return fila;
}

int inserirFila(Fila *fila, Aluno novoAluno) {
    if (fila == NULL) {
        printf("Fila nao existe!\n");
        return 0;
    }

    if (filaCheia(fila)) {
        printf("Fila cheia!\n");
        return 0;
    } 

    fila->dados[fila->final] = novoAluno;
    fila->final = (fila->final + 1) % MAX;

    return 1;
}

int removerFila(Fila *fila) {
    if (fila == NULL || filaVazia(fila)) {
        return 0;
    }

    fila->inicio = (fila->inicio + 1) % MAX;

    return 1;
}

int filaVazia(Fila *fila) {
    if (fila == NULL) {
        return -1;
    }

    return (fila->inicio == fila->final); //retorna 1 (true) ou 0 (false)
}

int filaCheia(Fila *fila) {
    if (fila == NULL) {
        return -1; //lista inválida, retorna -1
    }

    if (fila->inicio == (fila->final + 1) % MAX) {
        return 1; //fila cheia.
    } else {
        return 0; //fila vazia.
    }
}

int tamanhoFila(Fila *fila) {
    if (fila == NULL) {
        return -1; //fila inválida, retorna tamanho dela -1
    }

    int tamanho = abs(fila->final - fila->inicio); //função abs é o modulo da função f(x) = |x|

    return tamanho;
}

void imprimirFila(Fila *fila) {
    if (fila == NULL) {
        printf("Fila não existe!\n");
        return 0;
    }

    int i = fila->inicio;

    printf("\n----------Elementos da fila-----------");
    printf("\nMatricula\tNota1\tNota2\tNota3");
    printf("\n--------------------------------------");

    while (i != fila->final) {
        printf("\n%d", fila->dados[i].matricula);
        printf("\t\t%0.2f", fila->dados[i].n1);
        printf("\t%0.2f", fila->dados[i].n2);
        printf("\t%0.2f", fila->dados[i].n3);

        i = (i + 1) % MAX;
    }

    printf("\n--------------------------------------");
}
