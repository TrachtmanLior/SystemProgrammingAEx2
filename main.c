#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"

int main(){

    int i,j;
    char operator;

    // Allocate memory
    int **matrix = (int**) malloc(SIZE * sizeof(int*));

    for (int i = 0; i < SIZE; ++i)
        matrix[i] = (int*) malloc(SIZE * sizeof(int));

    scanf("%c", &operator);

    switch(operator){
        case 'A':
            getMatrix(matrix, SIZE);
            break;

        case 'B':
            scanf("%d%d", &i, &j);
            printf("%s\n", existPath(matrix, i, j, SIZE) ? "True":"False");
            break;
        case 'C':
            scanf("%d%d", &i, &j);
            printf("%d\n", shortestPath(matrix, i, j, SIZE));
            break;
        case 'D':
            break;

    }

    // Free memory to end program
    for (int i = 0; i < SIZE; ++i)
        free(matrix[i]);

    free(matrix);

    return 0;
}