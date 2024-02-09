
CC=gcc
FLAGS= -Wall -g

all: my_graph my_Knapsack

my_graph: my_graph.c my_mat.h my_mat.c
	$(CC) $(FLAGS) my_graph.c -o $@

my_Knapsack: my_Knapsack.c
	$(CC) $(FLAGS) my_Knapsack.c -o $@

clean:
	rm my_graph my_Knapsack