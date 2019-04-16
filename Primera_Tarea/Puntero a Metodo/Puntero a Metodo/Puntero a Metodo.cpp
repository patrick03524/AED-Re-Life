
#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

unsigned long inicio, fin, t;

template<class T>
class Father {
public:
	bool cmp_mayor(T a, T b) { return a < b; }
	bool cmp_menor (T a, T b) { return a > b; }
};

template<class T>
void swap_cuock(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
int partition(T arr[], int low, int high, bool (Father<T>:: *o) (T,T), Father<T> p)
{
	T pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		//if (arr[j] < pivot)
		if ((p.*o)(arr[j], pivot))
		{
			i++;
			swap_cuock(arr[i], arr[j]);
		}
	}
	swap_cuock(arr[i + 1], arr[high]);
	return (i + 1);
}

template<class T>
void quickSort(T arr[], int low, int high, bool (Father<int>:: *o) (int, int), Father<int> p)
{
	if (low < high)
	{
		int pi = partition<T>(arr, low, high, o, p);
		quickSort(arr, low, pi - 1, o, p);
		quickSort(arr, pi + 1, high, o, p);
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

	Father<int> marriage;
	bool (Father<int>:: *ptr) (int,int);
	ptr = &Father<int> :: cmp_mayor;

	/*if ((marriage.*ptr) (4, 3))
	{
		cout << "cuack" << endl;
	}
	*/
	inicio = clock();

	//quickSort<int, bool(Father<int>::*)(int, int)>(arr, 0, cuack - 1, ptr);
	quickSort<int>(arr, 0, cuack - 1, ptr, marriage);

	fin = clock();
	//printArray<int>(arr, cuack);
	double t = (double(fin - inicio) / CLOCKS_PER_SEC);
	cout << "Tiempo: " << t << " seg" << endl;

	delete[] arr;
	arr = 0;
}


