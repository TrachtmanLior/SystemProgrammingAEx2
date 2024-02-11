#include "my_mat.h"
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

void getMatrix(int matrix[][MATRIX_SIZE], int size){
    for(int i=0;i<size;i++){
        for(int j=0; j<size;j++){
            scanf("%d", &matrix[i][j]);
            // 0 in matrix means no path between i and j, set it to NO_PATH to make it easier for the algo
            if (matrix[i][j] == 0)
                matrix[i][j] = NO_PATH;
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
                    // no reason to check col k and no reason to check diagonal of matrix (always NO_PATH)
                    if (j != k && i!=j){
                        if(matrix[i][k] != NO_PATH && matrix[k][j] != NO_PATH
                        && (matrix[i][j] > matrix[i][k] + matrix[k][j])){
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
    // a path to yourself always exists
    return (matrix[i][j] != NO_PATH);
}

/* Assuming Floyd's algorithm has already been done.
Returns the shortest path betweeen i and j in matrix.
*/
int shortestPath(int matrix[][MATRIX_SIZE], int i , int j, int size){
    return matrix[i][j] != NO_PATH ? matrix[i][j] : -1;
}
