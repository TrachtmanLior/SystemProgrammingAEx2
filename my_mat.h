#ifndef MY_MAT_H
#define MY_MAT_H
#define SIZE 10
#define INFINITY INT_MAX

//case A get a matrix[i][j]
void getMatrix(int**, int);

//case B check for a path from i to j
int existPath(int**, int, int, int);

//case C find shortestpath from i to j
int shortestPath(int**, int, int, int);


#endif