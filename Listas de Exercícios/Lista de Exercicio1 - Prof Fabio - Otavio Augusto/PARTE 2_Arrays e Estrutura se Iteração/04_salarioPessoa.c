/*
    4.	Construa um programa que permita armazenar 
    o salário de 20 pessoas. Calcular e armazenar o 
    novo salário sabendo-se que o reajuste foi de 8%.
    Imprimir uma listagem numerada com o salário e o
    novo salário. Declare quantos vetores forem necessários.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    float salario[20];
    float novoSalario[20]; 

    int j = 1;
    for (int i = 0; i < 20; i++) {
        printf("Digite o %do salario: ", j);
        scanf("%f", &salario[i]);

        novoSalario[i] = (salario[i] + (0.08*salario[i])); 

        j++;
    }

    system("cls");
    
    printf("======================================\n");
    printf("= Salario               Novo Salario =\n");
    printf("======================================\n");
    for (int i = 0; i < 20; i++) {
        printf("   %0.2f                  %0.2f\n", salario[i], novoSalario[i]);
    }
    printf("======================================\n");

    return 0;
}