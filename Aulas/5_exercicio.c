/* 
    Declare uma estrutura capaz de armazenar o número e 3 notas para um dado aluno.
*/

#include <stdio.h>
#include <stdlib.h>

struct aluno {
    char nome[10];
    int num_aluno;
    float nota1, nota2, nota3;
    float media;
};

int main() {
    struct aluno aluno[3];

    printf("=============================\n");
    for(int i = 0; i < 3; i++) {
        printf("Digite seu nome: ");
        scanf("%s", &aluno[i].nome);

        printf("Digite seu numero: ");
        scanf("%d", &aluno[i].num_aluno);

        printf("Digite sua primeira nota: ");
        scanf("%f", &aluno[i].nota1);

        printf("Digite sua segunda nota: ");
        scanf("%f", &aluno[i].nota2);

        printf("Digite sua terceira nota: ");
        scanf("%f", &aluno[i].nota3);

        aluno[i].media = ((aluno[i].nota1 + aluno[i].nota2 + aluno[i].nota3)/3);

        printf("=============================\n");
    }

    for (int i = 0; i < 3; i++) {
        printf("Nome: %s", aluno[i].nome);
        printf("\nNumero: %d", aluno[i].num_aluno);
        printf("\nNota 1: %0.2f", aluno[i].nota1);
        printf("\nNota 2: %0.2f", aluno[i].nota2);
        printf("\nNota 3: %0.2f", aluno[i].nota3);
        printf("\nMedia de %s: %0.2f", aluno[i].nome, aluno[i].media);

        printf("\n=============================\n");
    }

    return 0;
}