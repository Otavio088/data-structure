#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int A[100];
	int B[100];
	
	int i, j, troca = 0, menor = 0;
	for (i = 0; i < 100; i++) {
		A[i] = rand() % 100;
		B[i] = rand() % 100;
	}
	
	//bubble sort
	for (i = 0; i < 100; i++) {
		for (j = 0; j < 100; j++) {
			if (A[j] > A[j+1]) {
				troca = A[j+1];	
				A[j+1] = A[j];
				A[j] = troca;
			}
		}
	}
	
	//selection sort
	for (i = 0; i < (100-1); i++) {
		menor = i;
		for (j = i+1; j < 100; j++) {
			if (B[j] < B[menor]) {
				menor = j;
			}
		}
		if (i != menor) {
			troca = B[i];
			B[i] = B[menor];
			B[menor] = troca;
		}
	}
	
	for (i = 0; i < 100; i++) {
		printf ("%d\n", A[i]);
	}
	printf("------------------------------\n");
	for (i = 0; i < 100; i++) {
		printf ("%d\n", B[i]);
	}
	
	return 0;
}
