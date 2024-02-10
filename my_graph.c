#include <stdio.h>
#include "my_mat.h"
#include <stdbool.h>

int main(){

    int i,j;
    char operator;

    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    bool didAlgoRun = false;        // Tell us if the Floyd's algo already ran for the current matrix - so we don't run it again

    scanf("%c", &operator);

    // Assuming the user enters values to matrix (A) before trying B or C
    switch(operator){
        case 'A':
            getMatrix(matrix, MATRIX_SIZE);
            didAlgoRun = false;
            break;
        case 'B':
            scanf("%d%d", &i, &j);
            if (!didAlgoRun) {
                floydWarshallAlgorithm(matrix, MATRIX_SIZE);
                didAlgoRun = true;
            }
            printf("%s\n", existPath(matrix, i, j, MATRIX_SIZE) ? "True":"False");
            break;
        case 'C':
            scanf("%d%d", &i, &j);
            if (!didAlgoRun) {
                floydWarshallAlgorithm(matrix, MATRIX_SIZE);
                didAlgoRun = true;
            }            
            printf("%d\n", shortestPath(matrix, i, j, MATRIX_SIZE));
            break;
        case EOF:
        case 'D':
            break;
    }

    return 0;
}
