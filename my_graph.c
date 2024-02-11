#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"

int main(){

    int i,j;
    char operator;
    int matrix[SIZE][SIZE];
    bool didAlgoRun = false;
    bool finished = false;


    while(!finished){
        printf("Enter a letter from A to D\n");
        scanf("%c", &operator);
        if (operator != ' ' && operator != 'D' && operator != EOF && operator != 'A'){
            printf("\n");
        }

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

            case EOF:
            case 'D':
                printf("\n");
                finished = true;
                break;

        }
    }

    return 0;
}