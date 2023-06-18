// algorithms.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void quicksort(int* m, int start, int end);
int transport_for_quicksort(int* m, int start, int end);
void merge(int arr[], int left, int middle, int right);




void bubblesort(int* m, int n) { 	//bubble sort
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (m[j] > m[j + 1]) std::swap(m[j + 1], m[j]);

		}
	}
}


void insertion_sort(int *k , int n) { 	/////insertion
	int j = 0, x = 0;
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		while (j >= 0 && k[j] > k[j + 1])
		{
			std::swap(k[j], k[j + 1]);
			j--;
		}
	}
}


void choice_sort(int* arr, int n) {
	{
		int i, j, minIndex, temp;
		for (i = 0; i < n - 1; i++) {
			minIndex = i;
			for (j = i + 1; j < n; j++) {
				if (arr[j] < arr[minIndex]) {
					minIndex = j;
				}
			}
			temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}
}


void quicksort(int* m, int start, int end) {

	if (start >= end) return;

	int sup = transport_for_quicksort(m, start, end);

	quicksort(m, start, sup - 1);
	quicksort(m, sup + 1, end);
}
int transport_for_quicksort(int* m, int start, int end) {

	int sup = m[end];
	int index = start;
	for (int i = start; i < end; i++) {
		if (m[i] <= sup) {
			std::swap(m[i], m[index]);
			index++;
		}
	}
	std::swap(m[end], m[index]);
	return index;
}


void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		// вычисляем середину массива
		int middle = left + (right - left) / 2;
		// рекурсивно вызываем функцию сортировки для левой и правой половин
		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);
		// объединяем отсортированные половины в исходный массив
		merge(arr, left, middle, right);
	}
}
void merge(int arr[], int left, int middle, int right) {
	// вычисляем размеры временных массивов
	int n1 = middle - left + 1;
	int n2 = right - middle;
	// создаем временные массивы L и R
	int* L = new int[n1];
	int* R = new int[n2];
	// копируем данные во временные массивы
	for (int i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = arr[middle + 1 + j];
	}
	// объединяем временные массивы в исходный массив
	int i = 0;
	int j = 0;
	int k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	// копируем оставшиеся элементы из временных массивов
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

int main()
{
	int n = 10;

	std::cout << "BUBBLE" << std::endl; //   O(n)^2
	//bubble sort
	int* m = new int[n] {-3, 5, 0, 4, 9, 8, 3, -1, 4, 2};
	bubblesort(m, n);

	for (int i = 0; i < n; i++) {
		std::cout << m[i] << " ";
	}


	std::cout << std::endl << "INSERTION" << std::endl; //   O(n)^2
	/////insertion
	int* k = new int[n] {-3, 5, 0, 4, 9, 8, 3, -1, 4, 2};

	insertion_sort(k, n);

	for (int i = 0; i < n; i++) {
		std::cout << k[i] << " ";
	}



	std::cout << std::endl << "CHOICE" << std::endl; //   O(n)^2
	/////choice
	int* mas = new int[n] {-3, 5, 0, 4, 9, 8, 3, -1, 4, 2};
		
	choice_sort(mas, n);

	for (int i = 0; i < n; i++) {
		std::cout << mas[i] << " ";
	}


	std::cout << std::endl << "QUICK" << std::endl; //   O(n*log n)
	/////quick
	int* mass = new int[n] {-3, 5, 0, 4, 9, 8, 3, -1, 4, 2};

	quicksort(mass, 0, n-1);

	for (int i = 0; i < n; i++) {
		std::cout << mass[i] << " ";
	}


	std::cout << std::endl << "MERGE" << std::endl; //   O(n*log n)
	/////merge
	int* massive = new int[n] {-3, 5, 0, 4, 9, 8, 3, -1, 4, 2};
	mergeSort(massive, 0, n - 1);

	for (int i = 0; i < n; i++) {
		std::cout << massive[i] << " ";
	}
}