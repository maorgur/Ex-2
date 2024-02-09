#include <stdio.h>

#define CAPACITY 20
#define ITEMS 5

int knapSackRec(int current_capacity, int weights[], int values[], int table[ITEMS][CAPACITY+1], int index){ //https://www.youtube.com/watch?v=xOlhR_2QCXY&ab_channel=CSDojo
    if (index < 0 || current_capacity <= 0){ //no more capacity in bag or done scanning all objects
        return 0;
    }
    if (table[index][current_capacity] != 0){ //already calculated
        return table[index][current_capacity];
    }

    if (weights[index] > current_capacity){ //adding this will be over the max weight, therefor ignore it and move to the next object
        return knapSackRec(current_capacity, weights, weights, table, index-1);
    } else {
        //compare between if adding the object or not, and select the most valuable
        int obj1 = knapSackRec(current_capacity, weights, values, table, index-1);
        int obj2 = knapSackRec(current_capacity-weights[index], weights, values, table, index-1) + values[index];
        if (obj1 > obj2){
            table[index][current_capacity] = obj1;
            return obj1;
        } else {
            table[index][current_capacity] = obj2;
            return obj2;
        }
    }
}


int knapSack(int weights[], int values[], int selected_bool[]){

    int table[ITEMS][CAPACITY+1];
    for (int j = 0; j < ITEMS; j++){ //fill table
        for (int w = 0; w <= CAPACITY; w++){
            table[j][w] = 0; //remove garbage data
            knapSackRec(w, weights, values,table, j);
        }
    }
    int max_value = table[ITEMS-1][CAPACITY];

    {//traceback the points used
        int current_capacity = CAPACITY;
        for (int i = ITEMS-1; i>0; i--){
            if (table[i][current_capacity] != table[i-1][current_capacity]){
                current_capacity -= weights[i];
                selected_bool[i] = 1;
                
            }
        }
        //check the first value
        if (table[0][current_capacity] > 0){
            selected_bool[0] = 1;

        }
    }
    return max_value;
    
}

int main(){
    int values[ITEMS];
    int weights[ITEMS];
    char names[ITEMS];
    
    //read values
    for (int i = 0; i < ITEMS; i++){
        scanf("%c", &names[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);
        if (names[i] == ' '){
            i--;
        }
    }

    int result[ITEMS]; //create boolean list to store the used objects
    for (int i = 0; i < ITEMS; i++){
        result[i] = 0;
    }

    int max_value = knapSack(weights, values, result); //calculate best value and the used objects

    //print result
    printf("Maximum profit: %d\n", max_value);

    printf("Selected items:");
    for (int i = 0; i < ITEMS; i++){
        if (result[i]){
            printf(" %c", names[i]);
        }
    }
    return 0;
}