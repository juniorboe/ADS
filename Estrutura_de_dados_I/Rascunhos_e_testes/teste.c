#include <stdio.h>

void updatePtr(int *p);

int main(){
    int x = 10;
    int *ptr;
    ptr = &x;

    printf("endereco de x = %p\n", &x);
    printf("endereco de ptr = %p\n", ptr);
    printf("valor de x = %d\n", x);
    printf("valor apontado por ptr = %d\n\n", *ptr);

    updatePtr(&x);

    printf("valor atualizado de ptr = %d\n", *ptr);
    printf("valor de x depois da atualizacao de ptr = %d\n", x);
}

void updatePtr(int *p){
    *p += 5;
}