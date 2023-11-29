#include <stdio.h>
#include <stdlib.h>

#define N 6

struct dados {
	int codigo;
	char nomeCliente[10];
};
typedef struct dados Dados;

struct fila {
	int inicio;
	int final;
	Dados dados[N];
};
typedef struct fila Fila;

Fila* criarFila();
void opcoes(Fila* fila, int op);
int filaVazia(Fila *fila);
int filaCheia (Fila *fila);
int tamanhoFila(Fila *fila);
int inserirFila(Fila *fila);
int removerFila(Fila *fila);
int imprimirFila(Fila *fila);

int main(int argc, char *argv[]) {
	Fila* fila = criarFila();
	
	int op = 0;
	while (op != 5) {
		printf("=========================================\n");
		printf("              MENU LAVA BARRO\n");
		printf("=========================================\n");
		printf("[1] Cadastrar veiculo\n[2] Mostrar Fila\n[3] Atender veiculo\n[4] Tamanho da fila\n[5] Sair\n");
		printf("=========================================\n");
		printf("Opcao: ");
		scanf("%d", &op);
		
		opcoes(fila, op);
	}
	

	return 0;
}

Fila* criarFila() {
	Fila *fila = (Fila*) malloc(sizeof(Fila));
	
	if (fila != NULL) {
		fila->inicio = 0;
		fila->final = 0;
	}
	
	return fila;
}

void opcoes(Fila* fila, int op) {
	switch(op) {
		case 1:
			system("cls");
			inserirFila(fila);
			break;
		case 2:
			system("cls");
			imprimirFila(fila);
			break;
		case 3:
			system("cls");
			removerFila(fila);
			break;
		case 4:
			system("cls");
			printf("Tamanho da fila: %d Veiculos\n", tamanhoFila(fila));
			break;
		case 5:
			system("cls");
			printf("Programa finalizado!\n");
			break;
		default:
			system("cls");
			printf("Opcao inexistente!\n");
	}
}

int filaVazia(Fila *fila) {
	if (fila == NULL) {
		return -1;
	}
	
	if (fila->inicio == fila->final) {
		return 1; //fila vazia
	} else {
		return 0;
	}
}

int filaCheia (Fila *fila) {
	if (fila == NULL) {
		return -1;
	}
	
	if (fila->inicio == (fila->final + 1) % N) {
		return 1; //fila cheia
	} else {
		return 0;
	}
}

int tamanhoFila(Fila *fila) {
	if (fila == NULL) {
		return -1;
	}
	
	if (fila->inicio <= fila->final) {
		return fila->final - fila->inicio;
	}
	
	return N - (fila->inicio - fila->final);
	
}

int inserirFila(Fila *fila) {
	if (fila == NULL) {
		return 0;
	}
	
	if (filaCheia(fila)) {
		printf("Sem vagas! Fila cheia!\n");
		return 0;
	}
	
	Dados dadosCliente;
	
	printf("            INFORME OS DADOS\n");
	printf("=========================================\n");
	printf("Codigo: ");
	scanf("%d", &dadosCliente.codigo);
	printf("Nome do Cliente: ");
	scanf("%s", &dadosCliente.nomeCliente);
	
	system("cls");
	
	fila->dados[fila->final] = dadosCliente;
	fila->final = (fila->final + 1) % N;
	
	printf("Veiculo entrou na fila!\n");
	
	return 1;
}

int removerFila(Fila *fila) {
	if (fila == NULL || filaVazia(fila)) {
		printf("Nenhum veiculo na fila!\n");
		return 0;
	}
	
	fila->inicio = (fila->inicio + 1) % N;
	
	printf("Veiculo atendido!\n");
	
	return 1;
}

int imprimirFila(Fila *fila) {
	if (fila == NULL) {
		return 0;
	}
	
	if (filaVazia(fila)) {
		printf("Nenhum veiculo na fila!\n");
		return 0;
	}
	
	int i = fila->inicio;
	printf("==============================\n");
	printf("CODIGO\tNOME CLIENTE\n");
	printf("==============================\n");
	while (i != fila->final) {
		printf("%d\t%s\n", fila->dados[i].codigo, fila->dados[i].nomeCliente);
		
		i = (i+1) % N;
	}
	printf("==============================\n");
	
	return 1;
}
