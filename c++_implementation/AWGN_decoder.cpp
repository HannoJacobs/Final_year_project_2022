#pragma region
#pragma region
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <time.h>
#include <chrono>
#include <random>

using namespace std;
int base_mat[46][68] = {{15, 17, 6, 14, -1, 24, 23, -1, -1, 23, 15, 25, 8, 15, -1, 15, 7, -1, 10, 0, 15, 17, 1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {6, -1, 26, 16, 11, 8, -1, 2, 22, 26, -1, 11, 9, -1, 5, 25, 3, 27, -1, 13, -1, 6, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {9, 4, 15, -1, 1, 26, 27, 29, 2, 24, 8, -1, -1, 6, 11, 3, -1, 6, 5, 7, 20, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {8, 23, -1, 12, 10, -1, 13, 6, 6, -1, 1, 6, 22, 24, 17, -1, 20, 2, 25, -1, 22, 9, 1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {4, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {2, 21, -1, 17, -1, -1, -1, -1, -1, -1, -1, -1, 23, -1, -1, -1, 0, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {19, -1, -1, -1, -1, -1, 22, -1, -1, -1, 23, 10, -1, 2, -1, -1, -1, 27, 22, -1, 13, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {17, 26, -1, -1, 29, -1, -1, 2, 16, -1, -1, -1, -1, -1, 18, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {1, 15, -1, 21, -1, -1, -1, -1, -1, -1, -1, -1, 13, -1, -1, -1, 27, -1, -1, 25, -1, 19, 3, -1, 8, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {19, 12, -1, -1, -1, -1, -1, -1, -1, -1, 26, 11, -1, 17, -1, -1, -1, 2, 2, -1, 25, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, 26, 1, -1, 10, -1, -1, 20, 25, -1, -1, -1, -1, -1, 24, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {15, 25, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 14, -1, -1, -1, 1, -1, -1, -1, -1, 2, 15, 17, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {6, 5, -1, -1, -1, -1, -1, -1, -1, -1, 4, 0, -1, 8, -1, -1, -1, -1, 20, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {10, -1, -1, 5, -1, -1, -1, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 28, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 24, -1, -1, 2, 5, 12, -1, -1, -1, 16, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {9, 18, -1, -1, -1, -1, -1, -1, -1, -1, 10, -1, -1, 23, -1, -1, -1, -1, 22, -1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, 18, -1, 2, -1, -1, -1, -1, -1, -1, -1, 24, -1, -1, -1, -1, -1, -1, -1, -1, 5, -1, 25, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 22, -1, 16, 9, -1, -1, -1, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 5, 0, -1, -1, -1, -1, 23, 14, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {29, 18, -1, -1, -1, -1, -1, 9, 18, -1, 16, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {17, -1, -1, 7, -1, -1, -1, -1, -1, 23, -1, 17, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, 17, -1, -1, -1, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 5, -1, -1, -1, 5, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {25, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 17, 6, -1, -1, -1, 28, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, 5, 7, -1, -1, -1, -1, -1, -1, -1, 27, -1, -1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {2, -1, -1, 28, 2, -1, -1, -1, -1, -1, -1, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 28, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, 27, -1, -1, -1, -1, 21, 11, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {13, -1, 11, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1, 22, -1, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {2, -1, -1, -1, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 20, -1, 25, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, 22, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 2, -1, -1, -1, 28, -1, -1, -1, -1, -1, -1, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {20, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1, -1, 26, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, 13, -1, -1, -1, -1, -1, 29, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 25, -1, -1, 18, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 20, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, 19, 12, -1, -1, -1, -1, -1, -1, -1, -1, 22, -1, -1, -1, -1, -1, -1, -1, -1, -1, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {11, -1, -1, -1, -1, -1, -1, 27, -1, -1, -1, -1, -1, -1, -1, 22, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, 21, -1, -1, -1, -1, 24, -1, -1, -1, -1, -1, 25, -1, -1, -1, -1, -1, -1, -1, -1, -1, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 27, 12, -1, -1, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, 29, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 24, -1, -1, -1, -1, -1, -1, -1, -1, -1, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1}, {1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 26, -1, 20, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1}, {-1, 25, -1, 8, -1, -1, -1, 18, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 22, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1}, {4, -1, -1, -1, -1, -1, -1, -1, 13, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1}, {-1, 23, -1, 9, -1, -1, -1, -1, -1, 5, -1, -1, -1, -1, -1, -1, -1, -1, 24, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1}, {12, -1, -1, -1, 20, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1}, {-1, 22, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 7, -1, 19, -1, -1, -1, -1, -1, -1, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1}, {11, -1, -1, -1, -1, -1, -1, 1, -1, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 28, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1}, {-1, 27, -1, -1, -1, -1, 24, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0}};
#pragma endregion
int Zc = 30;

void printArray_int(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
void printArray_db(double a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void shift_arr_int(int row[], int length, int x)
{
    int arr[length];
    int arr_length = length;
    fill_n(arr, arr_length, 0);

    if (x != -1)
    {
        int count = 0;
        for (int i = x; i < arr_length; i++)
        {
            arr[count] = row[i];
            count += 1;
        }
        for (int i = 0; i < x; i++)
        {
            arr[count] = row[i];
            count += 1;
        }
    }
    // printArray_int(arr, length);
    for (int i = 0; i < length; i++)
    {
        row[i] = arr[i];
    }
    // printArray_int(row, length);
}
void shift_arr_db(double row[], int length, int x)
{
    double arr[length];
    int arr_length = length;
    fill_n(arr, arr_length, 0.0);

    if (x != -1)
    {
        int count = 0;
        for (int i = x; i < arr_length; i++)
        {
            arr[count] = row[i];
            count += 1;
        }
        for (int i = 0; i < x; i++)
        {
            arr[count] = row[i];
            count += 1;
        }
    }
    // printArray_int(arr, length);
    for (int i = 0; i < length; i++)
    {
        row[i] = arr[i];
    }
    // printArray_int(row, length);
}

int count_errors(int encoded[], int decoded[], int k)
{
    int error_count = 0;
    for (int i = 0; i < k; i++)
    {
        if (encoded[i] != decoded[i])
        {
            error_count++;
        }
    }
    return error_count;
}

void copy_range_int(int a[], int b[], int index1, int index2)
{
    // a[] = b[index1:index2]
    int arr[index2 - index1];
    int arr_length = index2 - index1;
    fill_n(arr, arr_length, 0);
    int count = 0;
    for (int i = index1; i < index2; i++)
    {
        arr[count] = b[i];
        count++;
    }
    for (int i = 0; i < arr_length; i++)
    {
        a[i] = arr[i];
    }
}
void copy_range_db(double a[], double b[], int index1, int index2)
{
    // a[] = b[index1:index2]
    double arr[index2 - index1];
    int arr_length = index2 - index1;
    fill_n(arr, arr_length, 0.0);
    int count = 0;
    for (int i = index1; i < index2; i++)
    {
        arr[count] = b[i];
        count++;
    }
    for (int i = 0; i < arr_length; i++)
    {
        a[i] = arr[i];
    }
}

int *encode_message(int base_mat[46][68], int Zc, int message[])
{   // only works for NR30 !!!!!!!!!!!!!!!!!!!!!!
    int k = 22*30;              
    static int temp_mat[30*68]; 
    fill_n(temp_mat, 30*68, 0);
    static int codeword[30*68]; 
    fill_n(codeword, 30*68, 0);
    for (int x = 0; x < 22*Zc; x++)
    {
        codeword[x] = message[x];
    }
    
    int parity_mat[30]; // P1 encoding
    fill_n(parity_mat, 30, 0);
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 22; y++)
        {
            int a[30];
            copy_range_int(a, message, y*Zc, (y+1)*Zc);
            shift_arr_int(a, 30, base_mat[x][y]);
            for (int k = 0; k < Zc; k++)
            {
                parity_mat[k] = parity_mat[k] ^ a[k];
            }
        }
    }

    shift_arr_int(parity_mat, Zc, Zc); // encode P1
    int counter = 0;
    for (int x = 22*Zc; x < 23*Zc; x++)
    {
        codeword[x] = parity_mat[counter];
        counter++;
    }

    for (int x = 0; x < 3; x++) // encode P2-4
    {
        fill_n(parity_mat, 30, 0);
        for (int y = 0; y < (23+x); y++)
        {
            int a[30];
            copy_range_int(a, codeword, y*Zc, (y + 1)*Zc);
            shift_arr_int(a, 30, base_mat[x][y]);
            for (int k = 0; k < Zc; k++)
            {
                parity_mat[k] = parity_mat[k] ^ a[k];
            }
        }
        counter = 0;
        for (int p = (23 + x)*Zc; p < (24 + x)*Zc; p++)
        {
            codeword[p] = parity_mat[counter];
            counter++;
        }
    }

    for (int x = 4; x < 46; x++) // encode p5->end
    {
        fill_n(parity_mat, 30, 0);
        for (int y = 0; y < (26); y++)
        {
            int a[30];
            copy_range_int(a, codeword, (y)*Zc, (y + 1)*Zc);
            shift_arr_int(a, 30, base_mat[x][y]);
            for (int k = 0; k < Zc; k++)
            {
                parity_mat[k] = parity_mat[k] ^ a[k];
            }
        }
        counter = 0;
        for (int p = (22 + x)*Zc; p < (23 + x)*Zc; p++)
        {
            codeword[p] = parity_mat[counter];
            counter++;
        }
    }
    return codeword;
}

int check_codeword(int base_mat[46][68], int Zc, int c[])
{
    // c[9] = 0; // break codeword for testing
    int check = 0;
    int num_rows = 46;
    int num_cols = 68;

    int syndrome[30 * 46][1];
    for (int i = 0; i < 30 * 46; i++)
    {
        syndrome[i][0] = 0;
    }

    int trans_val[30][1];
    for (int i = 0; i < 30; i++)
    {
        trans_val[i][0] = 0;
    }

    int count = 0;
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            int a[30];
            copy_range_int(a, c, (j)*Zc, (j + 1) * Zc);
            shift_arr_int(a, 30, base_mat[i][j]);
            for (int k = 0; k < Zc; k++)
            {
                trans_val[k][0] = a[k];
            }
            int count1 = 0;
            for (int k = i * Zc; k < (i + 1) * Zc; k++)
            {
                syndrome[k][0] = syndrome[k][0] ^ trans_val[count1][0];
                count1++;
            }
        }
    }
    int val = 0;
    for (int i = 0; i < num_rows * Zc; i++)
    {
        val = syndrome[i][0];
        if (val != 0)
        {
            cout << "error with codeword at: " + to_string(i) << endl;
            check = 1;
            break;
        }
    }
    return check;
}

bool threshold_test(double array[68*30], double threshold_val, int n){
    bool f_stop_val = true;
    for (int i = 0; i < n; i++){
        double val = abs(array[i]);
        if (val < threshold_val){
            f_stop_val = false;
            break;
        }
    }
    return f_stop_val;
}


#pragma endregion
////////////////////////////////////////////////////////////////////////////
int main()
{
    cout << "" << endl;
    double distance_away = 1.9;
    int num_blocks = 1000;
    //////
    int min_number_of_iters = 6;
    int max_number_of_iters = 50;
    double threshold_value = 5.0;
    //////
    int num_layers = 46;
    double offset = 0.35;
    //////
    double Shannons_limit = -0.53094117634;
    double required_spec = Shannons_limit + distance_away;
    double EbNo_dB = required_spec;
    int num_rows = 46;
    int num_cols = 68;
    int k = (num_cols - num_rows) * Zc;
    int n = num_cols * Zc;
    double code_rate = (double)k / n;
    double EbNo_10 = (double)pow(10, (EbNo_dB / 10));
    double sigma = sqrt(1 / (2 * code_rate * EbNo_10));

    int val;
    int temp_rows_count[num_rows];
    fill_n(temp_rows_count, num_rows, 0);
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            val = base_mat[i][j];
            if (val != -1)
            {
                temp_rows_count[i]++;
            }
        }
    }

    double row_minsum_storage[Zc][19];
    for (int i = 0; i < Zc; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            row_minsum_storage[i][j] = 0.0;
        }
    }

    time_t start_time = time(0);
    int total_num_errors = 0;

    int message[22 * 30];
    int check;
    int symbol[68 * Zc];
    double r[68 * Zc];
    double noise;
    double scaled_noise;
    double Beliefs[68 * Zc];
    double full_minsum_storage[316][Zc];

    double total_num_iters = 0;
    for (int i = 0; i < num_blocks; i++)
    {
        srand(time(NULL));
        for (int i = 0; i < 22 * 30; i++)
        { // random message generation
            int random_int = rand() % 2;
            message[i] = random_int;
        }

        int *codeword = encode_message(base_mat, Zc, message);
        check = check_codeword(base_mat, Zc, codeword);
        // cout << "check: " + to_string(check) << "\n" << endl;

        for (int p = 0; p < 68 * Zc; p++)
        {
            symbol[p] = 1 - 2 * codeword[p];
        }

        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator(seed);
        std::normal_distribution<double> dist(0.0, 1.0);

        for (int p = 0; p < 68 * Zc; p++)
        {
            noise = dist(generator);
            scaled_noise = sigma * noise;
            r[p] = symbol[p] + scaled_noise;
        }

        /////////////////////////////// decoding ///////////////////////////////
        for (int i = 0; i < 68 * Zc; i++)
        {
            Beliefs[i] = r[i];
        }
        for (int i = 0; i < 316; i++)
        {
            for (int j = 0; j < Zc; j++)
            {
                full_minsum_storage[i][j] = 0.0;
            }
        }

        int rows_per_layer = (int)(num_rows) / num_layers;
        //////////////// iterations //////////////////
        int full_minsum_index;
        int row_minsum_index;
        int non_min1s_in_row;

        int iteration_count = 0;
        bool f_stop_val = false;
        bool broke_out = false;
        while (iteration_count < max_number_of_iters){
            if (f_stop_val == true){
                if (iteration_count > min_number_of_iters){
                    total_num_iters = total_num_iters + iteration_count;
                    broke_out = true;
                    break;
                }
            }
            full_minsum_index = 0;
            for (int layer_num = 0; layer_num < num_layers; layer_num++)
            {
                int layer_index1 = layer_num * rows_per_layer;
                int layer_index2 = (layer_index1 + rows_per_layer);

                int non_indexes[layer_index2 - layer_index1]; // solving: for (int _x : non_minus_1s_indexes)
                for (int current_row_num = layer_index1; current_row_num < layer_index2; current_row_num++)
                {
                    row_minsum_index = 0;
                    int num_non_minus_1s_indexes = 0;
                    int val1 = 0;
                    for (int p = 0; p < 68; p++)
                    {
                        val1 = base_mat[current_row_num][p];
                        if (val1 != -1)
                        {
                            num_non_minus_1s_indexes++;
                        }
                    }
                    non_indexes[current_row_num] = num_non_minus_1s_indexes;

                    int non_minus_1s_indexes[num_non_minus_1s_indexes];
                    int counter3 = 0;
                    for (int p = 0; p < 68; p++)
                    {
                        val1 = base_mat[current_row_num][p];
                        if (val1 != -1)
                        {
                            non_minus_1s_indexes[counter3] = p;
                            counter3++;
                        }
                    }
                    ////////////////////////// loop 1/3 //////////////////////////
                    for (int q = 0; q < non_indexes[current_row_num]; q++) // loop 1/3
                    {
                        int x = non_minus_1s_indexes[q];
                        int count4 = 0;
                        for (int p = (x)*Zc; p < (x + 1) * Zc; p++)
                        {
                            Beliefs[p] = Beliefs[p] - full_minsum_storage[full_minsum_index][count4];
                            count4++;
                        }
                        double a[Zc];
                        copy_range_db(a, Beliefs, (x)*Zc, (x + 1) * Zc);
                        shift_arr_db(a, 30, base_mat[current_row_num][x]);
                        for (int p = 0; p < Zc; p++)
                        {
                            row_minsum_storage[p][row_minsum_index] = a[p];
                        }
                        row_minsum_index++;
                        full_minsum_index++;
                    } // end for loop 1/3
                    ////////////////////////// end loop 1/3 //////////////////////////

                    non_min1s_in_row = row_minsum_index; // current value is the number of non -1s in the current row in the layer.
                    full_minsum_index = full_minsum_index - row_minsum_index;
                    row_minsum_index = 0;
                    ////////////////////////// loop 2/3 //////////////////////////
                    for (int i1 = 0; i1 < Zc; i1++) // loop 2/3
                    {
                        double temp_arr[non_min1s_in_row];
                        copy_range_db(temp_arr, row_minsum_storage[i1], 0, non_min1s_in_row);

                        double min_val_1 = 100000.0;
                        double min_val_2 = 100001.0;
                        double val2 = 0;
                        double val3 = 0;
                        int pos1 = 10000000;
                        int sign[non_min1s_in_row];
                        int overall_parity = 1;
                        for (int p = 0; p < non_min1s_in_row; p++)
                        {
                            val2 = abs(temp_arr[p]);
                            if (val2 <= min_val_1)
                            { // val2 <= min_val_1
                                min_val_2 = min_val_1;
                                min_val_1 = val2;
                                pos1 = p;
                            }
                            else if (val2 > min_val_1 && val2 <= min_val_2)
                            { // min_val_1 < val2 <= min_val_2
                                min_val_2 = val2;
                            }
                            else if (val2 > min_val_2)
                            {
                                ;
                            }
                            val3 = temp_arr[p];
                            if (val3 < 0)
                            {
                                overall_parity = overall_parity * (-1);
                                sign[p] = -1;
                            }
                            else
                            {
                                sign[p] = 1;
                            }
                        } // end p < non_min1s_in_row loop
                        // double offset = 0.35;
                        min_val_1 = min_val_1 - offset;
                        if (min_val_1 < 0)
                        {
                            min_val_1 = 0;
                        }
                        min_val_2 = min_val_2 - offset;
                        if (min_val_2 < 0)
                        {
                            min_val_2 = 0;
                        }
                        ////////////////////
                        double new_temp_reg[non_min1s_in_row];
                        for (int p = 0; p < non_min1s_in_row; p++)
                        {
                            new_temp_reg[p] = min_val_1;
                        }
                        new_temp_reg[pos1] = min_val_2;
                        for (int p = 0; p < non_min1s_in_row; p++)
                        {
                            new_temp_reg[p] = new_temp_reg[p] * sign[p] * overall_parity;
                        }

                        for (int p = 0; p < non_min1s_in_row; p++)
                        {
                            row_minsum_storage[i1][p] = new_temp_reg[p];
                        }
                    } //  end for loop 2/3
                    ////////////////////////// end loop 2/3 //////////////////////////
                    

                    ////////////////////////// loop 3/3 //////////////////////////
                    for (int q = 0; q < non_indexes[current_row_num]; q++) // loop 3/3
                    {
                        int x = non_minus_1s_indexes[q];
                        double a[Zc];
                        for (int p = 0; p < Zc; p++)
                        {
                            a[p] = row_minsum_storage[p][row_minsum_index];
                        }
                        shift_arr_db(a, 30, Zc - base_mat[current_row_num][x]);
                        copy_range_db(full_minsum_storage[full_minsum_index], a, 0, Zc);
                        int count4 = 0;
                        for (int p = (x)*Zc; p < (x + 1) * Zc; p++)
                        {
                            Beliefs[p] = Beliefs[p] + full_minsum_storage[full_minsum_index][count4];
                            count4++;
                        }
                        row_minsum_index++;
                        full_minsum_index++;
                    } // end of for loop 3/3
                    ////////////////////////// end loop 3/3 //////////////////////////
                }     // end of current_row_num loop
            }         // end of layers
            f_stop_val = threshold_test(Beliefs, threshold_value, n);
            iteration_count++; // increment while loop
        }             // end of iterations
        if (broke_out == false){
            total_num_iters = total_num_iters + iteration_count;
        }

        double final_beliefs[68 * Zc];
        for (int q3 = 0; q3 < 68 * Zc; q3++)
        {
            final_beliefs[q3] = Beliefs[q3];
        }

        int decoded_message[22 * 30];
        fill_n(decoded_message, k, 0);
        for (int i = 0; i < k; i++)
        {
            if (final_beliefs[i] < 0)
            {
                decoded_message[i] = 1;
            }
            else
            {
                decoded_message[i] = 0;
            }
        }

        int errors_in_block = count_errors(message, decoded_message, k);
        // cout << "errors_in_block: " << errors_in_block << endl;
        total_num_errors = total_num_errors + errors_in_block;
    } // end blocks

    int total_num_message_bits = num_blocks * k;
    double avg_num_iters = total_num_iters/num_blocks;
    double BER = (double)total_num_errors / total_num_message_bits;

    cout << "####################################" << endl;
    // cout << "num_blocks =\t" << to_string(num_blocks) << endl;
    // cout << "num_layers =\t" << to_string(num_layers) << endl;
    // cout << "num_iters =\t\t" << to_string(num_iterations) << endl;
    // cout << "offset =\t\t" << to_string(offset) << endl;
    // cout << "total_num_errors =\t\t" << to_string(total_num_errors) << endl;
    // cout << "total_message_bits =\t" << to_string(total_num_message_bits) << endl;
    // cout << "distance_away =\t\t" << to_string(distance_away) << endl;
    // cout << "BER =\t\t\t\t" << to_string(BER) << endl;
    cout << "num_blocks =\t\t\t" << to_string(num_blocks) << endl;
    cout << "distance_away =\t\t\t" << to_string(distance_away) << endl;
    cout << "total_num_errors =\t\t" << to_string(total_num_errors) << endl;
    cout << "total_message_bits =\t" << to_string(total_num_message_bits) << endl;
    cout << "BER =\t\t\t\t\t" << to_string(BER) << endl;
    cout << "" << endl;
    cout << "threshold_value =\t" + to_string(threshold_value) << endl;
    cout << "iterations range =\t(" + to_string(min_number_of_iters)+";"+ to_string(max_number_of_iters)+")"  << endl;
    cout << "avg_num_iters =\t\t" + to_string(avg_num_iters) << endl;

    time_t end_time = time(0);
    int run_time = end_time - start_time;
    cout << "\navg_run_time =\t" + to_string((run_time*1000)/num_blocks)+ " millisec";
    cout << "\nrun_time (s) =\t" << to_string(run_time) << " sec" << endl;
    cout << "####################################\n" << endl;
    return 0;
}