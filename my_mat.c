#include "my_mat.h"
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

void getMatrix(int matrix[][SIZE], int size){

    for(int i=0;i<size;i++){
        for(int j=0; j<size;j++){
            printf("enter a number value for matrix[%d][%d]\n",i,j);
            scanf("%d", &matrix[i][j]);
            if(matrix[i][j] == 0)
                matrix[i][j] = INFINITY;
        }
    }
}

void floydWarshallAlgorithm(int matrix[][SIZE], int size){
    for(int k=0;k<size;k++){
        for(int i=0;i<size;i++){
            if(i!=k){
                for(int j=0;j<size;j++){
                    //no reason to check col k and no reason to check diagnonal of matrix(i=j,NO PATH)
                    if(matrix[i][j] > matrix[i][k] + matrix[k][j]
                    && matrix[i][k] != INFINITY && matrix[k][j] != INFINITY && j!=k && i!=j){
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }
    }
}

int existPath(int matrix[][SIZE], int i , int j, int size){
    floydWarshallAlgorithm(matrix, size);
    return (matrix[i][j] != INFINITY);
}

int shortestPath(int matrix[][SIZE], int i , int j, int size){
    floydWarshallAlgorithm(matrix, size);
    return (matrix[i][j] != INFINITY) ? matrix[i][j]:0;
}
