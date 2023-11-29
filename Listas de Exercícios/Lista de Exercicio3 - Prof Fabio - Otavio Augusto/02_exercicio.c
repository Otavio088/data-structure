/*
    2. Uma empresa deseja armazenar dados de pedidos, os pedidos
    são compostos por um codigo, nome cliente, valor pedido,
    desconto, valor final.
    Crie um projeto que permita ao usuário realizar as operações
    abaixo por meio de um menu:
    ------------------------------------
            SISTEMA DE VENDAS
    ------------------------------------
    1. Criar pedido
    2. Listar pedidos
    3. Procurar pedido por código
    4. Remover pedido por código
    5. Resumo de pedidos
    6. Fechar
    ------------------------------------
    Na opção 5 deverá mostrar:
    - quantidade de pedidos
    - valor total dos pedidos
    - valor total desconto aplicado
    - valor total liquido
    - valor medio da: venda, desconto e liquido
*/

#include <stdio.h>
#include <stdlib.h>

struct pedido {
    int codigo;
    char nomeCliente[20];
    float valorPedido;
    float desconto;
    float valorFinal;
};
typedef struct pedido Pedido;

struct elemento {
    Pedido dados;
    struct elemento *proximo;
};
typedef struct elemento Elemento;
typedef struct elemento* Lista;

Lista* criarLista();
void opcoes(int op, Lista *listaPedidos);
int criarPedido(Lista *listaPedidos);
int listarPedidos(Lista *listaPedidos);
int procuraPedido(Lista *listaPedidos);
int removePedido(Lista *listaPedidos);
int resumoPedidos(Lista *listaPedidos);

int main() {
    Lista *listaPedidos = criarLista();

    int op = 0;

    while (op != 6) {
        printf("------------------------------\n");
        printf("       SISTEMA DE VENDAS      \n");
        printf("------------------------------\n");
        printf("1. Criar pedido\n2. Listar pedidos\n3. Procurar pedido por codigo\n4. Remover pedido por codigo\n5. Resumo de pedidos\n6. Fechar\n");
        printf("------------------------------\n");
        printf("Opcao: ");
        scanf("%d", &op);

        system("cls");

        opcoes(op, listaPedidos);
    }

    return 0;
}

void opcoes(int op, Lista *listaPedidos) {
    
    switch (op) {
        case 1:
            criarPedido(listaPedidos);
            system("cls");
            printf("Pedido criado com sucesso!\n");
            break;
        case 2: 
            listarPedidos(listaPedidos);
            break;
        case 3: 
            procuraPedido(listaPedidos);
            break;
        case 4:
            removePedido(listaPedidos);
            break;
        case 5:
            resumoPedidos(listaPedidos);
            break;
        case 6:
            printf("Programa finalizado!\n");
            exit(1);
            break;
        default:
            printf("Opcao inexistente!\n");
    }

}

Lista* criarLista() {
    Lista *listaPedidos = (Lista*) malloc(sizeof(Lista));

    if (listaPedidos != NULL) {
        *listaPedidos = NULL;
    }

    return listaPedidos;
}

int criarPedido(Lista *listaPedidos) {
    if (listaPedidos == NULL) {
        return 0;
    }

    //cria e preenche novo pedido
    Pedido dadosPedido;

    printf("Codigo: ");
    scanf("%d", &dadosPedido.codigo);
    printf("Nome Cliente: ");
    scanf("%s", &dadosPedido.nomeCliente);
    printf("Valor de Pedido: ");
    scanf("%f", &dadosPedido.valorPedido);
    printf("Desconto(%%): ");
    scanf("%f", &dadosPedido.desconto);

    dadosPedido.valorFinal = dadosPedido.valorPedido - (dadosPedido.desconto/100 * dadosPedido.valorPedido); 

    //inserir na lista
    Elemento *novoPedido = (Elemento*) malloc(sizeof(Elemento));

    if (novoPedido == NULL) {
        return 0;
    }

    novoPedido->dados = dadosPedido;

    if (*listaPedidos == NULL) {
        novoPedido->proximo = *listaPedidos;
        *listaPedidos = novoPedido;
        return 1;
    } else {
        Elemento *anterior, *atual = *listaPedidos;

        while (atual != NULL && atual->dados.codigo < dadosPedido.codigo) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (atual == (*listaPedidos)) {
            novoPedido->proximo = *listaPedidos;
            *listaPedidos = novoPedido;
        } else {
            novoPedido->proximo = atual;
            anterior->proximo = novoPedido;
        }
        return 1;
    }

}

int listarPedidos(Lista *listaPedidos) {
    if (listaPedidos == NULL) {
        return 0;
    }
    if (*listaPedidos == NULL) {
        printf("Nenhum pedido foi feito!\n");
        return 0;
    }

    Elemento *mostraPedido = *listaPedidos;

    printf("-------------------------------------------------------------------\n");
    printf("CODIGO\tNOME CLIENTE\tVALOR PEDIDO\tDESCONTO\tVALOR FINAL\n");
    printf("-------------------------------------------------------------------\n");
    while (mostraPedido != NULL) {
        printf("%d\t%s\t\t%0.2f\t\t%0.0f%%\t\t%0.2f\n", mostraPedido->dados.codigo,  mostraPedido->dados.nomeCliente,  mostraPedido->dados.valorPedido,  mostraPedido->dados.desconto,  mostraPedido->dados.valorFinal);
        mostraPedido = mostraPedido->proximo;
    }
    printf("-------------------------------------------------------------------\n");

    return 1;
}

int procuraPedido(Lista *listaPedidos) {
    if (listaPedidos == NULL) {
        return 0;
    }
    if (*listaPedidos == NULL) {
        printf("Nenhum pedido foi feito!\n");
        return 0;
    }

    Elemento *procuraPedido = *listaPedidos;
    int cod = 0;

    printf("Codigo do pedido: ");
    scanf("%d", &cod);
    system("cls");

    while (procuraPedido != NULL && procuraPedido->dados.codigo != cod) {
        procuraPedido = procuraPedido->proximo;
    }

    if (procuraPedido == NULL) {
        printf("Pedido inexistente!\n");
        return 0;
    }

    printf("-------------------------------------------------------------------\n");
    printf("CODIGO\tNOME CLIENTE\tVALOR PEDIDO\tDESCONTO\tVALOR FINAL\n");
    printf("-------------------------------------------------------------------\n");
    printf("%d\t%s\t\t%0.2f\t\t%0.0f%%\t\t%0.2f\n", procuraPedido->dados.codigo,  procuraPedido->dados.nomeCliente,  procuraPedido->dados.valorPedido,  procuraPedido->dados.desconto,  procuraPedido->dados.valorFinal);
    printf("-------------------------------------------------------------------\n");

    return 1;
}

int removePedido(Lista *listaPedidos) {
    if (listaPedidos == NULL) {
        return 0;
    }
    if (*listaPedidos == NULL) {
        printf("Nenhum pedido foi feito!\n");
        return 0;
    }

    Elemento *anterior, *procuraPedido = *listaPedidos;
    int cod = 0;

    printf("Codigo do pedido: ");
    scanf("%d", &cod);
    system("cls");

    while (procuraPedido != NULL && procuraPedido->dados.codigo != cod) {
        anterior = procuraPedido;
        procuraPedido = procuraPedido->proximo;
    }

    if (procuraPedido == NULL) {
        printf("Pedido inexistente!\n");
        return 0;
    }

   if (procuraPedido == (*listaPedidos)) {
        (*listaPedidos) = procuraPedido->proximo;
    } else {
        anterior->proximo = procuraPedido->proximo;
    }

    free(procuraPedido);

    printf("Pedido removido!\n");

    return 1;
}

int resumoPedidos(Lista *listaPedidos) {
    int qtdPedidos = 0;
    float valorTotalPedidos = 0, valorTotalDesconto = 0, valorTotalLiquido = 0;
    float valorMedioVenda = 0, valorMedioDesconto = 0, valorMedioLiquido = 0;

    if (*listaPedidos == NULL) {
        printf("Nenhum pedido foi feito!\n");
        return 0;
    }

    Elemento *pedido = *listaPedidos;

    while (pedido != NULL) {
        valorTotalPedidos = (valorTotalPedidos + pedido->dados.valorPedido);
        valorTotalDesconto = (valorTotalDesconto + pedido->dados.desconto);
        valorTotalLiquido = (valorTotalLiquido + pedido->dados.valorFinal);
        pedido = pedido->proximo;
        qtdPedidos++;
    }

    valorMedioVenda = (valorTotalPedidos/qtdPedidos);
    valorMedioDesconto = (valorTotalDesconto/qtdPedidos);
    valorMedioLiquido = (valorTotalLiquido/qtdPedidos);

    system("cls");
    printf("------------------------------------------\n");
    printf("Quantidade de pedidos: %d\n", qtdPedidos);
    printf("Valor Total Pedidos: %0.2f\n", valorTotalPedidos);
    printf("Valor Total Descontos: %0.0f%%\n", valorTotalDesconto);
    printf("Valor Total Liquido: %0.2f\n", valorTotalLiquido);
    printf("Valor Medio Venda: %0.2f\n", valorMedioVenda);
    printf("Valor Medio Desconto: %0.2f\n", valorMedioDesconto);
    printf("Valor Medio Venda Liquido: %0.2f\n", valorMedioLiquido);
    printf("------------------------------------------\n");

    return 1;
}