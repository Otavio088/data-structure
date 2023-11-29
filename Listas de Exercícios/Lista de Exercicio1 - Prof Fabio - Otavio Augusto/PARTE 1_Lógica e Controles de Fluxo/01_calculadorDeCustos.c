/*
    1. Programa: calculador de custos.
    Sabe-se que o custo de um carro novo ao consumidor é a soma
    do custo de fábrica com a porcentagem do distribuidor e dos
    impostos (aplicados ao custo de fábrica). Crie um programa
    que permita ao usuário informar: valor do custo de fábrica,
    o % de impostos e o % do distribuidor.
    A saída deverá mostrar:
      -Valor total do carro;
      -Valor do distribuidor e a porcentagem informada;
      -Valor dos impostos;
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    float custoCarro = 0;
    float custoFabrica = 0;
    float porcentagemDistribuidor = 0;
    float valorDistribuidor = 0;
    float porcentagemImpostos = 0;
    float valorImpostos = 0;

    printf("============================================\n");
    printf("=           CALCULADOR DE CUSTOS           =\n");
    printf("============================================\n");
    printf("Valor do custo de fabrica: ");
    scanf("%f", &custoFabrica);
    printf("Porcentagem (%%) de impostos: ");
    scanf("%f", &porcentagemImpostos);
    printf("Porcentagem (%%) do distribuidor: ");
    scanf("%f", &porcentagemDistribuidor);

    valorDistribuidor = (porcentagemDistribuidor/100 * custoFabrica);
    valorImpostos = (porcentagemImpostos/100 * custoFabrica);
    custoCarro = (custoFabrica + valorDistribuidor + valorImpostos);

    printf("============================================\n");
    printf("Valor total do carro: R$ %0.2f\n", custoCarro);
    printf("Valor do distribuidor: R$ %0.2f, Porcentagem informada: %0.2f%%\n", valorDistribuidor, porcentagemDistribuidor);
    printf("Valor dos impostos: R$ %0.2f\n", valorImpostos);
    printf("============================================\n");

    return 0;
}