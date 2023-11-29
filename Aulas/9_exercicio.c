//Testando ponteiros:

#include <stdio.h>
#include <stdlib.h>

int main() {
    // int vet[5] = {1, 2, 3, 4, 5};
    // int *p = vet;

    // for (int i = 0; i < 5; i++) {
    //     printf("%d  ", p[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < 5; i++) {
    //     printf("%d  ", *(p+i));
    // }

    // printf("\n===========================\n");

    // int mat[2][2] = {{1, 2},{3, 4}};
    // for (int i = 0; i < 2; i++) {
    //     for (int j = 0; j < 2; j++) {
    //         printf("%d  ", mat[i][j]);
    //     }
    // }
    // printf("\n");
    // int mat2[2][2] = {{1, 2},{3, 4}};
    // int *p1 = &mat2[0][0];
    // for (int i = 0; i < 4; i++) {
    //     printf("%d  ", *(p1+i));
    // }

    int x = 10;
    int *p1 = &x;
    int **p2 = &p1;

    printf("====================\n");
    printf("p2: %d\n", p2);
    printf("&p1: %d\n", &p1);
    printf("====================\n");
    printf("*p2: %d\n", *p2);
    printf("&x: %d\n", &x);
    printf("====================\n");
    printf("**p2: %d\n", **p2);
    printf("x: %d\n", x);
    printf("====================\n");
    printf("&p2: %d\n", &p2);
    printf("====================\n");

    return 0;
}