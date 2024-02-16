#include <stdio.h>

#define NUM_OF_ITEMS 5
#define MAX_WEIGHT 20

typedef struct
{
    char letter;
    int weight;
    int value;
    // bool chosen;
} Item;

void addItems(Item[], int);
int getBestKnapsack(Item[], int, int, int[]);
int max(int, int);

int main() {
    Item items[NUM_OF_ITEMS];
    int result[NUM_OF_ITEMS] = {0};           // 1 - item was chosen, 0 - item wasn't chosen

    addItems(items, NUM_OF_ITEMS);

    printf("Maximum profit: %d\n", getBestKnapsack(items, NUM_OF_ITEMS, MAX_WEIGHT, result));

    printf("Selected items:");
    for (int i = 0; i < NUM_OF_ITEMS; i++){
        if (result[i] == 1){
            printf(" %c", items[i].letter);
        }
    }

    return 0;
}

/* Add items to given items arrays, of size "size" */
void addItems(Item items[], int size){
    for (int i = 0; i < size; i++){
        scanf(" %c %d %d", &items[i].letter, &items[i].value, &items[i].weight);
    }
}

/* Gets an array of items, it's size and the maximum weight allowed in the knapsack,
and a "result" array to return the selected items. Returns the max profit.
Using Dynamic Programming, see more: https://en.wikipedia.org/wiki/Knapsack_problem .
*/
int getBestKnapsack(Item items[], int numOfItems, int maxWeight, int result[]){
    int dp[numOfItems+1][maxWeight+1];       // Used for Dynamic Programming
    int i, j;

    // i represents an item (num of available items), j represents the available weight in the bag
    // row 'i' in "dp" represents cell 'i-1' in items/result
    for (i = 0; i <= numOfItems; i++){
        for (j = 0; j <= maxWeight; j++){
            // No space for items || No items to put inside => 0 Profit
            if (i == 0 || j == 0){
                dp[i][j] = 0;
            }
            // There is space in the bag to include item i
            else if(items[i-1].weight <= j){
                // Check if it's better to include it or not
                dp[i][j] = max(dp[i-1][j-items[i-1].weight] + items[i-1].value, dp[i-1][j]);
            }
            // Not enough space in the bag - don't include item
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    i = numOfItems;
    j = maxWeight;

    // Trace chosen items (i and j start at the bottom left of the table)
    while (i > 0 && j > 0){
        if (dp[i-1][j] != dp[i][j]){
            // Item was chosen, go to the point before choosing it
            result[i-1] = 1;
            j -= items[i-1].weight;
            i--;
        }
        else{
            // Item wasn't chosen, go to the item above and check there
            result[i-1] = 0;
            i--;
        }
    }

    return dp[numOfItems][maxWeight];
}

int max(int a, int b){
    return (a < b) ? b : a;
}
