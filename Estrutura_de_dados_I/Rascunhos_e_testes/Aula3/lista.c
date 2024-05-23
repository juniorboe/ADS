#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Criando estrutura de nó
typedef struct no {
    int data;
    struct no *nxt;
} no;

//Criando variáveis
typedef no *pt;
pt list; //Criando a variável que apontará para o primeiro nó
int op; //Variável de controle do laço while da main()

//Prototipação
void show_menu();
void show_list(pt list);
void add_data(pt list);
void rm_data(pt data);
void select_menu(int op);

//Função principal
int main() {
    //Inicializando o randomizador
    srand(time(NULL));
    //Criando o primeiro nó e apontando list para ele
    list = (pt)malloc(sizeof(no)); //Alocando espaço para o nó e apontando list para ele
    list->data = 0;
    list->nxt = NULL;

    //Criando laço while para rodar o programa
    op = 1;
    while (op != 0) {
        system("cls || clear");
        show_menu();
        scanf("%d", &op);
        select_menu(op); 
    }
    return 0;
}

//Tratamento de funções
void show_menu() {
    show_list(list);
    printf("\n\nEscolha uma opcao: \n");
    printf("1- Adicionar elemento.\n");
    printf("2- Remover elemento.\n");
    printf("0- Sair.\n");
}

void show_list(pt list) {
    while (list->nxt != NULL) {
        printf("%d, ", list->data);
        list = list->nxt;
    }
    printf("%d", list->data);
}

void select_menu(int op) {
    switch (op) {
        case 1:
            add_data(list);
            break;
        case 2:
            rm_data(list);
            break;
    }
}

void add_data(pt list) {
    while (list->nxt != NULL) {
        list = list->nxt;
    }
    int new_data;
    printf("Digite um numero.");
    scanf("%d", &new_data);
    list->nxt = (pt)malloc(sizeof(no)); //Cria um novo nó para adicionar à lista
    list = list->nxt;
    list->data = new_data;
    list->nxt = NULL;
}

void rm_data(pt list) {
    int data_remove;
    pt atual;
    atual = (pt)malloc(sizeof(no));
    printf("Qual numero voce quer remover da lista?\n");
    scanf("%d", &data_remove);
    while (list->nxt != NULL) {
        if (list->data == data_remove) {
            atual->nxt = list->nxt;
        }
        atual = list;
        list = list->nxt;
    }
    if (list->data == data_remove) {
        atual->nxt = NULL;
    }
}
