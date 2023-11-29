/*
    3. Um sistema de gerenciamento de pedidos recebe as 
    seguintes informações do usuário (considere 10 entradas): 
    código do produto, valor unitário, quantidade vendida. 
    Armazene cada informação em um vetor próprio e:
        a. exiba a listagem de produtos no seguinte formato:
            CODIGO   V.UNIT   QTD   TOTAL ITEM
                1    100.00     2       200.00
              ...          ...             ...
              299    200.00     2       400.00
        b. calcule e exiba:
            i. Quantidade total de itens vendidos;
            ii. Valor total Vendido;
            iii. Quantidade média de itens por venda;
            iv. Valor unitário médio;
            v. Média do valor total por item;
        c. Solicite ao usuário informar um código para 
        consulta de item vendido, se o código existir exiba 
        todas informações do referido código: código, valor 
        unitário, quantidade, total item;
*/

#include <stdio.h>
#include <stdlib.h>

#define M 10

struct produtos {
    int codigo[M];
    float valorUnitario[M];
    int quantidadeVendida[M];
};
typedef struct produtos Produtos;

void preenchimentoProdutos(Produtos *p);
void ordenacaoProdutos(Produtos *p);
void exibeProdutos(Produtos *p);

int main() {
    Produtos prod;
    int qtdTotalVendido = 0, somaValorUnitario = 0, cod = 0;
    float vTotalVendido = 0, mediaItensVenda = 0, vUnitarioMedio = 0, somaValorTotal = 0, mediaValorTotal = 0;

    preenchimentoProdutos(&prod); //optei por preencher as informações de forma alreatória para poupar tempo.
    ordenacaoProdutos(&prod); //criei uma função de ordenação para treinar os conhecimentos.

    //a
    exibeProdutos(&prod);

    //b
    for (int i = 0; i < M; i++) { 
        qtdTotalVendido += prod.quantidadeVendida[i];
        vTotalVendido += ((prod.quantidadeVendida[i])*(prod.valorUnitario[i]));
        somaValorUnitario += prod.valorUnitario[i];
        somaValorTotal += ((prod.valorUnitario[i])*(prod.quantidadeVendida[i]));
    }
    mediaItensVenda = qtdTotalVendido/M;
    vUnitarioMedio = somaValorUnitario/M;
    mediaValorTotal = somaValorTotal/M;
    printf("1 - Quantidade Total de Itens Vendidos: %d\n", qtdTotalVendido);
    printf("2 - Valor Total Vendido: %0.2f\n", vTotalVendido);
    printf("3 - Quantidade Media de Itens por Venda: %0.2f\n", mediaItensVenda);
    printf("4 - Valor Unitario Medio: %0.2f\n", vUnitarioMedio);
    printf("5 - Media do valor total por item: %0.2f\n", mediaValorTotal);
    printf("------------------------------------------------\n");

    //c
    printf("Informe um Codigo de Produto para consulta: ");
    scanf("%d", &cod);
    int cont = 0;
    int i = 0;
    do { 
        for (i = 0; i < M; i++) {
            if (cod == prod.codigo[i]) {
                printf("------------------------------------------------\n");
                printf("CODIGO\tV.UNIT\t\tQTD\tTOTAL ITEM\n");
                printf("------------------------------------------------\n");
                printf("%d\t%0.2f\t\t%d\t%0.2f\n", prod.codigo[i], prod.valorUnitario[i], prod.quantidadeVendida[i], ((prod.valorUnitario[i])*(prod.quantidadeVendida[i])));
                printf("------------------------------------------------\n");
                cont = 1;
            } else if ((cod < prod.codigo[i]) && (cont == 0)) {
                printf("Codigo invalido! Tente outro: ");
                scanf("%d", &cod);
                i = 0;
            }
        }
    } while (cont == 0);

    return 0;
}

void preenchimentoProdutos(Produtos *p) {
    for (int i = 0; i < M; i++) {
        p->codigo[i] = rand() % 300;
        p->valorUnitario[i] = rand() % 3000;
        p->quantidadeVendida[i] = rand() % 100;
    }
}

void ordenacaoProdutos(Produtos *p) {
    int i, j, menor, troca;
    float trocaFloat;

    for (i = 0; i < M; i++) {
        menor = i;
        for (j = i+1; j < M; j++) {
            if (p->codigo[j] < p->codigo[menor]) {
                menor = j;
            }
        }
        if (i != menor) {
            troca = p->codigo[i];
            p->codigo[i] = p->codigo[menor];
            p->codigo[menor] = troca;

            troca = p->quantidadeVendida[i];
            p->quantidadeVendida[i] = p->quantidadeVendida[menor];
            p->quantidadeVendida[menor] = troca;

            trocaFloat = p->valorUnitario[i];
            p->valorUnitario[i] = p->valorUnitario[menor];
            p->valorUnitario[menor] = trocaFloat;
        }
    }
}

void exibeProdutos(Produtos *p) {
    printf("------------------------------------------------\n");
    printf("CODIGO\tV.UNIT\t\tQTD\tTOTAL ITEM\n");
    printf("------------------------------------------------\n");
     for (int i = 0; i < M; i++) {
        printf("%d\t", p->codigo[i]);
        printf("%0.2f\t\t" ,p->valorUnitario[i]);
        printf("%d\t", p->quantidadeVendida[i]);
        printf("%0.2f\t", ((p->valorUnitario[i])*(p->quantidadeVendida[i])) );
        printf("\n");
    }
    printf("------------------------------------------------\n");
}
