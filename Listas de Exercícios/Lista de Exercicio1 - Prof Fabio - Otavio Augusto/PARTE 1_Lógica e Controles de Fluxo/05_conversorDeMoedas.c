/*
    5.	Conversor de Moedas
    As moedas mais robustas do sistema financeiro global são o
    Dollar e o Euro, porém sabe-se que há flutuações nessas moedas
    em relação à cotação, principalmente quanto ao Real.
    
    Crie um programa para ajudar os viajantes a realizar a conversão
    para ambas as moedas. O usuário deverá informar o valor em real que
    deseja ser convertido e o valor da cotação do dollar e do euro em
    relação ao real. 
    Para efeito exemplificação, 1 dollar = R$ 5,57 e 1 euro = R$ 6,58.
    Obs. esses valores da cotação devem ser informados pelo usuário!

    Ao final, mostre o equivalente do valor informado em Euros e Dollar.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    float real = 0;
    float cotDollar = 0;
    float cotEuro = 0;
    float dollar = 0;
    float euro = 0;

    printf("=============================================\n");
    printf("=            CONVERSOR DE MOEDAS            =\n");
    printf("=============================================\n");
    printf("Quantidade de Reais (R$) a ser convertido: ");
    scanf("%f", &real);
    printf("Valor de cotação do Dollar: ");
    scanf("%f", &cotDollar); //Ex.: 1 dollar = R$ 5.57
    printf("Valor de cotação do Euro: ");
    scanf("%f", &cotEuro); //Ex.: 1 euro = R$ 6.58
    printf("=============================================\n");

    dollar = (real/cotDollar);
    euro = (real/cotEuro);

    printf("Equivalente em Dollar: %0.2f\n", dollar);
    printf("Equivalente em Euro: %0.2f\n", euro);
    printf("=============================================\n");

    return 0;
}