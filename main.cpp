#include <iostream>
#include <chrono>
#include <algorithm>
#include <random>
#include "algorithm_S.h"


void printVector(std::vector<long> & vec)
{
	for (long i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << ' ';
	}
	std::cout << std::endl;
}
void printVector(std::vector<double> & vec)
{
	for (long i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << ' ';
	}
	std::cout << std::endl;
}

int main(void)
{
    long n0 = 10e3; //10e3
    long nMax = 10e6; //10e6
    int nTest = 7;

	for (long sizeVec = n0; sizeVec < nMax; sizeVec *= 2) {
		std::vector<long> vec(sizeVec, 0); // long
		std::random_device rd;
		std::mt19937 gen(rd());

		for (long i = 0; i < sizeVec; i++) {
			vec[i] = i;
		}
		
		auto start = std::chrono::high_resolution_clock::now();
		
		for (int iTest = 0; iTest < nTest; iTest++) {
			std::shuffle(vec.begin(), vec.end(), gen);
			//printVector(vec);
			insertionSort(vec);
			//printVector(vec);
		}

		auto end = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		std::cout << dur.count() / nTest << std::endl;
		vec.clear();
	}

    return 0;
}