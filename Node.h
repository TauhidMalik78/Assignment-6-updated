

#include <iostream>
#include "LinkedList.h"
using namespace std;

#ifndef NODE_H
#define NODE_H
template <class T>
struct Node {
	T data;
	Node<T>* ptr;
};

#endif