#include <stdio.h>
#include "my_mat.h"

int main(){

    int i,j;
    char operator;

    int matrix[MATRIX_SIZE][MATRIX_SIZE];

    scanf("%c", &operator);

    switch(operator){
        case 'A':
            getMatrix(matrix, MATRIX_SIZE);
            break;
        case 'B':
            scanf("%d%d", &i, &j);
            floydWarshallAlgorithm(matrix, MATRIX_SIZE);
            printf("%s\n", existPath(matrix, i, j, MATRIX_SIZE) ? "True":"False");
            break;
        case 'C':
            scanf("%d%d", &i, &j);
            floydWarshallAlgorithm(matrix, MATRIX_SIZE);
            printf("%d\n", shortestPath(matrix, i, j, MATRIX_SIZE));
            break;
        case EOF:
        case 'D':
            break;
    }

    return 0;
}
