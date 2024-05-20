#include <stdio.h>

int main(){
//    int vetor[10];
//
//    for (int i = 0; i < 10; i++) {
//        printf("%d ", vetor[i]);
//    }
    int x;
    int *ptr;

    x = 10;
    printf("X: %d\n", x);
    ptr = &x;
    printf("Endereco apontado por ptr: %p\n", ptr);
    printf("Valor apontado por ptr: %d\n\n", *ptr);

    x = 12;
    ptr++;
    printf("Endereco apontado por ptr: %p\n", ptr);
    printf("Valor apontado por ptr: %d\n", *ptr);

    printf("Valor de X: %d\n", x);

    return 0;
}