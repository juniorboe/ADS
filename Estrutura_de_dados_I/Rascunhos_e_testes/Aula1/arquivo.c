#include <stdio.h>

int main(){
    int list[5] = {7, 8, 6, 4, 1};
    int *pont = list;

    printf("%d\n", *pont + 2);
    printf("%d\n", *(pont + 2));
    printf("%d\n", *(pont + 1));
    printf("%d\n", pont[2]);
    printf("%d\n", *pont++);
    printf("%d\n", (*pont)++);

    return 0;
}