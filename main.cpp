#include <iostream>
#include <chrono>
#include <algorithm>
#include "algorithm_S.h"


void printVector(std::vector<long> & vec)
{
	for (long i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << ' ';
	}
	std::cout << std::endl;
}

int main(void)
{
    long n0 = 10;
    long nMax = 30;
    int nTest = 1;

	for (long sizeVec = n0; sizeVec < nMax; sizeVec *= 2) {
		std::vector<long> vec(sizeVec, 0);
		for (long i = 0; i < sizeVec; i++) {
			vec[i] = i;
		}
		
		auto start = std::chrono::high_resolution_clock::now();
		for (int iTest = 0; iTest < nTest; iTest++) {

			std::random_shuffle(vec.begin(), vec.end());
			printVector(vec);
			quickSort(vec, 0, vec.size() - 1);
			printVector(vec);
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		//std::cout << dur.count() / nTest << std::endl;
		vec.clear();
	}

    return 0;
}