#include <iostream>
#include <chrono>
#include <algorithm> //sort

using namespace std;

void copy_arr(float* arr, float* temp_arr,int length)
{
	for (int i = 0; i < length; i++)
	{
		temp_arr[i] = arr[i];
	}
}

void show_arr(float* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void InsertionSort(float* arr, int length)
{
	int i, key, j;
	for (i = 1; i < length; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
};
//////////////////////////////////////////////////////////////////
void swap(float* xp, float* yp)
{
	float temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void SelectionSort(float* arr, int length)
{
	int min_idx;

	// One by one move boundary of
	// unsorted subarray
	for (int i = 0; i < length - 1; i++)
	{

		// Find the minimum element in
		// unsorted array
		min_idx = i;
		for (int j = i + 1; j < length; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element
		// with the first element
		if (min_idx != i)
			swap(arr[min_idx], arr[i]);
	}
}
//////////////////////////////////////////////////////////////////
void BubbleSort(float* arr,int length)
{
	float temp;
	for (int i = 0; i < (length - 1); i++)
	{
		for (int j = 0; j < (length - i - 1); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
//////////////////////////////////////////////////////////////////
void merge(float* arr, int l, int m, int r)//O(n)
{
	int i = 0, j = 0, k = l;
	int n1 = m - l + 1;
	int n2 = r - m;
	float* L = new float[n1]();
	float* R = new float[n2]();

	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;
}

void mergeSort(float* arr, int l, int r)
{
	int m = l + (r - l) / 2;
	if (l < r)
	{
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
//////////////////////////////////////////////////////////////////
void ShellSort(float* arr, int length)
{
	for (int gap = length / 2; gap > 0; gap /= 2)
	{
		// Do a gapped insertion sort for this gap size.
		// The first gap elements a[0..gap-1] are already in gapped order
		// keep adding one more element until the entire array is
		// gap sorted
		for (int i = gap; i < length; i += 1)
		{
			// add a[i] to the elements that have been gap sorted
			// save a[i] in temp and make a hole at position i
			float temp = arr[i];

			// shift earlier gap-sorted elements up until the correct
			// location for a[i] is found
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			//  put temp (the original a[i]) in its correct location
			arr[j] = temp;
		}
	}
}
//////////////////////////////////////////////////////////////////

int partition(float* arr, int low, int high)
{
	float pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element and indicates
	// the right position of pivot found so far

	for (int j = low; j <= high - 1; j++) 
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot) 
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void QuickSort(float* arr, int low, int high)
{
	if (low < high) 
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		QuickSort(arr, low, pi - 1);
		QuickSort(arr, pi + 1, high);
	}
}