
#include "pch.h"
#include <iostream>
using namespace std;

template<class T>
class Mayor {
public:
	inline bool operator() (T a, T b) { return a > b; }
};

template<class T>
class Menor {
public:
	inline bool operator() (T a, T b) { return a < b; }
};


template<class T>
void swap_cuock(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T, class Op>
int partition(T arr[], int low, int high)
{
	Op o;
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

template<class T, class Op>
void quickSort(T arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition<T, Op>(arr, low, high);
		quickSort<T, Op>(arr, low, pi - 1);
		quickSort<T, Op>(arr, pi + 1, high);
	}
}

template<class T>
class CNode {
public:
	T C_Data;
	CNode<T> *C_Next;
	CNode(T x) {
		C_Data = x;
		C_Next = 0;
	}
};

template<class T, class Op>
class CList {
public:
	CNode<T>* C_Head;
	Op o;
	CList() { C_Head = 0; }
	~CList()
	{
		cout << "Y LAS ESTRELLAS TOCAR DIGIMOOOOOOOOOOOOOOON" << endl;
	}

	bool find(T x, CNode<T> *&p);
	bool insert(T x);
	bool remove(T x);
	void print();
};

template<class T, class Op>
bool CList<T, Op>::find(T x, CNode<T> *&p)
{
	p = C_Head;
	int a = 1;
	while (p->C_Next!=NULL && p != NULL && o(p->C_Data, x) && o(p->C_Next->C_Data, x))
	{ 
		if (o(p->C_Data, x)) { cout << "Es " << p->C_Data << " menor a " << x << endl; }
		cout << "Entre " << a++ << endl;
		p = p->C_Next; 
		cout << "Avance el p a su next" << endl;
	}
	
	return p && (p->C_Data) == x;
}

template<class T, class Op>
bool CList<T, Op>::insert(T x)
{
	if (C_Head==NULL|| o(x,C_Head->C_Data)) {
		cout << "Entre al if" << endl;
		CNode<T> *temp = C_Head;
		C_Head = new CNode<T>(x);
		C_Head->C_Next = temp;
		return 1;
	}
	CNode<T> *p;
	if (find(x, p)) { return 0; }
	if (p->C_Next==NULL&& o(p->C_Data, x)) {
		cout << "Entro al if" << endl;
		cout << "VALOR P:" << p->C_Data << endl;
		CNode<T>*temp = new CNode<T>(x);
		p->C_Next = temp;
		return 1;		
	}
	cout << "No entre al if" << endl;
	cout << "VALOR P:" << p->C_Data << endl;
	CNode<T> *temp = new CNode<T>(x);
	temp->C_Next = p->C_Next;
	p->C_Next = temp;
	return 1;
}
template<class T, class Op>
bool CList<T, Op>::remove(T x)
{
	CNode<T> *p;
	//if (!find(x, p)) { return 0; }
	if (C_Head == NULL || !find(x, p)) { return 0; }
	if (C_Head->C_Next == NULL) {
		CNode<T>*temp = C_Head;
		delete temp;
		return 1;
	}
	if (x == C_Head->C_Data ) {
		CNode<T> *temp = C_Head;
		C_Head = C_Head->C_Next;
		delete temp;
		return 1;
	}
	CNode<T> *temp = p->C_Next;
	delete temp;
	return 1;	
}
template<class T, class Op>
void CList<T, Op>::print()
{
	CNode<T>*temp = C_Head;
	while (temp) {
		cout << temp->C_Data << ' ';
		temp = temp->C_Next;
	}
}

int main()
{
	CList<int, Menor<int>> list_cueck;
	cout << "Lista Enlazada Doble Puntero Sin Repeticiones" << endl;
	unsigned int i1, i2;
	int num1, num2;
	cout << "Cuantos Elementos quiere ingresar: ";
	cin >> i1;
	cout << "Cuantos Elementos quiere borrar: ";
	cin >> i2;
	for (unsigned int i = 0; i < i1; i++) {
		cout << "Ingrese el elemento que quiere agregar: ";
		cin >> num1;
		list_cueck.insert(num1);
		list_cueck.print();
		cout << " " << endl;
	}
	for (unsigned int i = 0; i < i2; i++) {
		cout << "Ingrese el elemento que quiere borrar: ";
		cin >> num2;
		list_cueck.remove(num2);
		list_cueck.print();
		cout << " " << endl;
	}
	cout << "Adios xd" << endl;
	list_cueck.print();
	cout << "" << endl;
}


