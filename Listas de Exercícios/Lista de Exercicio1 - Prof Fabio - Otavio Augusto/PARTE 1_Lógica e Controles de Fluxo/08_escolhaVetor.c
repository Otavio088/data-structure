/*
	8. Faça um programa em C que armazene 15 números inteiros
	em um vetor e depois permita que o usuário digite um número 
	inteiro para ser buscado no vetor, se for encontrado o programa 
	deve imprimir a posição desse número no vetor, caso contrário, 
	deve imprimir a mensagem: "Nao encontrado!".
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int v[15];
	int busca = 0;
	
	printf("==============================================================\n");
	printf("=                     BUSCADOR DE NUMEROS                    =\n");
	printf("==============================================================\n");
	
	for (int i = 0; i < 15; i++) {
		v[i] = rand() %60; //gera valores aleatórios;
	}

	printf("Digite um numero inteiro para buscar no vetor: ");
	scanf("%d", &busca);
	
	int achou = 0;
	
	for (int i = 0; i < 15; i++) {
		if (v[i] == busca) {
			printf("Posicao do numero no vetor: v[%d]\n", i);
			achou++;
		}
	}
	
	if (achou == 0) {
		printf("Nao encontrado!\n");
	}
	
	printf("==============================================================\n");
	printf("Vetor: ");
	for (int i = 0; i < 15; i++) {
		if (i < 14) {
			printf("%d, ", v[i]);
		} else {
			printf("%d.\n", v[i]);
		}
	}
	printf("==============================================================\n");

	return 0;
}