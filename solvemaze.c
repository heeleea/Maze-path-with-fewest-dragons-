#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 4
#define IMPOSSIBLE N*(N+1)
enum {WALL, EMPTY, VISITED, DRGAON};
int solvemaze(int maze[N][N], int start_row, int start_col, int dragon_counter);

void main() 
{	
	int maze[N][N] = {{1,1,3,3},                        
					{3,0,1,1},
					{3,0,0,0},
					{1,3,3,1}};
	
	/*
		int maze[N][N] = {{1,1,3,3},                        
					{3,0,1,1},
					{3,0,0,1},
					{1,3,3,1}};
	*/

	int res = solvemaze(maze, 0, 0, 0);
	printf("The path with the least dragons has an amount of %d dragons\n", res);
}


int solvemaze(int maze[N][N], int start_row, int start_col, int dragon_counter)
{
	int up, down, left, right = IMPOSSIBLE;
	int min_dragons = IMPOSSIBLE;

	if (maze[start_row][start_col] == WALL)
		return 0;

	if (maze[start_row][start_col] == VISITED)
		return 0;
	
	if (maze[start_row][start_col] == DRGAON)
		dragon_counter++;

	if ((start_row == N - 1) && (start_col == N - 1))
		return dragon_counter;

	maze[start_row][start_col] = VISITED;

	// move up
	if (start_row > 0) 
	{
		up = solvemaze(maze, start_row -1, start_col, dragon_counter);
		if (up && up < min_dragons)
			min_dragons = up;
	}

	// move down 
	if (start_row < N-1) {
		down = solvemaze(maze, start_row +1, start_col, dragon_counter);
		if (down && down < min_dragons)
			min_dragons = down;
	}

	// move left
	if (start_col > 0) 
	{
		left = solvemaze(maze, start_row, start_col - 1, dragon_counter);
		if (left && left < min_dragons)
			min_dragons = left;
	}

	// move right
	if (start_col < N - 1) 
	{
		right = solvemaze(maze, start_row, start_col + 1, dragon_counter);
		if (right && right < min_dragons)
			min_dragons = right;
	}

	return min_dragons;
}

