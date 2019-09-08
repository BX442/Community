#include "pch.h"
#include "a_random.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

int A_rand(int min, int max)
{
	//srand(static_cast<unsigned int>(time(0)));
	double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// равномерно распределяем рандомное число в нашем диапазоне
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}