/*
	6. Conversor de Tempo
	Crie um programa que ao receber do usuário um valor inteiro,
	correspondente a quantidade de anos, calcule a equivalência
	deste em (considere meses com 30 dias e ano com 365 dias):
	-meses
	-dias
	-horas
	-minutos
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int anos = 0;
	int meses = 0;
	int dias = 0;
	int horas = 0;
	int minutos = 0;
	
	printf("==================================\n");
	printf("=       CONVERSOR DE TEMPO       =\n");
	printf("==================================\n");
	printf("Digite a quantidade de anos: ");
	scanf("%d", &anos);
	printf("==================================\n");
	
	meses = (anos*12);
	dias = (anos*365);
	horas = (dias*24);
	minutos = (horas*60);
	
	printf("Convertido em meses: %d meses\n", meses);
	printf("Convertido em dias: %d dias\n", dias);
	printf("Convertido em horas: %d hrs\n", horas);
	printf("Convertido em minutos: %d min\n", minutos);
	printf("==================================\n");
	
	return 0;
}