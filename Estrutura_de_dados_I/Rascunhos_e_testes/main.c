#include <stdio.h>
#include <stdlib.h>


int main(){
    //Passo 1
    int x;
    int *y;

    //Passo 2
    printf("Informe o valor de x(por exemplo: 25): ");
    scanf("%d", &x);
    
    //Passo 3
    y = &x;
    
    //Passo 4
    *y = 12;

    //Passo 5
    y = y + 1;

    //Passo 6
    *y += 5;

    //Passo 7
    printf("Conteudo de x: %d", x);
    
    return 0;
}

