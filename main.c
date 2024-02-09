#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"

int main(){

    int i,j;
    char operator;

    // Allocate memory
    int **Matrix = (int**) malloc(SIZE * sizeof(int*));

    for (int i = 0; i < SIZE; ++i)
        Matrix[i] = (int*) malloc(SIZE * sizeof(int));

    scanf("%c", &operator);

    switch(operator){
        case 'A':
            getMatrix(Matrix, SIZE);
            break;

        case 'B':
            scanf("%d%d", &i, &j);
            break;
        case 'C':
            scanf("%d%d", &i, &j);
            break;
        case 'D':
            break;

    }

    return 0;
}