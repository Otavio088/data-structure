/*
    2.	Programa: média ponderada.
    Muitos concursos e universidades usam o sistema de média ponderada
    para a formulação da média final dos alunos. Assim, objetivo desse
    programa é a realização desse cálculo de forma automatizada.
    
    Considere três notas de um aluno - a serem informadas pelo usuário, 
    calcule e escreva a média final deste aluno.
    
    Considerar que a média é ponderada e que o peso das notas é 2, 3 e 5,
    respectivamente Fórmula para o cálculo da média final é:

    mediaFinal = (n1*2 + n2*3 + n3*5)/10
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    float n1 = 0;
    float n2 = 0;
    float n3 = 0;
    float mediaFinal = 0;

    printf("===============================\n");
    printf("=       MEDIA PONDERADA       =\n");
    printf("===============================\n");
    printf("Primeira nota: ");
    scanf("%f", &n1);
    printf("Segunda nota: ");
    scanf("%f", &n2);
    printf("Terceira nota: ");
    scanf("%f", &n3);
    printf("==============================\n");

    mediaFinal = ((n1*2 + n2*3 + n3*5)/10);
 
    printf("Media final do aluno: %0.2f\n", mediaFinal);
    printf("==============================\n");
    
    return 0;
}