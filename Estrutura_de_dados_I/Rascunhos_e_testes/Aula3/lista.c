#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Definindo a estrutura da lista
struct no {
    int dado;
    struct no *proximo;
};

//Definindo variaveis
typedef struct no no;
typedef no *ptr_no;
ptr_no lista;
int op;

//Prototipacao
void mostrar_menu();
void selecao_menu(int op);
void mostrar_no();
void add_elemento(ptr_no lista);

//Funcao principal
int main() {
    //Inicalizando maquina de numeros randomicos
    srand(time(NULL));

    op = 1;
    //Criando o primeiro no de lista
    lista = (ptr_no)malloc(sizeof(no));
    lista->dado = 0;
    lista->proximo = NULL;

    //Criando loop de execucao do programa
    while(op != 0){
        system("cls || clear");
        //Mostrando menu
        mostrar_menu();
        scanf("%d", &op);
        //Captando selecao do menu
        selecao_menu(op);
    }

    system("Pause");
    return 0;
}

void mostrar_no(ptr_no lista) {
    system("cls || clear");
    while(1) {
        printf("[");
        printf(" %d ", lista->dado);
        printf("]");
        if (lista->proximo == NULL) {
            break;
        }
    }
}


void mostrar_menu() {
    mostrar_no(lista);
    printf("\n");
    printf("Escolha uma das opcoes abaixo: \n");
    printf("1- Adicionar elemento.\n");
    printf("2- Excluir elemento.\n\n");
    printf("0- Sair.\n\n");
}

void selecao_menu(int op) {
    switch(op) {
        case 1:
            add_elemento(lista);
        break;
//        case 2:
//            rm_elemento();
//        break;
        case 0:
            printf("O programa esta sendo fechado.\n");
        break;
    }
}

void add_elemento(ptr_no lista){
    while (lista->proximo != NULL) {
        lista = lista->proximo;
    }
    lista->proximo = (ptr_no) malloc(sizeof(no));
    lista = lista->proximo;
    lista->dado = rand()%100;
    lista->proximo = NULL;
}