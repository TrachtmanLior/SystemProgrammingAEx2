#ifndef MY_MAT_H
#define MY_MAT_H
#define MATRIX_SIZE 10
#define INFINITY INT_MAX

//case A get a matrix[i][j]
void getMatrix(int[][MATRIX_SIZE], int);

//case B check for a path from i to j
int existPath(int[][MATRIX_SIZE], int, int, int);

//case C find shortestpath from i to j
int shortestPath(int[][MATRIX_SIZE], int, int, int);

//Algo to set shortest path in each cell
void floydWarshallAlgorithm(int[][MATRIX_SIZE], int size);


#endif