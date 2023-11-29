/*
    6.	Construa um programa que armazene o código, a 
    quantidade, o valor de compra e o valor de venda 
    de 30 produtos. A listagem pode ser de todos os 
    produtos ou somente de um ao se digitar o código.
*/

#include <stdio.h>
#include <stdlib.h>

struct produto {
    int codigo;
    int quantidade;
    float valorCompra;
    float valorVenda;
};

typedef struct produto Produto;

int main() {
    Produto prod[30];

    printf("======================================\n");
    printf("=        LISTAGEM DE PRODUTOS        =\n");
    printf("======================================\n");

    for (int i = 0; i < 30; i++) {
        printf("Codigo do Produto: ");
        scanf("%d", &prod[i].codigo);
        printf("Quantidade de Produtos: ");
        scanf("%d", &prod[i].quantidade);
        printf("Valor de Compra: ");
        scanf("%f", &prod[i].valorCompra);
        printf("Valor de Venda: ");
        scanf("%f", &prod[i].valorVenda);
        printf("--------------------------\n");
    }

    system("cls");

    printf("========================================================\n");
    printf("=                  LISTA DE PRODUTOS                   =\n");
    printf("========================================================\n");

    printf(" Codigo     Quantidade     Valor Compra     Valor Venda \n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < 30; i++) {
        printf("  %d            %d           %0.2f         %0.2f \n", prod[i].codigo, prod[i].quantidade, prod[i].valorCompra, prod[i].valorVenda);
    }
    printf("--------------------------------------------------------\n");

    return 0;
}