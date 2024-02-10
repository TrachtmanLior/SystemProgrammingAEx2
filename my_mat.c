#include "my_mat.h"
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

void getMatrix(int matrix[][MATRIX_SIZE], int size){
    for(int i=0;i<size;i++){
        for(int j=0; j<size;j++){
            while (scanf("%d", &matrix[i][j]) != 1){
                printf("Please re-enter a value!");
            }
        }
    }
}

/* In each cell [i][j] of matrix, this function sets the shortest path
(INFINITY if path doesn't exist), between i and j.
using Floyd-Warshall's algorithm: https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
*/
void floydWarshallAlgorithm(int matrix[][MATRIX_SIZE], int size){
    // Run through every vortex, and set new value if there is a shorter path through this vortex
    for(int k=0;k<size;k++){
        for(int i=0;i<size;i++){
            // no reason to check row k
            if (i != k) {
                for(int j=0;j<size;j++){
                    // no reason to check col k and no reason to check diagonal of matrix (always 0)
                    if (j != k || i==j){
                        if(matrix[i][j] > matrix[i][k] + matrix[k][j]){
                            matrix[i][j] = matrix[i][k] + matrix[k][j];
                        }
                    }
                    
                }
            }
            
        }
    }
}

/* Assuming Floyd's algorithm has already been done.
Returns if there is a path between i and j in matrix.
*/
int existPath(int matrix[][MATRIX_SIZE], int i , int j, int size){
    return (matrix[i][j] != INFINITY);
}

/* Assuming Floyd's algorithm has already been done.
Returns the shortest path betweeen i and j in matrix.
*/
int shortestPath(int** matrix, int i , int j, int size){
    return matrix[i][j];
}
