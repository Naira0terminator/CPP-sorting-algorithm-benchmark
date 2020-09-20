#include "sorting functions.h"
#include <algorithm>

void selection(std::vector<int>& array)
{
	for (int start{ 0 }; start < array.size(); start++)
	{
		int smallest{ start };

		for (int current{ start + 1 }; current < array.size(); current++)
		{
			if (array[current] < array[smallest])
				smallest = current;
		}

		std::swap(array[start], array[smallest]);
	}
}

// ============== SELCTION SORT ==================
void counting(std::vector<int>& array, int exp)
{
	std::vector<int> output;
	std::vector<int> count;
	int i;

	count.resize(10);
	output.reserve(array.size());

	for (i = 0; i < array.size(); i++)
		count[ (array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = array.size() - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < array.size(); i++)
		array[i] = output[i];
}

void radix(std::vector<int>& array)
{
	int max_element = *std::max_element(array.begin(), array.end());

	for (int exp = 1; max_element / exp > 0; exp *= 10)
		counting(array, exp);
}

// ============================================


// ============== QUICK SORT ==================
int partition(std::vector<int> &array, int low, int high)
{
	int pivot = array[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			std::swap(array[i], array[j]);
		}
	}

	std::swap(array[i + 1], array[high]);
	return (i + 1);
}

void quick(std::vector<int>& array, int low, int high)
{
	if (low < high)
	{
		int pi = partition(array, low, high);

		quick(array, low, pi - 1);
		quick(array, pi + 1, high);
	}
}

// ============================================

// ============== HEAP ==================
void heapify(std::vector<int>& array, int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;

	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		std::swap(array[i], array[largest]);
		heapify(array, n, largest);
	}
}

void heapSort(std::vector<int>& array)
{
	for (int i = array.size() / 2 - 1; i >= 0; i--)
		heapify(array, array.size(), i);

	for (int i = array.size() - 1; i >= 0; i--)
	{
		std::swap(array[0], array[i]);
		heapify(array, i, 0);
	}
}
// ======================================
