#include <stdio.h>
#include <string.h>

#define tamanho 5

char s[20];

struct tpilha {
    char dados[tamanho][20];
    int ini;
    int fim;
};

struct tpilha pilha;

void push(char *tarefa);
void pop();

int main() {
    push("Desenhar quadrado");
    pop();

    int i;
    for (int i = 0; i < tamanho; i++) {
        printf("%s, ", &pilha.dados[i]);
    }
    printf("\n");

    return 0;
}

void push(char *tarefa) {
    strcpy(pilha.dados[pilha.fim], tarefa);
    pilha.fim++;
}

void pop() {
    strcpy(pilha.dados[pilha.fim-1], "");
    pilha.fim--;
}
