/*
    4.	Conversor de temperaturas
    As unidades de temperaturas são diversas em muitos contextos
    e/ou países. No Brasil fazer uso na unidade º Celsius, porém
    há as unidades Kelvin e ºFarenheit.

    Crie um programa que ao receber uma temperatura em ºC apresente
    a mesma nas demais unidades. Fórmulas de Conversão:

    Celsius para Kelvin:                        Celsius para Farenheit:
    0 °C + 273,15 = 273,15 K                    °F = °C × 1,8 + 32
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    float C = 0;
    float K = 0;
    float F = 0;

    printf("=======================================\n");
    printf("=      CONVERSOR DE TEMPERATURAS      =\n");
    printf("=======================================\n");
    printf("Digite a Temperatura em Celsius: ");
    scanf("%f", &C);
    printf("=======================================\n");

    K = (C + 273.15);
    F = ((C * 1.8) + 32);

    printf("A Temperatura em Kelvin: %0.2f\n", K);
    printf("A Temperatura em Farenheit: %0.2f\n", F);
    printf("=======================================\n");

    return 0;
}