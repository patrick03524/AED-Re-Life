
#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

unsigned long inicio, fin, t;

template<class T>
void swap_cuock(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
int partition(T arr[], int low, int high)
{
	T pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap_cuock(arr[i], arr[j]);
		}
	}
	swap_cuock(arr[i + 1], arr[high]);
	return (i + 1);
}

template<class T>
void quickSort(T arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition<T>(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

template <class T>
void crear_aroi(T *aroi, int num_elem) { ///solo int's
	srand(time(NULL));
	int numero_aleatorio;
	for (int i = 0; i < num_elem; i++) {
		numero_aleatorio = 1 + rand() % (101 - 1);  ///numeros entre 1-100
		*aroi = numero_aleatorio;
		aroi++;
	}
}
template <class T>
void printArray(T *a, int n)
{
	cout << "{ ";
	for (int i = 0; i < n; i++) {
		cout << *(a + i) << " ";
	}
	cout << "}" << endl;
}
int main()
{
	const int cuack = 100;
	int *arr = NULL;
	arr = new int[cuack];
	crear_aroi<int>(arr, cuack);
	printArray<int>(arr, cuack);

	inicio = clock();

	quickSort<int>(arr, 0, cuack - 1);

	fin = clock();
	printArray<int>(arr, cuack);
	double t = (double(fin - inicio) / CLOCKS_PER_SEC);
	cout << "Tiempo: " << t << " seg" << endl;

	delete[] arr;
	arr = 0;
}
