#include <iostream>
#include <vector>
#include <time.h>
#include <string>

void showArray(std::vector <std::vector <int>> &array) {
	int N = array.size();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
				std::cerr << array[i][j] << ' ';
		}
		std::cerr << std::endl;
	}
	std::cerr << "--------------------------------------" << std::endl;
}
//overload
void showArray(std::vector <std::vector <int>> &array, int x, int y) {
	int N = array.size();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (x == j && y == i) {
				std::cerr << "C" << ' ';
			}
			else {
				std::cerr << array[i][j] << ' ';
			}
		}
		std::cerr << std::endl;
	}
	std::cerr << "--------------------------------------" << std::endl;
}

void executionTime(clock_t start, std::string function_name = "NULL") {
	clock_t end = clock();
	double seconds = (double)(end - double(start)) / CLOCKS_PER_SEC;
	if (function_name == "NULL")
	{
		printf("[TIME]%f SECONDS ELAPSED\n", seconds);
	}
	else {
		std::cerr << "[TIME][" << function_name << "]" << seconds << " SECONDS ELAPSED" << std::endl;
	}
}