
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
class C_Node {
public:
	T C_Value;
	C_Node *C_Next;
	C_Node(int val = 0, C_Node *next = NULL) {
		this->C_Value = val;
		this->C_Next = next;
	}
};

template<class T, class Op>
class C_List {
public:
	C_Node<T> *C_Head;
	C_Node<T> *C_Tail;
	Op o;
	C_List() {
		this->C_Head = NULL;
	}

	C_Node<T> *find(int val) {
		C_Node *temp = C_Head;
		while (temp->C_Next != C_Head && temp->C_Next->C_Value < val) { //recorrer la lista buscando el nodo
			temp = temp->C_Next; // find 
		}
		return temp;
	}

	void insert(int val) {
		C_Node* temp2 = new C_Node<T>(val);
		if (C_Head == NULL) {
			C_Head = temp2;
			C_Head->C_Next = C_Head;
			C_Tail = C_Head;
			return;
		}

		C_Node<T> *temp = find(val);

		if (temp == C_Head) {
			if (o(val, temp->C_Value)) {//Insertando antes de la cabeza
				temp = C_Tail;
				C_Node<T> *aux = temp->C_Next; // antigua cabeza
				C_Head = temp2;
				C_Head->C_Next = aux;
			}
			else {//Insertando despues de la cabeza
				if (temp->C_Next == C_Head) {//solo hay un elemento
					C_Tail = temp2;
				}
				C_Node *aux = temp->C_Next; // lo que next a la cabeza
				C_Head->C_Next = temp2;
				temp2->C_Next = aux;
			}
			C_Tail->C_Next = C_Head;
			//return;
		}

		else if (temp == C_Tail) { // Insertando al final
			temp->C_Next = temp2;
			C_Tail = temp2;
			C_Tail->C_Next = C_Head;
			//return;
		}

		else { // Insertando al medio
			temp2->C_Next = temp->C_Next;
			temp->C_Next = temp2;
			C_Tail->C_Next = C_Head;
			//return;
		}
	}


	void remove(int val) {
		cout << "Borrando: " << val << endl;
		cout << endl;
		if (C_Head == C_Tail && C_Head->C_Value == val) {
			C_Head = NULL;
			C_Tail = NULL;
			delete C_Head;
			delete C_Tail;
			return;
		}

		C_Node<T> *temp = find(val);


		if (temp->C_Value == val && temp == C_Head) {//inicio
			C_Head = temp->C_Next;
			delete temp;
			C_Tail->C_Next = C_Head;

		}

		else if (temp->C_Next == C_Tail) {//borrado al final
			C_Node<T> *aux = temp->C_Next->C_Next;
			delete temp->C_Next;
			C_Tail = temp;
			C_Tail->C_Next = C_Head;

		}
		else if (temp->C_Next->C_Value == val) {//despues
			C_Node<T> *aux = temp->C_Next;
			temp->C_Next = temp->C_Next->C_Next;
			delete aux;
			C_Tail->C_Next = C_Head;
		}
	}


	void print() {

		C_Node<T> *temp = C_Head;
		C_Node<T> *aux = temp->C_Next;

		while (aux != C_Head) {
			aux = temp->C_Next;
			cout << "  " << temp->C_Value; //<<"      Dirección : "<<temp<< "         C_Next: "<<temp->C_Next<< endl;
			temp = aux;

		}
		if (temp->C_Next == C_Head) { //Un elemento
			cout << "  " << C_Head->C_Value; //<<"      Dirección : "<<C_Head<< "         C_Next: "<<C_Head->C_Next<< endl;

		}
		cout << endl;
	}

	void Josephus(int k, int n)
	{
		C_Node<T> *C_Head = new C_Node<T>(1);
		C_Node<T> *prev = C_Head;
		for (int i = 2; i <= n; i++)
		{
			prev->C_Next = new C_Node<T>(i);
			prev = prev->C_Next;
		}
		prev->C_Next = C_Head;

		C_Node<T> *ptr1 = C_Head, *ptr2 = C_Head;
		while (ptr1->C_Next->C_Next != ptr1)
		{
			int cont = 1;
			while (cont != k)
			{
				ptr2 = ptr1;
				ptr1 = ptr1->C_Next;
				cont++;
			}
			ptr2->C_Next = ptr1->C_Next;
			ptr1 = ptr2->C_Next;
		}

		cout << "Josephus debe ser el soldado numero: " << ptr1->C_Value << " y su amigo el: " << ptr1->C_Next->C_Value;
	}
};

int main() {
	C_List<int,Menor<int>> list;
	/*
	list.insert(9);
	list.insert(2);
	list.insert(10);
	list.insert(5);
	list.insert(4);
	list.print();
	*/
	list.Josephus(3,50);
	/*
	if(list.C_Head != NULL){
		list.print();}
	else{
		cout<<"Lista Vacía"<<endl;
	}
	*/
	return 0;
}
