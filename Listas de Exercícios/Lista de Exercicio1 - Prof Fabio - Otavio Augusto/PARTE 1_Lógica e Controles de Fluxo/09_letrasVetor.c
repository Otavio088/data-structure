/*
	9.Faça um programa que armazene 10 letras em um vetor e imprima uma listagem numerada.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	char v[10];
	printf("=================================\n");
	printf("=        VETOR DE LETRAS        =\n");
	printf("=================================\n");
	
	for (int i = 0; i < 10; i++) {
		printf("Digite uma letra: ");
		scanf(" %c", &v[i]);
	}
	
	printf("=================================\n");
	
	for (int i = 0; i < 10; i++) {
		printf("posicao v[%d]:%c \n", i, v[i]);
	}
	
	printf("=================================\n");
	
	printf("Alinhado: ");
	for (int i = 0; i < 10; i++) {
		printf("%c", v[i]);
	}
	
	printf("\n=================================\n");
	return 0;
}