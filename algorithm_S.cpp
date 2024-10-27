#include <vector>

void bubbleSort(std::vector<long> & vec)
{
	long numberPairs = vec.size();
	bool isSwapped = true;
	while (isSwapped) {
		numberPairs--;
		isSwapped = false;
		for (long i = 0; i < numberPairs; i++) {
			if (vec[i] > vec[i + 1]) {
				std::swap(vec[i], vec[i + 1]);
				isSwapped = true;
			}
		}
	}
}

int partititon(std::vector<long>& vec, long left, long right)
{
	long p_Value = vec[right];
    long p_Point = left - 1;

    for (long i = left; i < right; i++) {
        if (vec[i] <= p_Value) {
			p_Point++;
            std::swap(vec[p_Point], vec[i]);
        }
    }

	std::swap(vec[right], vec[p_Point + 1]);
	return p_Point + 1;

}

void quickSort(std::vector<long>& vec, long left, long right)
{
	if (left < right) {
		long pivot = partititon(vec, left, right);
		quickSort(vec, left, pivot - 1);
		quickSort(vec, pivot + 1, right);

	}
}
