/*
    6. Crie um programa que gere dois vetores de 20 posições,
    A e B, com números aleatórios entre 0 e 50. Crie um vetor 
    C com os elementos únicos (sem repetição) dos vetores A e B,
    ordenado de forma crescente.
*/

#include <stdio.h>
#include <stdlib.h>

int tamanhoVetorC(int A[20], int B[20]);
void atribuicaoC(int A[20], int B[20], int C[], int T);
void ordenacaoC(int C[], int T);

int main() {
    int A[20], B[20];

    for (int i = 0; i < 20; i++) {
        A[i] = rand() % 51;
        B[i] = rand() % 51;
    }

    printf("\n---------------------------------------------------------------------");
    printf("\nA: ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", A[i]);
    }

    printf("\nB: ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", B[i]);
    }
    printf("\n---------------------------------------------------------------------");

    int tamanhoC = tamanhoVetorC(A, B); //essa função vai definir o tamanho que o vetor C precisa ter para armazenar os valores unicos de A e B.

    int C[tamanhoC];

    atribuicaoC(A, B, C, tamanhoC);

    ordenacaoC(C, tamanhoC);

    printf("\nC: ");
    for (int i = 0; i < tamanhoC; i++){
        printf("%d ", C[i]);
    }
    printf("\n---------------------------------------------------------------------");

    return 0;
}

int tamanhoVetorC(int A[20], int B[20]) {
    int cont;
    int teste;
    int tamanhoC = 0;
    for (int i = 0; i < 20; i++) {
        //vai buscar a quantidade de elementos repetidos para depois selecionar a quantidade de elementos unicos no mesmo vetor.
        cont = 0;
        teste = 0;
        for (int j = 0; j < 20; j++) { 
            if ((A[i] == A[j]) && (i != j)) {
                cont++;
            }
        }
        teste += (20 - cont);
        if (teste == 20) { //igual a 20 quer dizer que não repete.
            cont = 0;
            teste = 0;
            for (int j = 0; j < 20; j++) {
                if (A[i] == B[j]) {
                    cont++;
                }
            }
            teste += (20 - cont);
            if (teste == 20) { //igual a 20 quer dizer que não repete no outro vetor.
                tamanhoC++;
            }
        }
        //vai buscar a quantidade de elementos repetidos para depois selecionar a quantidade de elementos unicos no mesmo vetor.
        cont = 0;
        teste = 0;
        for (int j = 0; j < 20; j++) {
            if ((B[i] == B[j]) && (i != j)) {
                cont++;
            }
        }
        teste += (20 - cont);
        if (teste == 20) { //igual a 20 quer dizer que não repete.
            cont = 0;
            teste = 0;
            for (int j = 0; j < 20; j++) {
                if (B[i] == A[j]) {
                    cont++;
                }
            }
            teste += (20 - cont);
            if (teste == 20) { //igual a 20 quer dizer que não repete no outro vetor.
                tamanhoC++;
            }
        }

    }

    return tamanhoC; 
}

void atribuicaoC(int A[20], int B[20], int C[], int T) {
    int cont;
    int teste;
    int Controle = 0;
    for (int i = 0; i < 20; i++) {
        //vai buscar a quantidade de elementos repetidos para depois selecionar a quantidade de elementos unicos no mesmo vetor.
        cont = 0;
        teste = 0;
        for (int j = 0; j < 20; j++) { 
            if ((A[i] == A[j]) && (i != j)) {
                cont++;
            }
        }
        teste += (20 - cont);
        if (teste == 20) { //igual a 20 quer dizer que não repete.
            cont = 0;
            teste = 0;
            for (int j = 0; j < 20; j++) {
                if (A[i] == B[j]) {
                    cont++;
                }
            }
            teste += (20 - cont);
            if (teste == 20) { //igual a 20 quer dizer que não repete no outro vetor.
                C[Controle] = A[i];
                Controle++;
            }
        }
        //vai buscar a quantidade de elementos repetidos para depois selecionar a quantidade de elementos unicos no mesmo vetor.
        cont = 0;
        teste = 0;
        for (int j = 0; j < 20; j++) {
            if ((B[i] == B[j]) && (i != j)) {
                cont++;
            }
        }
        teste += (20 - cont);
        if (teste == 20) { //igual a 20 quer dizer que não repete.
            cont = 0;
            teste = 0;
            for (int j = 0; j < 20; j++) {
                if (B[i] == A[j]) {
                    cont++;
                }
            }
            teste += (20 - cont);
            if (teste == 20) { //igual a 20 quer dizer que não repete no outro vetor.
                C[Controle] = B[i];
                Controle++;
            }
        }

    }
}

void ordenacaoC(int C[], int T) {
    int i, j, menor, troca;

    for (i = 0; i < T-1; i++) {
        menor = i;
        for (j = i+1; j < T; j++) {
            if (C[j] < C[menor]) {
                menor = j;
            }
        }
        if (i != menor) {
            troca = C[i];
            C[i] = C[menor];
            C[menor] = troca;
        }
    }
    
}