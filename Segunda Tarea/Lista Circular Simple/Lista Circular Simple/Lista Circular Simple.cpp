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


template <class T>
struct CNode {
	CNode<T>* C_Next;
	CNode<T>* C_Prev;
	T C_Data;
	CNode(T x) {
		C_Data = x;
		C_Next = C_Prev = this;
	}
};

template <class T, class Op>
class CList {
	CNode<T>* C_Head;
	CNode<T>* C_Tail;
	unsigned int len = 0;
	Op o;
public:
	CList();
	bool find(T x, CNode<T>*& p);
	bool insert(T x);
	bool remove(T x);
	void print();
	void Josephus_cueck(int ciclos);
};

template <class T, class Op>
CList<T, Op>::CList() {
	this->C_Head = this->C_Tail = 0;
}

template <class T, class Op>
bool CList<T, Op>::find(T x, CNode<T>*& p) {
	if (!C_Head) return 0;
	for (p = (C_Head); o(p->C_Data, p->C_Next->C_Data) && o(p->C_Data, x); p = (p)->C_Next);
	return (p)->C_Data == x;
}

template <class T, class Op>
bool CList<T, Op>::insert(T x) {
	if (!C_Head) {
		C_Head = new CNode<T>(x);
		C_Tail = C_Head;
	}
	else {
		CNode<T>* p;
		if (find(x, p)) return 0;
		CNode<T>* N_Temp = new CNode<T>(x);
		if (p == C_Tail) {
			if (p->C_Data < x) {
				N_Temp->C_Next = C_Head;
				p->C_Next = N_Temp;
				N_Temp->C_Prev = p;
				C_Head->C_Prev = N_Temp;
				C_Tail = N_Temp;
			}
			else {
				N_Temp->C_Next = p;
				N_Temp->C_Prev = p->C_Prev;
				p->C_Prev->C_Next = N_Temp;
				p->C_Prev = N_Temp;
			}
		}
		else if (p == C_Head) {
			N_Temp->C_Next = p;
			N_Temp->C_Prev = C_Tail;
			p->C_Prev = N_Temp;
			C_Head = N_Temp;
			C_Tail->C_Next = N_Temp;
		}
		else {
			N_Temp->C_Next = p;
			N_Temp->C_Prev = p->C_Prev;
			p->C_Prev->C_Next = N_Temp;
			p->C_Prev = N_Temp;
		}
	}
	len++;
	return 1;
}

template <class T, class Op>
bool CList<T, Op>::remove(T x) {
	if (C_Head == C_Head->C_Next) {
		delete C_Head;
		C_Head = C_Tail = 0;
		return 0;
	}
	CNode<T>* p;
	if (!find(x, p)) return 0;
	if (p == C_Head) {
		C_Head = (p)->C_Next;
		C_Head->C_Prev = C_Tail;
		C_Tail->C_Next = C_Head;
	}
	else if (p == C_Tail) {
		C_Tail = (p)->C_Prev;
		C_Tail->C_Next = C_Head;
		C_Head->C_Prev = C_Tail;
	}
	else {
		(p)->C_Prev->C_Next = (p)->C_Next;
		(p)->C_Next->C_Prev = (p)->C_Prev;
	}
	delete p;
	len--;
	return 1;
}

template <class T, class Op>
void CList<T, Op>::print() {
	if (!C_Head) cout << endl;
	else {
		CNode<T>* temp;
		for (temp = C_Head; o(temp->C_Data, temp->C_Next->C_Data); temp = temp->C_Next) {
			cout << temp->C_Data << " ";
		}
		cout << temp->C_Data << endl;
	}
}

template <class T, class Op>
void CList<T, Op>::Josephus_cueck(int ciclos) {
	CNode<int>* temp = C_Head;

	while (len > 2) {
		for (int i = 0; i < ciclos - 1; i++) {
			temp = temp->C_Next;
		}
		T tmp = temp->C_Data;
		temp = temp->C_Next;
		cout << "Shine Kakyoin: " << tmp << endl;
		remove(tmp);
	}
	cout << "Los Soldados Pecho Plateado que sobrevivieron fueron estos xdd: " << C_Head->C_Data << " " << C_Head->C_Next->C_Data << endl;
	cout << "IM SO ALONE XD" << endl;

}

int main(int argc, char *argv[]) {

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
	}
	for (unsigned int i = 0; i < i2; i++) {
		cout << "Ingrese el elemento que quiere borrar: ";
		cin >> num2;
		list_cueck.remove(num2);
		list_cueck.print();
	}
	cout << "Adios xd" << endl;
	list_cueck.print();
	unsigned int watashiwaldes;
	cout << "Ingrese los ciclos del Josephus: ";
	cin >> watashiwaldes;
	list_cueck.Josephus_cueck(watashiwaldes);
	//list_cueck.~CList<int,Menor<int>> ();
	return 0;
}