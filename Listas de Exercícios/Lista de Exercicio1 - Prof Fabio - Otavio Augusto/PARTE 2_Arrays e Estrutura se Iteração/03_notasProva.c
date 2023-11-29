/*
    3. Faça um programa que armazene as notas das
    provas 1 e 2 de 15 alunos.

    a) Calcule e armazene a média.

    b) Armazene também a situação do aluno:
    1-Aprovado ou 2-Reprovado.

    c) Ao final o programa deve imprimir uma listagem
    contendo as notas, a média e a situação de cada 
    aluno em formato tabulado.

    Utilize quantos vetores forem necessários para armazenar os dados.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    float n1[15];
    float n2[15];
    float media[15];
    char situacao[15];

    for (int i = 0; i < 15; i++) {
        n1[i] = rand() % 10;
        n2[i] = rand() % 10;
        media[i] = ((n1[i] + n2[i])/2);

        if (media[i] < 6) {
            situacao[i] = '2'; //Reprovado
        } else {
            situacao[i] = '1'; //Aprovado
        }

    }

    printf("===============================================\n");
    printf("=         ALUNO APROVADO OU REPROVADO         =\n");
    printf("===============================================\n");
    printf("Situacao = 1 Aprovado || Situacao = 2 Reprovado\n");
    printf("===============================================\n");
    printf("= Nota 1      Nota 2      Media      Situacao =\n");
    printf("===============================================\n");
    for (int i = 0; i < 15; i++) {
    printf("  %0.2f        %0.2f        %0.2f        %c\n", n1[i], n2[i], media[i], situacao[i]);
    }
    printf("===============================================\n");

    return 0;
}