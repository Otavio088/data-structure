/*
    1. Faça um programa que leia 10 números inteiros, 
    armazene-os em um vetor, solicite um valor
    de referência inteiro e:
        a. imprima os números do vetor que são maiores
        que o valor referência;
        b. retorne quantos números armazenados no vetor 
        são menores que o valor de referência;
        c. retorne quantas vezes o valor de referência 
        aparece no vetor;
        d. gere um segundo vetor vetor, com 50 posições e:
            i. contabilize quantas vezes, cada número informado 
            pelo usuário, consta no segundo vetor;
            ii. calcule o % de números do vetor de 50 posições 
            que constam no primeiro;
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int v[10];
    int v2[50];
    int referencia = 0;

    int j = 1;
    for (int i = 0; i < 10; i++) {
        printf("Digite o %do valor: ", j);
        scanf("%d", &v[i]);
        j++;
    }

    for (int i = 0; i < 50; i++) {
        v2[i] = rand() % 100;
    }

    system("cls");

    printf("Digite o valor de referencia: ");
    scanf("%d", &referencia);

    system("cls");

    int cont = 0;
    int contRef = 0;
    int contV2 = 0;
    printf("----------------------------------------------------------------------------------------------\n");
    printf("a) Valores maiores que %d: ", referencia);
    for (int i = 0; i < 10; i++) {
        if(v[i] > referencia) {
            printf("%d ", v[i]);
        }
        if(v[i] < referencia) {
            cont++;
        }
        if(v[i] == referencia) {
            contRef++;
        }
        for (j = 0; j < 50; j++) {
            if (v[i] == v2[j]) {
                contV2++;
            }
        }
    }
    printf("\n");
    printf("b) Quantidade de valores menores que %d: %d\n", referencia, cont);
    printf("c) Quantidade de vezes que %d aparece no vetor: %d\n", referencia, contRef);
    printf("d) I.Quantidade de vezes que cada numero informado pelo usuario consta no segundo vetor: %d\n", contV2);

    float porcentagem = contV2*100/50;

    printf("d) II.Porcentagem de numeros do vetor de 50 posicoes que constam no primeiro: %0.2f%%\n", porcentagem);
    printf("----------------------------------------------------------------------------------------------\n");

    return 0;
}