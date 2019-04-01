
#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

unsigned long inicio, fin, t;

template<class T>
bool mayor(T a, T b) { return a > b; }

template<class T>
bool menor(T a, T b) { return a < b; }

template<class T>
void swap_cuock(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}
template<class T>
void burbuja(T *arr, int n, bool(*p)(T,T))
{
	for (unsigned int i = 0; i < n - 1; i++)
		for (unsigned int j = 0; j < n - i - 1; j++)
			//if (compara(arr[j], arr[j + 1]))
			//if (*(arr+j) > *(arr+j+1))
			//if (o.funct(*(arr+j), *(arr+j+1)))
			if (p(*(arr + j), *(arr + j + 1)))
				swap_cuock(*(arr + j), *(arr + j + 1));
}
template<class T>
int partition(T arr[], int low, int high, bool(*o)(T, T))
{
	T pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		//if (arr[j] < pivot)
		//if ((p.*o)(arr[j], pivot))
		if (o(arr[j], pivot))
		{
			i++;
			swap_cuock(arr[i], arr[j]);
		}
	}
	swap_cuock(arr[i + 1], arr[high]);
	return (i + 1);
}

template<class T>
void quickSort(T arr[], int low, int high, bool(*o)(T, T))
{
	if (low < high)
	{
		int pi = partition<T>(arr, low, high, o);
		quickSort<T>(arr, low, pi - 1, o);
		quickSort<T>(arr, pi + 1, high, o);
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
	const int cuack = 5000000;
	int *arr = NULL;
	arr = new int[cuack];
	crear_aroi<int>(arr, cuack);
	//printArray<int>(arr, cuack);

	bool (*p)(int, int);
	p = menor;

	inicio = clock();

	//burbuja<int>(arr, cuack, p);
	quickSort<int>(arr, 0, cuack-1, p);

	fin = clock();
	//printArray<int>(arr, cuack);
	double t = (double(fin - inicio) / CLOCKS_PER_SEC);
	cout << "Tiempo: " << t << " seg" << endl;

	delete[] arr;
	arr = 0;	
}


		