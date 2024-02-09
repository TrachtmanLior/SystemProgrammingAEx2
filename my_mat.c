#include "my_mat.h"
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

void getMatrix(int** matrix, int size){

    for(int i=0;i<size;i++){
        for(int j=0; j<size;j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}

void floydWarshallAlgorithm(int** matrix, int size){
    for(int k=0;k<size;k++){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(matrix[i][j] > matrix[i][k] + matrix[k][j]
                    && matrix[i][k] != INFINITY && matrix[k][j] != INFINITY){
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
}

int existPath(int** matrix, int i , int j, int size){
    floydWarshallAlgorithm(matrix, size);
    return (matrix[i][j] != INFINITY && matrix[i][j] != 0);
}

int shortestPath(int** matrix, int i , int j, int size){
    floydWarshallAlgorithm(matrix, size);
    return matrix[i][j];
}
