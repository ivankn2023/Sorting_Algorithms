// algorithms.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
void quicksort(int* m, int start, int end);
int transport(int* m, int start, int end);


int main()
{
	int n = 10;


	std::cout << "BUBBLE" << std::endl; //   O(n)^2
	//bubble sort
	int* m = new int[n] {-3, 5, 0, 4, 9, 8, 3, -1, 4, 2};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (m[j] > m[j + 1]) std::swap(m[j + 1], m[j]);

		}
	}
	for (int i = 0; i < n; i++) {
		std::cout << m[i] << " ";
	}




	std::cout << std::endl << "INSERTION" << std::endl; //   O(n)^2
	/////insertion
	int* k = new int[n] {-3, 5, 0, 4, 9, 8, 3, -1, 4, 2};
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
	for (int i = 0; i < n; i++) {
		std::cout << k[i] << " ";
	}



	std::cout << std::endl << "CHOICE" << std::endl; //   O(n)^2
	/////choice
	int c = 0;
	int* mas = new int[n] {-3, 5, 0, 4, 9, 8, 3, -1, 4, 2};
	for (int j = 0; j < n - 1; j++) {

		int min = mas[j];
		for (int k = j+1; k < n; k++) {
			if (mas[k] < min) min = k;
		}
		if (min != j) {
			c = mas[j];
			mas[j] = mas[min];
		}
	}
	for (int i = 0; i < n; i++) {
		std::cout << k[i] << " ";
	}


	std::cout << std::endl << "QUICK" << std::endl; //   O(n*log n)
	/////quick
	int* mass = new int[n] {-3, 5, 0, 4, 9, 8, 3, -1, 4, 2};

	quicksort(mass, 0, n-1);

	for (int i = 0; i < n; i++) {
		std::cout << k[i] << " ";
	}
}

void quicksort(int* m, int start, int end) {

	if (start >= end) return;

	int sup = transport(m, start, end);

	quicksort(m, start, sup - 1);
	quicksort(m, sup + 1, end);
}
int transport(int* m, int start, int end) {

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