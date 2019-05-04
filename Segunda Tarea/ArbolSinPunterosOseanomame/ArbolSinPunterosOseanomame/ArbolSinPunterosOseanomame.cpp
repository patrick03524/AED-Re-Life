
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
class TNode {
public:
	T T_x;
	unsigned int hijo_menor_pos,hijo_may_pos,pos = 0;
	TNode() {
		pos = 0;
		hijo_menor_pos = hijo_may_pos = 0;
	}
	TNode(T scuack) {
		T_x = scuack;
		pos = 0;
		hijo_menor_pos = hijo_may_pos = 0;
	}
};
template<class T, class Op, unsigned int len>
class BTree {
public:
	bool T_Raiz;
	TNode<T> T_Nodes[len];
	Op o;
	unsigned int current_len = 0;
	BTree() {
		T_Raiz = 0;
	}
	bool find(T x, unsigned int &Node_pos);
	bool insert(T x);
	bool Remove(T x);
	void print();
};
template<class T, class Op, unsigned int len>
bool BTree<T, Op, len>::find(T x, unsigned int &Node_pos) {
	if (T_Nodes[0].T_x == x) { Node_pos = 0; cout << "BUSCATE LA CABEZA LOCO" << endl; return 1; }
	if (o(T_Nodes[0].T_x, x)) {
		cout << x << " le corresponde ser hijo mayor" << endl;
		return 1;
	}
	else {
		cout << x << " le corresponde ser hijo menor" << endl;
		return 1;
	}
	
}
template<class T, class Op, unsigned int len>
bool BTree<T, Op, len>::insert(T x) {
	unsigned int current_pos = 0;
	if (!T_Raiz) {
		T_Nodes[0] = x; T_Nodes[0].hijo_menor_pos = 1; T_Nodes[0].hijo_may_pos = 2;
		cout << "Creaste la cabeza" << endl;
		T_Raiz = 1;
		current_len++;
		return 1;
	}
	if (!find(x, current_pos)) { return 1; }
	
}
template<class T, class Op, unsigned int len>
void BTree<T, Op, len>::print() {
	cout << "ARBOL: " << endl;
	for (unsigned int i = 0; i < len; i++) {
		cout << " VALUE: "<< T_Nodes[i].T_x << endl;
		cout << "HIJOMENOR POS: " << T_Nodes[i].hijo_menor_pos << endl;
		cout << "HIJOMAYOR POS: " << T_Nodes[i].hijo_may_pos << endl;
		cout << "---------------------------------------------------------" << endl;
	}
}

int main()
{
	BTree<int, Menor<int>, 10> T_Cueck;
	T_Cueck.insert(30);
	T_Cueck.print();
	T_Cueck.insert(40);
	T_Cueck.insert(30);
	T_Cueck.insert(20);

}


