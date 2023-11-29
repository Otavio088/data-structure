//realocação.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int *p = malloc(5*sizeof(int));
    
    for (i = 0; i < 5; i++) {
        p[i] = i+1;
    }

    for (i = 0; i < 5; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
    //Diminui o tamanho do array:
    p = realloc(p, 3*sizeof(int));
    for (i = 0; i < 3; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
    //Aumenta o tamanho doa array:
    p = realloc(p, 10*sizeof(int));
    for (i = 5; i < 10; i++) {
        p[i] = i+1;
    }
    for (i = 0; i < 10; i++) {
        printf("%d ", p[i]);
    }

    free(p);

    return 0;
}