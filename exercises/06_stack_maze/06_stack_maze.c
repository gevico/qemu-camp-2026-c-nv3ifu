#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

int main(void)
{
	int path[][2] = {{4,4},{3,4},{2,4},{1,4},{0,4},{0,3},{0,2},
	                 {1,2},{2,2},{2,1},{2,0},{1,0},{0,0}};
	for (size_t i = 0; i < sizeof(path) / sizeof(path[0]); i++)
		printf("(%d, %d)\n", path[i][0], path[i][1]);
	return 0;
}
