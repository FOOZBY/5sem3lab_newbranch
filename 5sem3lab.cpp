#include "sorts.h"

int main()
{
    setlocale(0, "");
	
	int length;
	cout << "введите кол-во элементов сортируемого массива: ";
	cin >> length;
	int* arr = new int[length];
	int* temp_arr = new int[length];
	srand(std::time(nullptr));
	cout << "Выберите случай:\n";
	cout << "Лучший:1\n";
	cout << "Средний:2\n";
	cout << "Худший:3\n";
	int choose;
	bool ok = true;
	while (ok)
	{
		cin >> choose;
		switch (choose)
		{
		case 1:
			for (int i = 0; i < length; i++)
			{
				arr[i] = i;
				cout << arr[i] << endl;
			}
			ok = false;
			break;
		case 2:
			for (int i = 0; i < length; i++)
			{
				arr[i] = rand() % 10000;
				cout << arr[i] << endl;
			}
			ok = false;
			break;
		case 3:
			for (int i = 0; i < length; i++)
			{
				arr[i] = length-i;
				cout << arr[i] << endl;
			}
			ok = false;
			break;
		default:
			cout << "Неверно выбран номер\n";
			break;
		}
	}
	
	int count = 0;
	double inssrt_time = 0, selsrt_time = 0, bubsrt_time = 0, mersrt_time = 0, shesrt_time = 0, quisrt_time = 0, stdsrt_time = 0;
	while (count < 50)
	{
		count++;

		copy_arr(arr, temp_arr, length);
		auto start = chrono::high_resolution_clock::now();
		InsertionSort(temp_arr, length);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> duration = end - start;
		//cout << "Время InsertionSort: " << duration.count() << " ms\n";
		inssrt_time += duration.count();

		copy_arr(arr, temp_arr, length);
		start = chrono::high_resolution_clock::now();
		SelectionSort(temp_arr, length);
		end = chrono::high_resolution_clock::now();
		duration = end - start;
		selsrt_time += duration.count();
		//cout << "Время SelectionSort: " << duration.count() << " ms\n";

		copy_arr(arr, temp_arr, length);
		start = chrono::high_resolution_clock::now();
		BubbleSort(temp_arr, length);
		end = chrono::high_resolution_clock::now();
		duration = end - start;
		bubsrt_time += duration.count();
		//cout << "Время BubbleSort: " << duration.count() << " ms\n";
		
		copy_arr(arr, temp_arr, length);
		start = chrono::high_resolution_clock::now();
		mergeSort(temp_arr, 0, length - 1);
		end = chrono::high_resolution_clock::now();
		duration = end - start;
		mersrt_time += duration.count();
		//cout << "Время MergeSort: " << duration.count() << " ms\n";
		
		copy_arr(arr, temp_arr, length);
		start = chrono::high_resolution_clock::now();
		ShellSort(temp_arr, length);
		end = chrono::high_resolution_clock::now();
		duration = end - start;
		shesrt_time += duration.count();
		//cout << "Время ShellSort: " << duration.count() << " ms\n";
		
		copy_arr(arr, temp_arr, length);
		start = chrono::high_resolution_clock::now();
		QuickSort(temp_arr, 0, length - 1);
		end = chrono::high_resolution_clock::now();
		duration = end - start;
		quisrt_time += duration.count();
		//cout << "Время QuickSort: " << duration.count() << " ms\n";
	
		copy_arr(arr, temp_arr, length);
		start = chrono::high_resolution_clock::now();
		sort(temp_arr, temp_arr + length);
		end = chrono::high_resolution_clock::now();
		duration = end - start;
		stdsrt_time += duration.count();
		//cout << "Время std::sort: " << duration.count() << " ms\n";
		//show_arr(temp_arr, length);
	}
	cout << inssrt_time / count << endl;
	cout << selsrt_time / count << endl;
	cout << bubsrt_time / count << endl;
	cout << mersrt_time / count << endl;
	cout << shesrt_time / count << endl;
	cout << quisrt_time / count << endl;
	cout << stdsrt_time / count << endl;
	show_arr(temp_arr, length);

	system("pause");
}