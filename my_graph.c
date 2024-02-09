#define POINTS 10

#include <stdio.h>
#include "my_mat.h"
#include "my_mat.c"

int main(){
    char mode = 'a'; //override garabage that can lead to problems
    int graph[10][10];
    int current_cell;
    int i, j;
    int result;
    while (mode != 'D' && mode != EOF){
        scanf("%c", &mode);

        switch (mode)
        {
        case 'A':
            //read numbers from user
            current_cell = 0;
            for (int i = 0; i < POINTS * POINTS; i++){
                scanf("%d", &graph[current_cell/POINTS][current_cell%POINTS]);
                current_cell++;
            }
            create_Floyd_Warshall_graph(graph);
            break;
        
        case 'B':
            scanf("%d", &i);
            scanf("%d", &j);
            check_if_reachable(graph, i, j);
            break;
        case 'C':
            scanf("%d", &i);
            scanf("%d", &j);
            result = distance_in_graph(graph, i, j);
            printf("%d\n", result);
            break;
        default:
            break;
        }


    }
    return 0;
}