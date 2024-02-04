
all: connections

connections: main.c my_mat.h my_mat.c
	gcc main.c -o connections

clean:
	rm connections