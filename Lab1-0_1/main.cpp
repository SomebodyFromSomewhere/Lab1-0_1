#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include "utils/utils.h"


int N = 0;
int wall_count = 0;

void setBorders(std::vector <std::vector <int>>& maze) {
	//sets borders
	for (int i = 0; i < N + 2; i++)
	{
		maze[0][i] = 1;
		maze[i][0] = 1;
		maze[i][N + 1] = 1;
		maze[N + 1][i] = 1;
	}
	//sets corners empty: 0 - empty, 1 - border, . - e.t.c.
	// 0 0 1 .
	// 0 0 0 .
	// 1 0 0 .
	// . . . .

	//empty corners
	maze[0][0] = 5;
	maze[1][0] = 5;
	maze[0][1] = 5;
	maze[N][N + 1] = 5;
	maze[N + 1][N] = 5;
	maze[N + 1][N + 1] = 5;
}

void countWalls(std::vector <std::vector <int>>& array, int x, int y) {
	//check right
	if (x + 1 < N + 2) {
		if (array[y][x + 1] == 1) {
			wall_count++;
			array[y][x + 1] = 2;
		}
	}

	//check down
	if (y + 1 < N + 2) {
		if (array[y + 1][x] == 1) {
			wall_count++;
			array[y + 1][x] = 2;
		}
	}

	//check up
	if (y - 1 >= 0) {
		if (array[y - 1][x] == 1) {
			wall_count++;
			array[y - 1][x] = 2;
		}
	}

	//check left
	if (x - 1 >= 0) {
		if (array[y][x - 1] == 1) {
			wall_count++;
			array[y][x - 1] = 2;
		}
	}
}

void DFS(std::vector <std::vector <int>> &array, int x, int y) {
	//Sleep(1000);
	showArray(array, x, y);
	//check right
	if (x + 1 < N + 2) {
		if (array[y][x + 1] == 0) {
			array[y][x] = 3;
			countWalls(array, x, y);
			DFS(array, x + 1, y);
		}
	}
	
	//check down
	if (y + 1 < N + 2) {
		if (array[y + 1][x] == 0) {
			array[y][x] = 3;
			countWalls(array, x, y);
			DFS(array, x, y + 1);
		}
	}

	//check up
	if (y - 1 >= 0) {
		if (array[y - 1][x] == 0) {
			array[y][x] = 3;
			countWalls(array, x, y);
			DFS(array, x, y - 1);
		}
	}

	//check left
	if (x - 1 >= 0) {
		if (array[y][x - 1] == 0) {
			array[y][x] = 3;
			countWalls(array, x, y);
			DFS(array, x - 1, y);
		}
	}
	countWalls(array, x, y);
	array[y][x] = 3;
}

int main() {
	clock_t start = clock();
	std::ifstream file("INPUT.txt");
	file >> N;
	std::vector <std::vector <int>> maze(N + 2, std::vector <int>(N + 2));
	setBorders(maze);

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++) {
			char val;
			file >> val;
			maze[i][j] = val == '.' ? 0 : 1;
			std::cerr << maze[j][i] << ' ';
		}
		std::cerr << std::endl;
	}
	showArray(maze);
	DFS(maze, 1, 1);
	showArray(maze);
	std::cerr << wall_count << std::endl;
	executionTime(start);
	return 0;
}