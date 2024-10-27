#include <vector>

void count_sort(std::vector<long> &vec, long min_v, long max_v)
{
	std::vector<long> count(max_v - min_v + 1, 0);
	for (long val : vec) count[val - min_v]++;

	vec.clear();
	for (long i = 0; i < count.size(); i++) for (long j = 0; j < count[i]; j++) vec.push_back(i + min_v);
}

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
