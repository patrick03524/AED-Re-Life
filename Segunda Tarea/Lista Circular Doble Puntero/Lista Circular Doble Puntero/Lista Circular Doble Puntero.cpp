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
	CNode(T x, CNode<T>* cueck=0) {
		C_Data = x;
		C_Next = cueck;
	}
};

template<class T, class Op>
class CList {
public:
	CNode<T> *C_Head;
	//CNode<T> *C_Tail;
	Op o;
	unsigned int len;
	CList() { C_Head = 0; len = 0; }
	~CList()
	{
		if (!C_Head) { return; }
		CNode<T> *temp2 = C_Head->C_Next;
		while (temp2&&temp2 != C_Head) {
			CNode<T> *cuack;
			cuack = temp2;
			temp2 = temp2->C_Next;
			delete cuack;
		}
		delete temp2;
	}

	bool find(T x, CNode<T> **&p);
	bool insert(T x);
	bool remove(T x);
	void print();
	//void get_last(CNode<T> **&p);
	//void Josephus_cueck(CNode<T> *superv1, CNode<T> *superv2, unsigned int ciclos);
	void Josephus_cueck(unsigned int ciclos);
};
/*template<class T, class Op>
bool CList<T, Op>::find(T x, CNode<T> **&p)
{

	p = &C_Head;
	if (!(*p)) { return 0; }
	if (!o((*p)->C_Data,x)){ return (*p)->C_Data == x; }
	p = &(*p)->C_Next;
	for (*p; *p && o((*p)->C_Data, x) && (*p) != C_Head; p = &(*p)->C_Next);
	return (*p) && (*p)->C_Data == x;
}*/
template<class T, class Op>
bool CList<T, Op>::find(T x, CNode<T> **&p)
{

	p = &C_Head;
	if (!(*p)) { return 0; }
	if (*p && (*p)->C_Next && o((*p)->C_Data, x)) { p = &(*p)->C_Next; }
	for (*p; *p && o((*p)->C_Data, x) && (*p) != C_Head; p = &(*p)->C_Next);
	return (*p) && (*p)->C_Data == x;
}
template<class T, class Op>
bool CList<T, Op>::insert(T x)
{
	CNode<T> **p;
	if (find(x, p)) { return 0; }
	if (*p && o(x,(*p)->C_Data)) {
		cout << "COCHINO Y FEO UF CSMREEEEEEEEEEEEEEEE" << endl;
		CNode<T> *temp = new CNode<T>(x);
		temp->C_Next = *p;
		//*p = temp;
		for (; (*p)!= C_Head; p = &(*p)->C_Next);
		(*p)->C_Next = temp;
		C_Head = *p;
		//for (r = *p; r->C_Next != C_Head; r = r->C_Next);
		//r->C_Next = C_Head;
		return 1;
	}
	/*CNode<T> *temp = new CNode<T>(x);
	temp->C_Next = *p;
	*p = temp;*/
	*p = new CNode<T>(x, *p);
	if (!(*p)->C_Next) {	
		(*p)->C_Next = C_Head;
	}
	
	len++;
	return 1;
}
/*
template<class T, class Op>
bool CList<T, Op>::find(T x, CNode<T> **&p)
{

	p = &C_Head;
	if (!(*p)) { return 0; }
	p = &(*p)->C_Next;
	for (*p; *p && o((*p)->C_Data, x) && (*p) != C_Head; p = &(*p)->C_Next);
	return (*p) && (*p)->C_Data == x;
}*/
/*template<class T, class Op>
bool CList<T, Op>::find(T x, CNode<T> **&p)
{
	//for (p = &C_Head; (*p) && o((*p)->C_Data, x) ; p = &((*p)->C_Next));
	p = &C_Head;
	if((*p) && (*p)->C_Next==C_Head && o((*p)->C_Data, x)){
		p = &(*p)->C_Next;
		return (*p) && (*p)->C_Data == x;
	}
	while ((*p) && o((*p)->C_Data, x)) {
		p = &(*p)->C_Next;
	}

	//if((*p)==C_Tail){}
	return (*p) && (*p)->C_Data == x;
}

template<class T, class Op>
bool CList<T, Op>::insert(T x)
{
	CNode<T> **p, **q;
	if (find(x, p)) { return 0; }
	CNode<T> *temp = new CNode<T>(x,*p);
	//temp->C_Next = *p;
	*p = temp;
	while ((*p) &&(*p)->C_Next != NULL) { (*p) = (*p)->C_Next; }
	(*p)->C_Next = C_Head;
	//get_last(q);
	//(*q)->C_Next = C_Head;
	return 1;
}*/
template<class T, class Op>
bool CList<T, Op>::remove(T x)
{
	CNode<T> **p;
	if (!find(x, p)) { return 0; }
	CNode<T> *temp = *p;
	*p = temp->C_Next;
	delete temp;
	len--;
	return 1;
}

template<class T, class Op>
void CList<T, Op>::print()
{
	if (!C_Head) { return; }
	CNode<T>*temp = C_Head;
	cout << temp->C_Data << ' ';
	temp = temp->C_Next;
	while (temp!=C_Head) {
		cout << temp->C_Data << ' ';
		temp = temp->C_Next;
	}
}
template<class T, class Op>
//void CList<T, Op>::Josephus_cueck(CNode<T> *superv1, CNode<T> *superv2, unsigned int ciclos)
void CList<T, Op>::Josephus_cueck(unsigned int ciclos)
{
	if (!C_Head) { return; }
	cout << "Josephus C Mama Nii" << endl;
	CNode<T> *temp = C_Head;
	while (len > 2) {
		for (unsigned int i = 0; i < ciclos-1; i++) {
			temp = temp->C_Next;
		}
		T mesias = temp->C_Data;	
		temp = temp->C_Next;
		cout << "Elemento Eliminado: " << mesias << endl;
		remove(mesias);	
	}
	//superv1 = C_Head;
	//superv2 = C_Head->C_Next;
	cout << "Elementos sobrevivientes del Desastre Global: " << C_Head->C_Data << " - " << C_Head->C_Next->C_Data << " //" << endl;

}
/*template<class T, class Op>
void CList<T, Op>::get_last(CNode<T> **&p)
{
	if (!C_Head) { return; }
	p = &C_Head;
	if ((*p)->C_Next == C_Head) {
		p = &((*p)->C_Next);
		return ;
	}
	for (; (*p) && (*p)->C_Next != C_Head; p = &((*p)->C_Next));
	return ;
}*/

int main()
{
	CList<int, Menor<int>> 	
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
	unsigned int watashiwaldes;
	cout << "Ingrese los ciclos del Josephus: ";
	cin >> watashiwaldes;
	list_cueck.Josephus_cueck(watashiwaldes);
	//list_cueck.~CList<int,Menor<int>> ();	

}