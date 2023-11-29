/*
    Uma loja de instrumentos musicais possui 4 instrumentos ja cadastrados,
    sendo eles: Violão, Guitarra, Violino e Teclado. Cada um possui codigo, 
    nomeInstrumento, quantidade e preço. Crie um programa que já contenha 
    estes instrumentos cadastrados, onde seja possível ao funcionário cadastrar
    mais instrumentos, fazer alterações no instrumento, remover instrumento da 
    lista, mostrar a lista e fechar o programa. Mostre primeiro a lista de 
    forma tabulada com as opções do programa e a cada alteração mostre 
    novamente as mesmas opções do programa. Faça tudo isso usando Lista Dinamica 
    Encadeada.(todos os instrumento de mesmo tipo não fazem alteração de 
    preço por marca diferente para facilitar o exercicio). 
    Os primeiros itens da lista deverão ser no seguinte formato:
    -----------------------------------------------------
    CODIGO     INSTRUMENTO     QUANTIDADE     PREÇO
    -----------------------------------------------------
    20         Violao          33             R$ 850,00
    21         Guitarra        15             R$ 1200,00
    25         Violino         8              R$ 425,00
    35         Teclado         20             R$ 1499,99  
    -----------------------------------------------------
    [1] - Cadastrar novo Instrumento
    [2] - Alteração no instrumento
    [3] - Remover instrumento da Lista
    [4] - Fechar Programa
    -----------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

struct instrumento {
    int codigo;
    char nomeInstrumento[20];
    int quantidade;
    float preco;
};
typedef struct instrumento Instrumento;

struct elemento {
    Instrumento dados;
    struct elemento *proximo;
};
typedef struct elemento* Lista;
typedef struct elemento Elemento;

Lista* criarLista();
void mostrarLista(Lista *listaInstrumentos);
void opcoes(Lista *listaInstrumentos, int *escolha);
int inserirLista(Lista *listaInstrumentos, Instrumento novoInstrumento);
int cadastroInstrumento(Lista *listaInstrumentos);
int alteracaoInstrumento(Lista *listaInstrumentos);
int removerInstrumento(Lista *listaInstrumentos);

int main() {

    Lista *lista = criarLista();
    
    Instrumento inst1 = {20, "Violao", 33, 850.00}, inst2 = {21, "Guitarra", 15, 1200.00}, inst3 = {25, "Violino", 8, 425.00}, inst4 = {35, "Teclado", 20, 1499.99};

    inserirLista(lista, inst1), inserirLista(lista, inst2), inserirLista(lista, inst3), inserirLista(lista, inst4);

    int op = 0;
    while (op != 4) {
        mostrarLista(lista);

        printf("[1] - Cadastrar novo Instrumento\n");
        printf("[2] - Alteracao no Instrumento\n");
        printf("[3] - Remover instrumento da Lista\n");
        printf("[4] - Fechar Programa\n");
        printf("=================================================\n");
        printf("Escolha uma Opcao: ");
        scanf(" %d", &op);

        system("cls");

        opcoes(lista, &op);
    }


    return 0;
}

Lista* criarLista() {
    Lista *listaInstrumentos = (Lista*) malloc(sizeof(Lista));

    if (listaInstrumentos != NULL) {
        *listaInstrumentos = NULL;
    }

    return listaInstrumentos;
}

void mostrarLista(Lista *listaInstrumentos) {
    if (listaInstrumentos == NULL) {
        return 0;
    }

    Elemento *elemento = *listaInstrumentos;

    printf("=================================================\n");
    printf("CODIGO\tINSTRUMENTO\tQUANTIDADE\tPRECO\n");
    printf("=================================================\n"); 
    while (elemento != NULL) {
        printf("%d\t%-12s\t%d\t\t%0.2f\n", elemento->dados.codigo, elemento->dados.nomeInstrumento, elemento->dados.quantidade, elemento->dados.preco);
        elemento = elemento->proximo;
    }
    printf("=================================================\n");

}

void opcoes(Lista *listaInstrumentos, int *escolha) {

    switch (*escolha) {
        case 1:
            mostrarLista(listaInstrumentos);
            cadastroInstrumento(listaInstrumentos);
            break;
        case 2:
            mostrarLista(listaInstrumentos);
            alteracaoInstrumento(listaInstrumentos);
            break;
        case 3:
            mostrarLista(listaInstrumentos);
            removerInstrumento(listaInstrumentos);
            break;
        case 4:
            printf("*Programa encerrado!\n");
            exit(1);
            break;
        default:
            printf("Opcao Inexistente!\n");
            break;
    }
}

int inserirLista(Lista *listaInstrumentos, Instrumento novoInstrumento) {
    if (listaInstrumentos == NULL) {
        return 0;
    }

    Elemento *elemento = (Elemento*) malloc(sizeof(Elemento));

    if (elemento == NULL) {
        return 0;
    }

    elemento->dados = novoInstrumento;

    if (*listaInstrumentos == NULL) {
        elemento->proximo = *listaInstrumentos;
        *listaInstrumentos = elemento;
        return 1;
    } else {
        Elemento *anterior, *atual = *listaInstrumentos;

        while (atual != NULL && atual->dados.codigo < novoInstrumento.codigo) {
            anterior = atual;
            atual = atual->proximo;
        }
        if (atual == (*listaInstrumentos)) {
            elemento->proximo = *listaInstrumentos;
            *listaInstrumentos = elemento;
        } else {
            elemento->proximo = atual;
            anterior->proximo = elemento;
        }
        return 1;
    }
}

int cadastroInstrumento(Lista *listaInstrumentos) {
    if (listaInstrumentos == NULL) {
        return 0;
    }

    Elemento *elementoBusca = *listaInstrumentos;  
    Instrumento novoInstrumento;

    printf("======Informe os dados do novo instrumento======\n");
    printf("Nome: ");
    scanf("%s", &novoInstrumento.nomeInstrumento);
    printf("Codigo: ");
    scanf("%d", &novoInstrumento.codigo);
        while (elementoBusca != NULL && novoInstrumento.codigo != elementoBusca->dados.codigo) {
            elementoBusca = elementoBusca->proximo;
        }
        if (elementoBusca != NULL && novoInstrumento.codigo == elementoBusca->dados.codigo) {
            system("cls");
            printf("Erro! Codigo ja existe!\n");
            return 0;
        }
    printf("Quantidade: ");
    scanf("%d", &novoInstrumento.quantidade);
    printf("Preco: ");
    scanf("%f", &novoInstrumento.preco);

    inserirLista(listaInstrumentos, novoInstrumento);
    return 1;
}

int alteracaoInstrumento(Lista *listaInstrumentos) {
    int codigoBusca = 0, op = 0;
    Elemento *elementoBusca = *listaInstrumentos;

    printf("Codigo do Instrumento: ");
    scanf("%d", &codigoBusca);
    
    while (codigoBusca != elementoBusca->dados.codigo) {
        if (codigoBusca < elementoBusca->dados.codigo) {
            system("cls");
            printf("Instrumento inexistente!\n");
            return 0;
        } else if (elementoBusca->proximo == NULL) {
            system("cls");
            printf("Instrumento inexistente!\n");
        return 0;
    } else {
            elementoBusca = elementoBusca->proximo;
        }
    }

    system("cls");

    printf("=================================================\n");
    printf("[1] - Alterar Codigo\n");
    printf("[2] - Alterar Nome\n");
    printf("[3] - Alterar Quantidade\n");
    printf("[4] - Alterar Preco\n");
    printf("=================================================\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &op);

    system("cls");

    switch (op) {
        case 1:
            mostrarLista(listaInstrumentos);
            printf("Informe o novo Codigo: ");
            scanf("%d", &elementoBusca->dados.codigo);
            system("cls");
        break;
        case 2:
            mostrarLista(listaInstrumentos);
            printf("Informe o novo Nome: ");
            scanf("%s", &elementoBusca->dados.nomeInstrumento);
            system("cls");
        break;
        case 3:
            mostrarLista(listaInstrumentos);
            printf("Informe a nova Quantidade: ");
            scanf("%d", &elementoBusca->dados.quantidade);
            system("cls");
        break;
        case 4:
            mostrarLista(listaInstrumentos);
            printf("Informe o novo Preco: ");
            scanf("%f", &elementoBusca->dados.preco);
            system("cls");
        break;
        default:
            printf("Opcao Inexistente!\n");
            mostrarLista(listaInstrumentos);
        break;
    }

    return 1;
}

int removerInstrumento(Lista *listaInstrumentos) {
    int codigoBusca = 0;
    Elemento *anterior, *elementoBusca = *listaInstrumentos;

    printf("Codigo do Instrumento: ");
    scanf("%d", &codigoBusca);

    while (codigoBusca != elementoBusca->dados.codigo) {
        if (codigoBusca < elementoBusca->dados.codigo) {
            system("cls");
            printf("Instrumento inexistente!\n");
            return 0;
        } else if (elementoBusca->proximo == NULL) {
            system("cls");
            printf("Instrumento inexistente!\n");
            return 0;
        } else {
            anterior = elementoBusca;
            elementoBusca = elementoBusca->proximo;
        }
    }

    if (elementoBusca == (*listaInstrumentos)) {
        (*listaInstrumentos) = elementoBusca->proximo;
    } else {
        anterior->proximo = elementoBusca->proximo;
    }

    free(elementoBusca);

    system("cls");

    return 1;
}
