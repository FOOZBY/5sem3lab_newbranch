#include "sorts.h"

int main()
{
    setlocale(0, "");
    
	int length;
	cout << "введите кол-во элементов сортируемого массива: ";
	cin >> length;
	float* arr = new float[length];
	float* temp_arr = new float[length];
	cout << "введите элементы массива: ";
	for (int i = 0; i < length; i++)
	{
		cin >> arr[i];
	}
	copy_arr(arr, temp_arr, length);


	auto start = chrono::high_resolution_clock::now();
	InsertionSort(temp_arr, length);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	cout << "Время InsertionSort: " << duration.count() << " ms\n";
	copy_arr(arr, temp_arr, length);

	start = chrono::high_resolution_clock::now();
	SelectionSort(temp_arr, length);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Время SelectionSort: " << duration.count() << " ms\n";
	copy_arr(arr, temp_arr, length);

	start = chrono::high_resolution_clock::now();
	BubbleSort(temp_arr, length);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Время BubbleSort: " << duration.count() << " ms\n";
	copy_arr(arr, temp_arr, length);

	start = chrono::high_resolution_clock::now();
	mergeSort(temp_arr, 0, length-1);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Время MergeSort: " << duration.count() << " ms\n";
	copy_arr(arr, temp_arr, length);

	start = chrono::high_resolution_clock::now();
	ShellSort(temp_arr, length);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Время ShellSort: " << duration.count() << " ms\n";
	copy_arr(arr, temp_arr, length);

	start = chrono::high_resolution_clock::now();
	QuickSort(temp_arr, 0, length - 1);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Время QuickSort: " << duration.count() << " ms\n";
	copy_arr(arr, temp_arr, length);

	start = chrono::high_resolution_clock::now();
	sort(temp_arr, temp_arr+length);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Время std::sort: " << duration.count() << " ms\n";
	show_arr(temp_arr, length);

    system("pause");
}