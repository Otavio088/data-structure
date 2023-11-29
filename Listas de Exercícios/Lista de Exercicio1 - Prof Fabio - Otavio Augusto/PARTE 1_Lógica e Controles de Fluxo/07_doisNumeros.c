/*
	7.	Fazer um programa em "C" que solicite 2 números e informe:
	a. A soma dos números;
	b. O produto do primeiro número pelo quadrado do segundo;
	c. O quadrado do primeiro número;
	d. A soma dos cubos de ambos números;
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	float n1 = 0;
	float n2 = 0;
	
	printf("========================================================\n");
	printf("=                 INFORME DOIS NUMEROS                 =\n");
	printf("========================================================\n");
	printf("Primeiro valor: ");
	scanf("%f", &n1);
	printf("Segundo valor: ");
	scanf("%f", &n2);
	printf("========================================================\n");
	
	printf("Soma entre os dois numeros: %0.2f\n", (n1+n2));
	printf("Produto do primeiro pelo quadrado do segundo: %0.2f\n", (n1*(n2*n2)));
	printf("Quadrado do primeiro numero: %0.2f\n", n1*n1);
	printf("Soma dos cubos de ambos os numeros: %0.2f\n", (n1*n1*n1)+(n2*n2*n2));
	printf("========================================================\n");

	return 0;
}