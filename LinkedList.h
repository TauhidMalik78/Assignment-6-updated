#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <iostream>
#include "Node.h"
#include "Composer.h"
using namespace std;

template <class T>
class LinkedList {
private:
	Node<T>* first;
	Node<T>* last;

public:
	LinkedList();
	~LinkedList();
	void printList() const;
	void append(const T data);
	void prepend(const T data);
	bool removeFront();
	void insert(const T data);
	bool remove(const T data);
	bool find(const T data);
	bool isEmpty() const;
	T getFirst() const;
	T getLast() const;
	T* getFirstPtr() const;

};

template <class T>
LinkedList<T>::LinkedList() {
	first = nullptr;
	last = nullptr;
}


template <class T>
void LinkedList<T>::printList() const {
	Node<T>* p = first;

	while (p) {
		cout << p->data << endl;
		p = p->ptr;
	}
	cout << endl;
}

template <class T>
void LinkedList<T>::append(const T data) {
	Node<T>* p = new Node<T>;
	p->data = data;
	p->ptr = nullptr;


	if (!first) {

		first = p;
		last = p;
		p = nullptr;
	}
	else {
		last->ptr = p;
		last = p;
		p = nullptr;
	}
	
}

template <class T>
void LinkedList<T>::prepend(const T data) {

	Node<T>* p = new Node<T>;
	Node<T>* temp;
	p->data = data;

	if (!first) {
		first = p;
		last = p;
		first->ptr = nullptr;
		p = nullptr;
	}
	else {
		temp = first;
		first = p;
		first->ptr = temp;
		p = nullptr;
		temp = nullptr;
	}
	
}

template <class T>
bool LinkedList<T>::removeFront() {
	Node<T>* second;

	if (!first) {
		return false;
	}
	else if (first->ptr == nullptr) {
		delete first;
		first = nullptr;
		return true;
	}
	else {
		second = first->ptr;
		delete first;

		first = second;

		second = nullptr;

		return true;
	}
}

template <class T>
void LinkedList<T>::insert(const T data) {

	Node<T>* temp = new Node<T>;
	Node<T>* scan = first;
	temp->data = data;
	temp->ptr = nullptr;
	
	//ADD A == SITUATION TOO DUMBASS
	if (!first) {
		first = temp;
		last = temp;
		first->ptr = nullptr;
		temp = nullptr;
		printList();
	}
	else{
		while (scan){
			if (scan->ptr == nullptr){
				if (data < scan->data) {
					temp->ptr = first;
					first = temp;
					temp = nullptr;
					printList();
					break;
				}
				else {
					
					last->ptr = temp;
					last = temp;
					temp = nullptr;
					printList();
					break;
				}
				
			}

			else if ((data > scan->data) && (data < scan->ptr->data)) {

				temp->ptr = scan->ptr;
				scan->ptr = temp;
				temp = nullptr;
				printList();
				break;
			}
			
			scan = scan->ptr;
		}
	}
}

template <class T>
bool LinkedList<T>::remove(const T data) {

	Node<T>* scan;
	Node<T>* temp;

	if (first) {
		return false;
	}

	while (scan) {
		if (scan->ptr->data == data) {
			temp = scan->ptr->ptr;

			delete scan->ptr;

			scan->ptr = temp;
			temp = nullptr;

			return true;
		}

		scan = scan->ptr;
	}

	return false;
}

template <class T>
bool LinkedList<T>::find(const T data) {

	Node<T>* scan = first;

	while (scan) {
		if (scan->data == data)
			return true;
		scan = scan->ptr;
	}

	return false;
}

template <class T>
bool LinkedList<T>::isEmpty() const {
	
	if (!first) {
		return true;
	}
	else {
		return false;
	}
}

template <class T>
T LinkedList<T>::getFirst() const {
	return first->data;
}

template <class T>
T LinkedList<T>::getLast() const {
	return last->data;
}

template <class T>
T* LinkedList<T>::getFirstPtr() const{
	return first;
}

template <class T>
LinkedList<T>::~LinkedList() {


}

#endif // !LINKEDLIST_H