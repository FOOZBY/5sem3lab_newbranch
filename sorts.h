#include <iostream>
#include <chrono>
#include <algorithm> //sort

using namespace std;

void copy_arr(int* arr, int* temp_arr,int length)
{
	for (int i = 0; i < length; i++)
	{
		temp_arr[i] = arr[i];
	}
}

void show_arr(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void InsertionSort(int* arr, int length)
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
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void SelectionSort(int* arr, int length)
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
void BubbleSort(int* arr,int length)
{
	int temp;
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
void merge(int* arr, int l, int m, int r)//O(n)
{
	int i = 0, j = 0, k = l;
	int n1 = m - l + 1;
	int n2 = r - m;
	int* L = new int[n1]();
	int* R = new int[n2]();

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

void mergeSort(int* arr, int l, int r)
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
void ShellSort(int* arr, int length)
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
			int temp = arr[i];

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

int partition(int* arr, int low, int high)
{
	// Выбираем крайний правый элемент в качестве опорного элемента массива
	int pivot = arr[high];

	// элементы, меньшие точки поворота, будут перемещены влево от `pIndex`
	// элементы больше, чем точка поворота, будут сдвинуты вправо от `pIndex`
	// равные элементы могут идти в любом направлении
	int pIndex = low;

	// каждый раз, когда мы находим элемент, меньший или равный опорному, `pIndex`
	// увеличивается, и этот элемент будет помещен перед опорной точкой.
	for (int i = low; i < high; i++)
	{
		if (arr[i] <= pivot)
		{
			swap(arr[i], arr[pIndex]);
			pIndex++;

		}
	}

	// поменять местами `pIndex` с пивотом
	swap(arr[pIndex], arr[high]);

	// вернуть `pIndex` (индекс опорного элемента)
	return pIndex;
}

void QuickSort(int* arr, int low, int high)
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