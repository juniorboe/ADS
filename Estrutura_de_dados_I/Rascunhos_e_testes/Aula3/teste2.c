#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declarando struct no
typedef struct no {
    int dado;
    struct no *prox;
} no;

//Declarando variaveis
typedef no *ptr_no; //declarando um ponteiro para a lista
ptr_no lista; //criando a variavel lista para apontar para a lista
int op;

//Prototipacao
void mostrar_lista(ptr_no lista);
void adicionar_dado(ptr_no lista);
void remover_dado(ptr_no lista);
void mostrar_menu();
void selecao_menu(int op);

//Funcao principal
int main() {
    //Iniciando a maquina de randomizacao
    srand(time(NULL));
    op = 1;
    //Iniciando a lista
    lista = (ptr_no)malloc(sizeof(no)); //criando o primeiro nó
    lista->dado = 0; //colocando 0 como dado do primeiro nó
    lista->prox = NULL; //apontando o ponteiro do primeiro nó para nulo

    while (op != 0) {
        system("cls");
        mostrar_menu();
        scanf("%d", &op);
        selecao_menu(op);
    }
    system("Pause");
    return 0;
}

void mostrar_lista(ptr_no lista) {
    system("cls");
    while (lista->prox != NULL) {
        printf("%d, ", lista->dado);
        lista = lista->prox;
    }
    printf("%d", lista->dado);
}

void adicionar_dado(ptr_no lista) {
    while (lista->prox != NULL) {
        lista = lista->prox;
    }
    lista->prox = (ptr_no)malloc(sizeof(no));
    lista = lista->prox;
    lista->dado = rand() %100;
    lista->prox = NULL;
}

void mostrar_menu() {
    mostrar_lista(lista);
    printf("\n\nEscolha uma das opcoes:\n");
    printf("1- Adicionar dado.\n");
    printf("2- Remover dado.\n");
    printf("0- Sair.\n");
}

void selecao_menu(int op) {
    switch (op) {
        case 1:
            adicionar_dado(lista);
            break;
        case 2:
            remover_dado(lista);
            break;
        
    }
}

void remover_dado(ptr_no lista) {
    int dado;
    ptr_no atual; //Criando um ponteiro que aponte para um espaço vazio, para que esse espaco receba o dado anterior, e aponte para o proximo no
    printf("Digite o numero a ser removido: ");
    scanf("%d", &dado);
    while (lista->dado != dado) {
        if (lista->prox == NULL) {
            break;
        }
        else {
            atual = lista;
            lista = lista->prox;
        }
    }
    if (dado == lista->dado) {
        atual->prox = lista->prox;
    }
}
