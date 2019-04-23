
#include "pch.h"
#include <iostream>

using namespace std;

template<class T>
class CNode {
	T valor;
public:
	CNode<T> *siguiente;
	CNode<T> *anterior;
	CNode(T valor, CNode<T> *siguiente = NULL, CNode<T> *anterior = NULL) : siguiente(siguiente), anterior(anterior), valor(valor) {}
	T get_valor() { return this->valor; }
	~CNode() {
		siguiente = NULL;
		anterior = NULL;
		valor = 0;
	}
};

template<class T>
class Lista {
	CNode<T> *head;
public:
	Lista();
	Lista(T valor);
	void InsertNode(T valor);
	void DeleteNode(T valor);
	void Imprimir(char a);
	bool If_empty();
	~Lista() {
		CNode<T> *temp = head;
		CNode<T> *temp2 = head;
		do {
			temp = head;
			temp2 = head;
			temp = temp2 = temp->siguiente;
			temp2 = temp->siguiente;
			head->siguiente = temp2;
			temp2->anterior = head;
			delete temp;
		} while (temp2 != head);
		delete head;
	}
};

template<class T>
Lista<T>::Lista()
{
	head = NULL;
}

template<class T>
Lista<T>::Lista(T valor)
{
	head = new CNode<T>(valor);
	head->anterior = head;
	head->siguiente = head;
}

template<class T>
void Lista<T>::InsertNode(T valor)
{
	CNode<T> *nuevo;
	if (head == NULL) {
		nuevo = new CNode<T>(valor);
		head = nuevo;
		head->anterior = head;
		head->siguiente = head;
	}
	else {
		CNode<T> *temp;
		CNode<T> *temp2;
		temp = head;
		if (temp->get_valor() <= valor) {
			while (temp->get_valor() < valor) {
				temp = temp->siguiente;
				if (temp == head)break;
			}
			if (temp->get_valor() == valor) {
				return;
			}
			cout << "ACA" << endl;///AQUI,PAPU
			temp2 = temp->anterior;
			nuevo = new CNode<T>(valor);
			temp2->siguiente = nuevo;
			temp2 = temp2->siguiente;
			temp2->anterior = temp->anterior;
			temp->anterior = temp2;
			temp2->siguiente = temp;
			//                temp2->anterior = temp->anterior;
			//                temp2->siguiente = temp;
			//                temp->anterior = temp2;

		}
		else {
			temp = temp->anterior;
			while (temp->get_valor() > valor) {
				temp = temp->anterior;
			}
			if (temp->get_valor() == valor) {
				return;
			}

			temp2 = temp->siguiente;
			nuevo = new CNode<T>(valor);
			temp2->anterior = nuevo;
			temp2 = temp2->anterior;
			temp2->siguiente = temp->siguiente;
			temp->siguiente = temp2;
			temp2->anterior = temp;

		}
	}
}

template<class T>
void Lista<T>::DeleteNode(T valor)
{

}

template<class T>
void Lista<T>::Imprimir(char a)
{
	CNode<T> *temp = head;
	if (a == 'a') {
		do {
			cout << temp->get_valor() << endl;
			temp = temp->anterior;
		} while (temp != head);
	}
	else {
		do {
			cout << temp->get_valor() << endl;
			temp = temp->siguiente;
		} while (temp != head);
	}
}

template<class T>
bool Lista<T>::If_empty()
{
	if (head == NULL)return true;
	return false;
}


int main()
{
	Lista<int> lista;
	int num = 1;
	char opcion, dir;
	while (num != 0) {
		cout << " Presione i para insertar, e para eliminar, p para imprimir o z para salir : "; cin >> opcion;
		if (opcion == 'i') {
			cout << "Escriba un valor para insertar en la lista circular doblemente enlazada : "; cin >> num;
			lista.InsertNode(num);
		}
		else if (opcion == 'e') {
			cout << "Escriba un valor para eliminar de la lista circular doblemente enlazada : "; cin >> num;
			lista.DeleteNode(num);
		}
		else if (opcion == 'p') {
			cout << "En que direccion desea imprimir? Para atras presione a, para adelante presione s : "; cin >> dir;
			lista.Imprimir(dir);
		}
		else if (opcion == 'z') {
			num = 0;
		}
	}
	return 0;
}
