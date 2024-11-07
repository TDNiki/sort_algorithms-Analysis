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

void merge(std::vector<long> &vec, long left, long mid, long right)
{
	long left_len = mid - left + 1;
	long right_len = right - mid;

	std::vector<long> Lvec(left_len), Rvec(right_len);

	for (long i = 0; i < left_len; i++)
        Lvec[i] = vec[left + i];
    for (long j = 0; j < right_len; j++)
        Rvec[j] = vec[mid + 1 + j];
	
	long i = 0, j = 0;
    long k = left;

    while (i < left_len && j < right_len) {
        if (Lvec[i] <= Rvec[j]) {
            vec[k] = Lvec[i];
            i++;
        }
        else {
            vec[k] = Rvec[j];
            j++;
        }
        k++;
    }

    while (i < left_len) {
        vec[k] = Lvec[i];
        i++;
        k++;
    }

    while (j < right_len) {
        vec[k] = Rvec[j];
        j++;
        k++;
    }
}

void merge_sort(std::vector<long> &vec, long left, long right)
{
	if (left < right) {
		int mid = left + (right - left) / 2;
    	merge_sort(vec, left, mid);
    	merge_sort(vec, mid + 1, right);
    	merge(vec, left, mid, right);
	}
}

void insertionSort(std::vector<double> &vec)
{
	for (long i = 1; i < vec.size(); i++) {
        double key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

void insertionSort(std::vector<long> &vec)
{
	for (long i = 1; i < vec.size(); i++) {
        long key = vec[i];
        long j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

void bucket_sort(std::vector<double> &vec)
{
	size_t n = vec.size();
	std::vector<std::vector<double>> dtemp(n);

	for (double val : vec) dtemp[n * val].push_back(val);
	for (std::vector i : dtemp) insertionSort(i);
	long index = 0;
	for (long i = 0; i < n; i++) for (long j = 0; j < dtemp[i].size(); j++) vec[index++] = dtemp[i][j];
}