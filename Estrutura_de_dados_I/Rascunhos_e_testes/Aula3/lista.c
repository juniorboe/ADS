#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
    int dado;
    struct no *proximo;
} no;

//Definindo variáveis
typedef struct no *ptr_no;
ptr_no lista;
int op;

//prototipação
void menu_mostrar();
void menu_selecionar(int op);
void lista_inserir(ptr_no lista);
void lista_mostrar(ptr_no lista);

//Função principal
int main() {
    op = 1;

    lista = (ptr_no)malloc(sizeof(no));
    lista->dado = 0;
    lista->proximo = NULL;

    while (op != 0) {
        system("cls");
        menu_mostrar();
        scanf("%d", &op);
        menu_selecionar(op);
    }
    system("Pause");
    return 0;
}

void menu_mostrar() {
    lista_mostrar(lista);
    printf("\n\nEscolha uma opcao:\n");
    printf("1- Adicionar elemento.\n");
    printf("0- Sair.\n");
}

void lista_mostrar(ptr_no lista) {
    system("cls");
    while (lista->proximo != NULL) {
        printf("%d, ", lista->dado);
        lista = lista->proximo;
    }
    printf("%d", lista->dado);
}

void menu_selecionar(int op) {
    switch (op) {
        case 1:
            lista_inserir(lista);
        break;
    }
}

void lista_inserir(ptr_no lista) {
    while (lista->proximo != NULL) {
        lista = lista->proximo;
    }
    lista->proximo = (ptr_no)malloc(sizeof(no));
    lista = lista->proximo;
    lista->dado = 1;
    lista->proximo = NULL;
}