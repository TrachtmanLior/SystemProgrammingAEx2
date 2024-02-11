#ifndef MY_MAT_H
#define MY_MAT_H
#define SIZE 10
#define INFINITY INT_MAX

//case A get a matrix[i][j]
void getMatrix(int[][SIZE], int);

//case B check for a path from i to j
int existPath(int[][SIZE], int, int, int);

//case C find shortestpath from i to j
int shortestPath(int[][SIZE], int, int, int);

//Algorithm to find shortest path
void floydWarshallAlgorithm(int[][SIZE], int);


#endif