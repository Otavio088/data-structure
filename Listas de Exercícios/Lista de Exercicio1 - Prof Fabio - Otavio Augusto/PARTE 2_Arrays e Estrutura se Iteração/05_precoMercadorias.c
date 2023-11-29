/*
    5. Crie um programa que leia o preço de compra 
    e o preço de venda de 100 mercadorias (utilize 
    vetores). Ao final, o programa deverá imprimir 
    quantas mercadorias proporcionam:

    a.	lucro < 10%
    b.	10% <= lucro <= 20%
    c.	lucro > 20%
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    float precoCompra[100];
    float precoVenda[100];

    int menor10 = 0;
    int entre10e20 =0;
    int maior20 = 0;

    printf("====================================================\n");
    printf("=                ANALISADOR DE LUCROS              =\n");
    printf("====================================================\n");
    for (int i = 0; i < 100; i++) {
        printf("Preco de compra: ");
        scanf("%f", &precoCompra[i]);
        printf("Preco de venda: ");
        scanf("%f", &precoVenda[i]);
        printf("-------------------");
    }

    system("cls");

    for (int i = 0; i < 100; i++) {

        if ((precoVenda[i] - precoCompra[i]) < (0.01 * precoCompra[i])) {
            menor10 += 1;
        } else if ((precoVenda[i] - precoCompra[i]) >= (0.01 * precoCompra[i]) && (precoVenda[i] - precoCompra[i]) <= (0.02 * precoCompra[i])) {
            entre10e20 += 1;
        } else {
            maior20 += 1;
        }

    }

    printf("====================================================\n");
    printf("a) Mercadorias com lucro menor que 10%%: %d\n", menor10);
    printf("b) Mercadorias com lucro entre 10%% e 20%%: %d\n", entre10e20);
    printf("c) Mercadorias com lucro maior que 20%%: %d\n", maior20);
    printf("====================================================\n");

    return 0;
}