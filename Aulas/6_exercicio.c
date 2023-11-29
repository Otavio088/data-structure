/*
    Criar um struct chamado venda, com os atributos Valor Unitário e Quantidade.

    Crie uma função que receba os dados da venda e calcule o valor do imposto considerando:
    valor da venda até 500: valor do imposto será de 10%;
    valor de venda acima de 500: valor do imposto será de 15%.
*/
#include <stdio.h>

struct venda {
    float valorUnitario;
    float quantidade;
};

typedef struct venda Venda;

float calculoImposto(Venda valor) {
    float dadosVenda = (valor.valorUnitario * valor.quantidade);
    if (dadosVenda <= 500) {
        return 0.10 * dadosVenda;
    } else {
        return 0.15 * dadosVenda;
    }
}

int main() {
    Venda ven;
    printf("=======================\n");
    printf("Valor de Venda: ");
    scanf("%f", &ven.valorUnitario);
    printf("Quantidade de Vendas: ");
    scanf("%f", &ven.quantidade);
    printf("=======================\n");

    float imposto = calculoImposto(ven);

    printf("Valor total: %0.2f\n", ven.valorUnitario*ven.quantidade);
    printf("Valor de Imposto: %0.2f\n", imposto);
    printf("=======================");

    return 0;
}
