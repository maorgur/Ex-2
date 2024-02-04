#define POINTS 10

#include "my_mat.h"
#include <stdio.h>

void create_Floyd_Warshall_graph(int graph[POINTS][POINTS]){
    //set invalid bridges to infinite weight
    for (int i = 0; i < POINTS * POINTS; i++){
        if (graph[i/POINTS][i%POINTS] <= 0 && i/POINTS != i%POINTS){
            graph[i/POINTS][i%POINTS] = 9999;
        } 
    }

    //run the alogritham on graph
    for (int graph_index = 0; graph_index < POINTS; graph_index++){
        for (int src_point = 0; src_point < POINTS; src_point++){
            for (int dst_point = 0; dst_point < POINTS; dst_point++){
                //check if to change
                if (src_point != graph_index && dst_point != graph_index){
                    //check if there is a shorter path
                    if (graph[src_point][graph_index] + graph[graph_index][dst_point] < graph[src_point][dst_point]){
                        //check if didn't went through a 0 (0 means there is no path)
                        graph[src_point][dst_point] = graph[src_point][graph_index] + graph[graph_index][dst_point];
                    }
                }
            }
        }
    }
}

void check_if_reachable(int graph[POINTS][POINTS], int src, int dest){
    if (distance_in_graph(graph, src, dest) > 0 && src != dest){
        printf("True\n");
    } else {
        printf("False\n");
    }
}

int distance_in_graph(int graph[POINTS][POINTS], int src, int dest){
    if (graph[src][dest] > 0 && graph[src][dest] < 9999){
        return graph[src][dest];
    } else {
            return -1;
        }
    }