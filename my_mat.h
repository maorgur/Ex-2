#define POINTS 10

void create_Floyd_Warshall_graph(int graph[POINTS][POINTS]); //A

int distance_in_graph(int graph[POINTS][POINTS], int src, int dest); //B

void check_if_reachable(int graph[POINTS][POINTS], int src, int dest); //C