#pragma once

#ifndef UTILS_H
#define UTILS_H

void showArray(std::vector <std::vector <int>> &maze);
void showArray(std::vector <std::vector <int>> &maze, int x, int y);
void executionTime(clock_t start, std::string function_name = "NULL");

#endif // UTILS_H