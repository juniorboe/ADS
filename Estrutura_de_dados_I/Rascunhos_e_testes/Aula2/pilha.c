#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Constantes
#define tamanho 5

//Estrutura de pilha
struct tpilha {
    int dados[tamanho];
    int ini;
    int fim;
};

//Variaveis globais
struct tpilha pilha;
int op;

//Prototipacao
void push();
void pop();
void show();
void menu();

//Funcao principal
int main() {
    pilha.ini = 0;
    pilha.fim = 0;

    op = 1;
    while (op != 0){
        system("cls");
        show();
        menu();
        
        scanf("%d", &op);
        switch(op) {
            case 1:
                push();
            break;
            case 2:
                pop();
            break;
            default:
                printf("O programa esta sendo fechado.");
            break;
        }
    }

    return 0;
}

//funcao menu
void menu() {
    printf("Digite uma opcao: \n");
    printf("1- Empilhar.\n");
    printf("2- Desempilhar.\n");
    printf("0- Sair.\n\n");  
}

//funcao show
void show() {
    int i;
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf(" %d ", pilha.dados[i]);
    }
    printf("]\n\n");
}

//funcao push
void push() {
    if (pilha.fim == tamanho){
        printf("Operacao invalida! Pilha cheia.\n\n");
        system("pause");
    }
    else {
        printf("Digite o dado a ser empilhado: ");
        scanf("%d", &pilha.dados[pilha.fim]);
        pilha.fim++;
    }
}

//funcao pop
void pop() {
    if (pilha.fim == pilha.ini) {
        printf("Operacao invalida! Pilha vazia.\n\n");
        system("pause");
    }
    else {
        pilha.dados[pilha.fim-1] = 0;
        pilha.fim--;
    }
}
