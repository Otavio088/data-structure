/*
    Crie um struct que represente um produto, sendo os
    atributos: codigo, valor e quantidade.
    
    Crie uma função que receba um struct pronto, por
    referência e preencha as informações inerentes.
    
    Crie uma função que receba um array de struct produto
    e seu respectivo tamanho e preencha o array fazendo
    uso da função anterior.
    
    Crie uma função chamada mostrarListaProdutos e exiba
    os produtos de modo tabular, Exemplo:
    Codigo    Quantidade    Valor
    -----------------------------
    1         4             10.99
    44        3             34.44
*/

#include <stdio.h>
#include <stdlib.h>

#define M 5

struct produto {
    int codigo;
    float valor;
    int quantidade;
};
typedef struct produto Produto;

void recebeProduto(Produto *p, int m);
void preencheProduto(Produto *p, int m);
void mostrarListaProdutos(Produto *p);

int main() {
    Produto prod[M];

    recebeProduto(prod, M);

    printf("Codigo\tQuantidade\tValor\n");
    printf("-----------------------------\n");
    mostrarListaProdutos(prod);
    printf("-----------------------------\n");

    return 0;
}

void recebeProduto(Produto *p, int m) {
    preencheProduto(p, m);
}

void preencheProduto(Produto *p, int m) {
    for (int i = 0; i < m; i++) {
        p[i].codigo = rand() % 999;
        p[i].valor = rand() % 3000;
        p[i].quantidade = rand() %999; 
    }
}

void mostrarListaProdutos(Produto *p) {
    for (int i = 0; i < M; i++) {
        printf("%d\t", p[i].codigo);
        printf("%0.2f\t\t", p[i].valor);
        printf("%d\t\n", p[i].quantidade);
    }
}