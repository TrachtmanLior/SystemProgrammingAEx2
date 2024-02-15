#include <stdio.h>


#define CAPACITY 20
#define ITEMS 5

typedef struct
{
    char letter;
    int weight;
    int value;
} Items;

//INIT
int max(int,int);
int knapSack(Items[], int[]);




int main(){
    //create array of 5 items that has weight and values(b)
    Items item[CAPACITY];
    int result[ITEMS] = {0};
    for(int i=0;i<ITEMS;i++){
        scanf("%c%d%d", &item[i].letter,  &item[i].value, &item[i].weight);
    }

    printf("Max profit is: %d\n", knapSack(item, result));

    for(int i=0;i<ITEMS;i++){
        if(result[i] == 1){
             printf("%c", item[i].letter);
        }
    }

    return 0;
}


int max(int a, int b){
    return (a>b) ? a:b;
}

int knapSack(Items item[], int result[]){
    int dp[ITEMS+1][CAPACITY+1];
    int i,j;

    for(i=0;i <= ITEMS; i++){
        for(j=0; j<= CAPACITY; j++){
            //weight limit is 0 or there are no items to choose
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            // found space to store an item
            else if(item[i-1].weight <= j){
                dp[i][j] = max(dp[i-1][j] ,item[i-1].value + dp[i-1][j - item[i-1].weight]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    i=ITEMS;
    j=CAPACITY;

    while(i>0 && j>0){
        //added the item
        if(dp[i][j] > dp[i-1][j]){
            result[i-1] = 1;
            j-=item[i-1].weight;
            i--;
        }
        //didn't add the item
        else{
            result[i-1] = 0;
            i--;
        }
    }
    return dp[ITEMS][CAPACITY];
}
