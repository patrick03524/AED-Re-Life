
#include "pch.h"
#include <iostream>
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
	int state_null = -1;
	TNode<T> T_Nodes[2];
	TNode(T scuack) {
		T_x = scuack;
		T_Nodes[0] = T_Nodes[1] = 0;
	}
};
template<class T, class Op, unsigned int len>
class BTree {
public:
	TNode<T> T_Head;
	TNode<T> B_Nodes[len];
	Op o;
	unsigned int current_len = 0;
	BTree() {
	}
	bool find(T x, TNode<T> &Head);
	bool insert(T x);
	bool Remove(T x);
};
template<class T, class Op, unsigned int len>
bool BTree<T,Op,len>::find(T x, TNode<T> &temp)
{
	temp = T_Head;
	if (temp->state_null == -1) { return 0; }
	while (temp->state_null == 0 && current_len<len) {
		temp = B_Nodes[o(temp.T_x, x)];)
	}
	return temp->T_x == x;
}
template<class T, class Op, unsigned int len>
bool BTree<T, Op, len>::insert(T x)
{
	if (!T_Head) {
		T_Head->state_null = 0;
		T_Head->T_x = x;
		T_Head->T_Nodes[0] = T_Head->T_Nodes[1] = NULL;
		current_len++;
		return 1;
	}
	TNode<T> temp;
	if (find(x, temp)) { return 0; }
	temp->T_Nodes[o(temp.T_x, x)]->T_x = x;
	temp->T_Nodes[o(temp.T_x, x)]->T_Nodes[0] = temp->T_Nodes[o(o(temp.T_x, x))]->T_Nodes[1] = NULL;
	current_len++;
	return 1;

}
template<class T, class Op, unsigned int len>
bool BTree<T, Op, len>::Remove(T x)
{
	if (!T_Head) { return 0; }
	if (T_Head->T_x == x) {
		current_len--;
		TNode<T> temp;
		temp = T_Head;
		T_Head->T_Nodes[o(T_Head.T_x, x)] = temp;
		delete temp;
		return 1;
	}
	TNode<T> temp;
	if (!find(x, temp)) { return 0; }
	TNode<T> temp2;
	temp2 = temp;
	temp2->T_Nodes[o(T_Head.T_x, x)] = Temp;
	delete temp2;
	current_len--;
	return 1;
}
int main()
{
	BTree<int, Menor<int>, 10> arbol_cueck;
}


