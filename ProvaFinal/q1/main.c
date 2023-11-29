#include <stdio.h>
#include <stdlib.h>

struct dados {
	int anoFabricacao;
	int anoModelo;
	char cor[10];
	char placa[10];
	int codigo;
	float valor;
};
typedef struct dados Dados;

struct elemento {
	Dados dados;
	struct elemento *proximo;
};
typedef struct elemento* Lista;
typedef struct elemento Elemento;

Lista* criarLista();
void escolha(Lista *listaVeiculos,int op);
int cadastroVeiculo(Lista *listaVeiculos);
int listagemVeiculos(Lista *listaVeiculos);
int consultaVeiculo(Lista *listaVeiculos);
int removerInicio(Lista *listaVeiculos);
int resumoVeiculos(Lista *listaVeiculos);

int main(int argc, char *argv[]) {
	Lista *listaVeiculos = criarLista();
	
	int op = 0;
	while (op != 6) {
		printf("==========================================\n");
		printf("                MENU VEICULOS\n");
		printf("==========================================\n");
		printf("1. cadastro de veiculo\n2. listagem de veiculos\n3. consulta de veiculo por codigo\n4. remover veiculo do inicio da lista\n5. resumo veiculos\n6. fechar\n");
		printf("==========================================\n");
		printf("Opcao: ");
		scanf("%d", &op);
		
		escolha(listaVeiculos, op);
	}
	
	return 0;
}

Lista* criarLista() {
	Lista *listaVeiculos = (Lista*) malloc(sizeof(Lista));
	
	if (listaVeiculos != NULL) {
		*listaVeiculos = NULL;
	}	
	
	return listaVeiculos;
}

void escolha(Lista *listaVeiculos,int op) {
	switch(op) {
		case 1:
			system("cls");
			cadastroVeiculo(listaVeiculos);
			printf("Cadastro realizado com sucesso\n");
			break;
		case 2:
			system("cls");
			listagemVeiculos(listaVeiculos);
			break;
		case 3:
			system("cls");
			consultaVeiculo(listaVeiculos);
			break;
		case 4:
			system("cls");
			removerInicio(listaVeiculos);
			break;
		case 5:
			system("cls");
			resumoVeiculos(listaVeiculos);
			break;
		case 6:
			system("cls");
			printf("*Programa finalizado!\n");
			break;
		default:
			system("cls");
			printf("Opcao inexistente!\n");
	}
}

int cadastroVeiculo(Lista *listaVeiculos) {
	if (listaVeiculos == NULL) {
		return 0;
	}
	
	Dados dadosVeiculo;
	
	printf("         INFORME OS DADOS\n");
	printf("======================================\n");
	printf("Ano de fabricacao: ");
	scanf("%d", &dadosVeiculo.anoFabricacao);
	printf("Ano do modelo: ");
	scanf("%d", &dadosVeiculo.anoModelo);
	printf("Cor do veiculo: ");
	scanf("%s", &dadosVeiculo.cor);
	printf("Placa do veiculo: ");
	scanf("%s", &dadosVeiculo.placa);
	printf("Codigo do veiculo: ");
	scanf("%d", &dadosVeiculo.codigo);
	printf("valor do veiculo: ");
	scanf("%f", &dadosVeiculo.valor);
	
	system("cls");
	
	Elemento *novoVeiculo = (Elemento*) malloc(sizeof(Elemento));
	
	if (novoVeiculo == NULL) {
		return 0;
	}
	
	novoVeiculo->dados = dadosVeiculo;
	
	if ((*listaVeiculos) == NULL) {
		novoVeiculo->proximo = *listaVeiculos;
		*listaVeiculos = novoVeiculo;
		return 1;
	} else {
		Elemento *anterior, *atual = *listaVeiculos;
		
		while (atual != NULL && atual->dados.codigo < dadosVeiculo.codigo) {
			anterior = atual;
			atual = atual->proximo;
		}
		
		if (atual == (*listaVeiculos)) {
			novoVeiculo->proximo = *listaVeiculos;
			*listaVeiculos = novoVeiculo;
		} else {
			novoVeiculo->proximo = atual;
			anterior->proximo = novoVeiculo;
		}
		
		return 1;
	}
	
}

int listagemVeiculos(Lista *listaVeiculos) {
	if (listaVeiculos == NULL) {
		return 0;
	}
	
	if (*listaVeiculos == NULL) {
		printf("Ainda nao existe nenhum veiculo na lista!\n");
		return 0;
	}
	
	Elemento *auxiliar = *listaVeiculos;
	
	printf("=================================================================\n");
	printf("AnoFabricacao\tAnoModelo\tCor\tPlaca\tCodigo\tValor\n");
	printf("=================================================================\n");
	
	while (auxiliar != NULL) {
		printf("%d\t\t%d\t\t%s\t%s\t%d\t%0.2f\n", auxiliar->dados.anoFabricacao, auxiliar->dados.anoModelo, auxiliar->dados.cor, auxiliar->dados.placa, auxiliar->dados.codigo, auxiliar->dados.valor);
		auxiliar = auxiliar->proximo;
	}
	printf("=================================================================\n");
	
	return 1;
}

int consultaVeiculo(Lista *listaVeiculos) {
	if (listaVeiculos == NULL) {
		return 0;
	}
	
	if (*listaVeiculos == NULL) {
		printf("Ainda nao existe nenhum veiculo na lista!\n");
		return 0;
	}
	
	int op = 0;
	printf("Informe o Codigo do Veiculo: ");
	scanf("%d", &op);
	
	Elemento *auxiliar = *listaVeiculos;
	
	while (auxiliar != NULL && auxiliar->dados.codigo != op) {
		auxiliar = auxiliar->proximo;
	}
	
	if (auxiliar == NULL) {
		printf("Codigo inexistente!\n");
		return 0;
	} else {
		printf("=================================================================\n");
		printf("AnoFabricacao\tAnoModelo\tCor\tPlaca\tCodigo\tValor\n");
		printf("=================================================================\n");
		printf("%d\t\t%d\t\t%s\t%s\t%d\t%0.2f\n", auxiliar->dados.anoFabricacao, auxiliar->dados.anoModelo, auxiliar->dados.cor, auxiliar->dados.placa, auxiliar->dados.codigo, auxiliar->dados.valor);
		printf("=================================================================\n");
	}
	
	return 1;
}

int removerInicio(Lista *listaVeiculos) {
	if (listaVeiculos == NULL) {
		return 0;
	}
	
	if (*listaVeiculos == NULL) {
		printf("Ainda nao existe nenhum veiculo na lista!\n");
		return 0;
	}
	
	Elemento *auxiliar = *listaVeiculos;
	*listaVeiculos = auxiliar->proximo;
	
	free(auxiliar);
	
	printf("Veiculo removido do inicio!\n");
	return 1;
}

int resumoVeiculos(Lista *listaVeiculos) {
	if (listaVeiculos == NULL) {
		return 0;
	}
	
	if (*listaVeiculos == NULL) {
		printf("Ainda nao existe nenhum veiculo na lista!\n");
		return 0;
	}
	
	int qtdVeiculos = 0;
	float valorMediaVeiculos = 0, valorTotalVeiculos = 0;

	Elemento *auxiliar = *listaVeiculos;

	while (auxiliar != NULL) {
		valorMediaVeiculos = valorMediaVeiculos + auxiliar->dados.valor;
		qtdVeiculos++;
		
		auxiliar = auxiliar->proximo;
	}
	valorTotalVeiculos = valorMediaVeiculos;
	valorMediaVeiculos = (valorMediaVeiculos/qtdVeiculos);
	
	printf("------------------------------------------------\n");
	printf("Quantidade de veiculos cadastrados: %d\n", qtdVeiculos);
	printf("Valor medio dos veiculos: %0.2f\n", valorMediaVeiculos);
	printf("Valor total dos veiculos: %0.2f\n", valorTotalVeiculos);
	printf("------------------------------------------------\n");
	
	return 1;
}
