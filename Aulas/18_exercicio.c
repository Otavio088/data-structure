//Aprendendo Lista Dinâmica Encadeada/Ligada.

#include <stdio.h>
#include <stdlib.h>

struct aluno {
    int matricula;
    char nome[30];
    float nota1, nota2, nota3;
};
typedef struct aluno Aluno; //dados

struct elemento {
    Aluno dados;
    struct elemento *proximo; //vai apontar para o endereço de memória do próximo elemento.
};
typedef struct elemento* Lista; //Lista é a mesma coisa que um ponteiro de struct elemento. Um ponteiro de elemento que vai apontar para o primeiro elemento.
typedef struct elemento Elemento; //contém os dados e um ponteiro que aponta para o próximo Elemento.

Lista* criarLista();
int inserirInicioLista(Lista *lista, Aluno novoAluno);
int inserirListaOrdenada(Lista *lista, Aluno novoAluno);
int inserirFimLista(Lista *lista, Aluno novoAluno);
int removerInicioLista(Lista *lista);
int removerListaMatricula(Lista *lista, int codigoMatricula);
int removerFimLista(Lista *lista);
int tamanhoLista(Lista *lista);
int listaVazia(Lista *lista);
void imprimirLista(Lista  *lista);
void liberaLista (Lista* lista);

int main() {

    Lista *listaAlunos = criarLista();

    printf("\nQuantidade de elementos da lista: %d", tamanhoLista(listaAlunos));
    printf("\nA lista e vazia? (0 false/1 true): %d ", listaVazia(listaAlunos));

    Aluno a1 = {10, "Joaozinho", 3.0, 4.0, 7.0};
    Aluno a2 = {20, "Mariazinha", 8.5, 2.5, 9.5};
    Aluno a3 = {30, "Pedrinho", 4.0, 6.8, 9.9};
    Aluno a4 = {40, "Aninha", 7.0, 5.5, 9.0};
    Aluno a5 = {50, "Carlinhos", 10.0, 8.8, 6.9};

    inserirInicioLista(listaAlunos, a1);
    inserirListaOrdenada(listaAlunos, a3);
    inserirListaOrdenada(listaAlunos, a4);
    inserirListaOrdenada(listaAlunos, a2);
    inserirFimLista(listaAlunos, a5);

    imprimirLista(listaAlunos);

    printf("\nQuantidade de elementos da lista: %d", tamanhoLista(listaAlunos));
    printf("\nA lista e vazia? (0 false/1 true): %d ", listaVazia(listaAlunos));

    removerInicioLista(listaAlunos);
    removerListaMatricula(listaAlunos, a3.matricula);
    removerFimLista(listaAlunos);

    imprimirLista(listaAlunos);

    printf("\nQuantidade de elementos da lista: %d", tamanhoLista(listaAlunos));
    printf("\nA lista e vazia? (0 false/1 true): %d ", listaVazia(listaAlunos));

    liberaLista (listaAlunos);

    return 0;
}

Lista* criarLista() {
    Lista *listaAlunos = (Lista*) malloc(sizeof(Lista)); //listaAlunos vai apontar para uma alocação de memória do tipo Lista, que vai ser o inicio da lista. listaAlunos é um ponteiro para ponteiro.

    if (listaAlunos != NULL) { //se o endereço que listaAlunos aponta for diferente de NULL (quer dizer que conseguiu alocar memória).
        *listaAlunos = NULL; //o endereço que listaAlunos aponta recebe o valor NULL, ela passa a ser uma lista vazia.
    }

    return listaAlunos; //retorna a lista ja criada com a memória alocada.
}

int inserirInicioLista(Lista *lista, Aluno novoAluno) {
    if (lista == NULL) { //se o ENDEREÇO que lista aponta for igual a NULL, então a lista não existe.
        return 0; //false.
    }

    Elemento *novoElemento = (Elemento*) malloc(sizeof(Elemento)); //novoElemento é do tipo ponteiro que aponta para variáveis de tipo Elemento. Aqui, ele passa a apontar para o endereço de memória que foi alocado.

    if (novoElemento == NULL) { //Se o ENDEREÇO que novoElemento aponta for igual a NULL: não tem memória alocada.
        return 0; //false 
    }
    
    novoElemento->dados = novoAluno; //memória que (*novoElemento)->dados aponta recebe dados do novo aluno.
    novoElemento->proximo = (*lista); //o ponteiro "proximo" de novoElemento passa a apontar para o valor que lista aponta (inicio). Poderia ser escrito assim: (*novoElemento).proximo = (*lista);
    (*lista) = novoElemento; // O valor que lista aponta passa a ser o valor de novoElemento.

    return 1; //true.
}

int inserirListaOrdenada(Lista *lista, Aluno novoAluno) {
    if (lista == NULL) { //se a lista não existir: 
        return 0; //false
    }

    Elemento *elemento =  (Elemento*) malloc(sizeof(Elemento)); //aloca um espaço na memória que o "elemento" ponteiro (que aponta para o tipo Elemento) vai apontar

    if (elemento == NULL) { //se não conseguiu alocar memória:
        return 0; //false
    }

    elemento->dados = novoAluno; //dados de elemento recebe os dados do novoAluno.

    if ((*lista) == NULL) { //se o elemento que lista aponta for igual a NULL: 
        elemento->proximo = *lista; //o proximo de elemento aponta para onde lista aponta, no caso NULL.
        *lista = elemento; //lista passa apontar para o novo elemento.

        return 1; //true
    }else { //senao
        Elemento *anterior, *atual = *lista; //um ponteiro anterior e atual que apontam para quem for do tipo Elemento. O ponteiro atual começa apontando para onde lista aponta, no caso o inicio.
        while (atual != NULL && atual->dados.matricula < novoAluno.matricula) { //enquanto o endereço que atual aponta for diferente de NULL e a matricula dos dados do atual for menor que a matricula do novoAluno:
            anterior = atual; //anterior aponta para onde atual aponta
            atual = atual->proximo; //atual passa a apontar para o proximo dele mesmo
        }
        if (atual == (*lista)) { //se o atual apontar para o mesmo elemento que lista, no caso o primeiro:
            elemento->proximo = *lista; //o proximo de elemento aponta para onde lista aponta.
            *lista = elemento; //lista passa a apontar para o elemento, assim ele se torna o primeiro elemento da lista.
        }else { //senao
            elemento->proximo = atual; //o proximo de elemento aponta para o atual
            anterior->proximo = elemento; //o proximo de anterior aponta para o elemento
        }

        return 1; //true
    }
}

int inserirFimLista(Lista *lista, Aluno novoAluno) {
    if (lista == NULL) { //se o ENDEREÇO que lista aponta for igual a NULL, então a lista não existe.
        return 0; //false
    }

    Elemento *novoElemento; //novoElemento é do tipo ponteiro que aponta para variáveis de tipo Elemento.
    novoElemento = (Elemento*) malloc(sizeof(Elemento)); //aqui, ele passa a apontar para o endereço de memória que foi alocado.
    
    if (novoElemento == NULL) { //se o ENDEREÇO que novoElemento aponta for igual a NULL: não tem memória alocada.
        return 0; //false
    }

    novoElemento->dados = novoAluno; //endereço que (*novoElemento)->dados aponta recebe como valor os dados do novo aluno.
    novoElemento->proximo = NULL; //o ponteiro "proximo" de novoElemento passa a apontar para valor NULL, vira o ultimo elemento da lista, porque aponta para NULL. Poderia ser escrito assim: (*novoElemento).proximo = (*lista);


    if ((*lista) == NULL) { //se o endereço que lista aponta já for o valor NULL:
        *lista = novoElemento; //o valor que lista aponta passa a ser novoElemento.
    } else {
        Elemento *aux; //declara ponteiro que aponta para valores do tipo Elemento.
        aux = *lista; //aux aponta para o valor que lista aponta.
        while (aux->proximo != NULL) { //enquanto proximo não estiver apontando para NULL:
            aux = aux->proximo; //aux aponta para o proximo.
        }
        aux->proximo = novoElemento; //(*aux).proximo passa a apontar para novoElemento.
    }

    return 1;
} 

int removerInicioLista(Lista *lista) {
    if (lista == NULL) { //se lista não existe:
        return 0; // false
    }

    if (*lista == NULL) { //se lista for vazia:
        return 0; //false
    }

    Elemento *atual = *lista; //atual aponta para onde lista aponta, no caso o inicio
    *lista = atual->proximo; //inicio da lista vai der o proximo, após o atual e após ela mesma
    free(atual); //remove o "ex-primeiro" elemento da lista. Libera memória

    return 1; //true
}

int removerListaMatricula(Lista *lista, int codigoMatricula) {
    if (lista == NULL) { //se a lista não existir:
        return 0; //false
    }

    if ((*lista) == NULL) { //se a lista for vazia:
        return 0; //false
    }

    Elemento *anterior, *atual = *lista; //um ponteiro anterior. Um ponteiro atual que começa apontando para o inicio.

    while (atual != NULL && atual->dados.matricula != codigoMatricula) { //enquanto o atual for diferente de NULL E a matricula dos dados de atual for diferente do codigoMatricula:
        anterior = atual; //anterior recebe atual
        atual = atual->proximo; //atual recebe o seu proximo
    }

    if (atual == NULL) { //se o endereço que atual aponta for nulo:
        return 0; //false
    }

    if (atual == (*lista)) { //se atual for igual ao primeiro elemento:
        *lista = atual->proximo; //lista aponta para o proximo de atual. aponta para NULL
    } else { //senao
        anterior->proximo = atual->proximo; //o proximo do anterior aponta para o proximo do atual.
    }
    free(atual); //remove

    return 1;
}

int removerFimLista(Lista *lista) {
    if (listaVazia(lista)) { //se a lista for vazia
        return 0; //false
    }

    Elemento *ultimoElemento = *lista; //cria um ponteiro que começa apontando para o Elemento de início
    Elemento *anteriorElemento; //cria um ponteiro que vai apontar para o anterior ao "ultimoElemento"

    while (ultimoElemento->proximo != NULL) { //enquanto o ponteiro proximo do ultimoElemento não apontar para NULL
        anteriorElemento = ultimoElemento; //anteriorElemento aponta para ultimoElemento
        ultimoElemento = ultimoElemento->proximo; //ultimoElemento aponta para o proximo dele mesmo
    }

    if (ultimoElemento == (*lista)) { //se o ultimoElemento for igual ao inicio da lista
        (*lista) = ultimoElemento->proximo; //lista passa a apontar para o proximo do ultimoElemento, esvaziando a lista.
    } else { //senao
        anteriorElemento->proximo = ultimoElemento->proximo; //o proximo de anteriorElemento aponta para o PRÓXIMO do UltimoElemento.
    }

    free(ultimoElemento); //remove o ultimoElemento.

    return 1;
}

int tamanhoLista(Lista *lista) {
    if (lista == NULL) { //se a lista não existir:
        return 0; //false
    }

    int cont = 0; //contador

    Elemento* elemento = *lista; //ponteiro que aponta para os que forem do tipo Elemento começa apontando para onde o inicio da lista aponta.

    while (elemento != NULL) { //enquanto o endereço que elemento aponta for diferente de NULL:
        elemento = elemento->proximo; //elemento passa a valer seu próximo
        cont++; //contador soma mais 1
    }

    return cont; //retorta o total de elementos da lista.
}

int listaVazia(Lista *lista) {
    if(lista == NULL) { //se o ENDEREÇO que lista aponta for nulo: 
        return 1; //lista não existe
    }

    if (*lista == NULL) { //se o valor que lista aponta for nulo:
        return 1; //lista está vazia
    }

    return 0; //não é vazia.
}

void imprimirLista(Lista  *lista) {
    if (lista == NULL) { //Se o endereço que lista aponta é NULL, a lista não existe (no caso, se a lista não apontar para nenhum espaço de memória).
        printf("Lista nula!");
        return 0; //false.
    }

    Elemento *elemento = *lista; //Declarou um ponteiro que aponta para os que forem do tipo Elemento. Ele passa a apontar para onde lista aponta.

    printf("\n=====LISTA DE ALUNOS=====");
    while (elemento != NULL) { //enquanto o endereço que elemento aponta for diferente de NULL:
        printf("\nMatricula: %d", elemento->dados.matricula); //pode ser escrito também: (*elemento).dados.matricula 
        printf("\nNome: %s", elemento->dados.nome);
        printf("\nNota 1: %0.1f", elemento->dados.nota1);
        printf("\nNota 2: %0.1f", elemento->dados.nota2);
        printf("\nNota 3: %0.1f", elemento->dados.nota3);
        printf("\n----------------------");
    
        elemento = elemento->proximo; //elemento aponta para o próximo elemento na lista.
    }
}

void liberaLista (Lista* lista) {
    if (lista != NULL) { //se o endereço que lista aponta for diferente de NULL:
        Elemento* elemento; //ponteiro elemento que aponta para os de tipo Elemento.
        while ((*lista) != NULL) { //Enquanto o elemento que lista aponta for diferente de NULL:
            elemento = *lista; //elemento aponta para onde lista aponta (aponta para o primeiro valor da lista).
            *lista = (*lista)->proximo; //lista passa a apontar para o próximo Elemento da lista.
            free(elemento); //libera a memória da posição que 'elemento' passou a apontar.
        }
        free(lista); //libera a memória de toda a lista.
    }
}
