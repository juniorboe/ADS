#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Constantes
#define tamanho 20

//Estrutura da senha
typedef struct tsenha {
    int numero;
    char tipo;
} tsenha;

//Estrutura da fila
struct tfilabanco {
    tsenha dados[tamanho];
    int ini;
    int fim;
};

//Variaveis globais
struct tfilabanco fila;
int op, proximo;

//Prototipacao
void fila_entrar(); //Entra na fila
void fila_sair(); //Retira da fila
void fila_mostrar(); //Mostra fila
void menu_mostrar(); //Mostra o menu

//Funcao principal
int main() {
    setlocale(LC_ALL, "Portuguese");
    op = 1;
    proximo = 1;
    fila.ini = 0;
    fila.fim = 0;
    while(op != 0) {
        system("cls || clear");
        fila_mostrar();
        menu_mostrar();
        scanf("%d", &op);
        switch(op) {
            case 1:
                fila_entrar();
                break;
            case 2:
                fila_sair();
                break;
        }
    }

    return 0;
}

//Remover o primeiro elemento da Fila de acordo com o caixa
void fila_sair() {
    if (fila.ini == fila.fim) {
        printf("\nFila vazia, mas logo aparece alguem!\n\n");
        system("pause");
    } else {
        int caixa;
        char tipoAtendimento;
        printf("\nQual caixa vai atender (1 a 4): ");
        scanf("%d", &caixa);
        switch(caixa) {
            case 1:
                tipoAtendimento = 'P';
                break;
            case 2:
            case 3:
                tipoAtendimento = 'C';
                break;
            case 4:
                tipoAtendimento = 'R';
                break;
            default:
                printf("\nValor invalido!");
                return;
        }
        //Define a posicao do elemento a ser removido como 0
        int posicao = 0;

        //Procura elemento do tipo correspondente
        for (int i = 0; i < tamanho; i++) {
            if (fila.dados[i].tipo == tipoAtendimento) {
                posicao = i;
                break;
            }
        }

        printf("\n\n##### ATENDIMENTO #####\n");
        printf("Senha: %c- %d\n", fila.dados[posicao].tipo, fila.dados[posicao].numero);
        printf("Caixa: %c\n", caixa);
        printf("##### ATENDIMENTO #####\n\n");

        //Retira elemento da posicao e move os demais
        for (int i = posicao; i < tamanho; i++) {
            fila.dados[i].numero = fila.dados[i+1].numero;
            fila.dados[i].tipo = fila.dados[i+1].tipo;
        }
        fila.dados[fila.fim].numero = 0;
        fila.dados[fila.fim].tipo = ' ';
        fila.fim--;
    }
}

//Adicionar um elemento no final da fila
void fila_entrar() {
    if (fila.fim == tamanho) {
        printf("A fila esta cheia, volte outro dia!\n\n");
        system("pause");
        return;
    }

    char tipo;
    printf("\nEscolha o tipo de atendimento:");
    printf("\nC - Comum.");
    printf("\nP - Prioritario.");
    printf("\nR - Rapido.\n");
    scanf(" %c", &tipo);
    if (tipo != 'C' && tipo != 'P' && tipo != 'R') {
        printf("\nTipo de atendimento invalido!\n\n");
        return;
    }
    fila.dados[fila.fim].tipo = tipo;
    fila.dados[fila.fim].numero = proximo;
    proximo++;
    fila.fim++;
}

//Mostrar o menu de opcoes
void menu_mostrar() {
    printf("\nEscolha uma opcao: \n");
    printf("1- Nova senha.\n");
    printf("2- Atender.\n");
    printf("0- Sair.\n\n");
}

//Mostrar o conteudo da fila
void fila_mostrar() {
    int i;
    printf("[ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%c-%d ", fila.dados[i].tipo, fila.dados[i].numero);
    }
    printf(" ]\n\n");
}
