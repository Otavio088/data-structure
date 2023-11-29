/*
    1. Crie um programa que armazene um boletim de um aluno:
        a. Os dados dos alunos armazenados serão RA (matricula) e a média;
        b. Armazene os dados em um vetor de 40 posições;
        c. Gere os dados aleatórios ou por input do usuário;
        d. Crie uma função para mostrar os dados do vetor;
        e. Ordene o vetor por ordem de notas;
        f. mostre novamente o vetor.
*/

#include <stdio.h>
#include <stdlib.h>

#define N 40

struct aluno {
    int RA;
    float media; 
};
typedef struct aluno Aluno;

void exibeAlunos(Aluno boletim[N]);
void ordenacao(Aluno boletim[N]);

int main() {
    Aluno boletim[N];
    int i;

    for (i = 0; i < N; i++) {
        boletim[i].RA = rand() % 100;
        boletim[i].media = rand() % 10;
    }

    exibeAlunos(boletim);

    ordenacao(boletim);

    exibeAlunos(boletim);

    return 0;
}

void exibeAlunos(Aluno boletim[N]) {
    int i;

    printf("\n================================\n");
    printf("=======BOLETIM DOS ALUNOS=======\n");
    printf("================================\n");
    printf("\tCODIGO\tMEDIA\n");
    printf("--------------------------------\n");
    for (i = 0; i < N; i++) {
        printf("\t%d\t%0.2f\n", boletim[i].RA, boletim[i].media);
    }   
    printf("--------------------------------\n");
}

void ordenacao(Aluno boletim[N]) {
    int i, j, menor = 0;
    Aluno troca;

    for (i = 0; i < N-1; i++) {
        menor = i;

        for (j = i+1; j < N; j++) {
            if (boletim[j].media < boletim[menor].media) {
                menor = j;
            }
        }

        if (i != menor) {
            troca = boletim[i];
            boletim[i] = boletim[menor];
            boletim[menor] = troca;
        }
    }
}