#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include "Node.h"
#include "Stack.h"

class LinkedList{
private:
	Node *head;
	int sz;
public:
	LinkedList();
	int size()const;
	bool isEmpty()const;
	bool isFull()const;
	void print()const;
	void clear();
	void insertFront(int data);
	void insertEnd(int data);
	bool retrieve(int position, int &x) const;
	bool remove(int position, int &x);
	bool remove(int val);
	bool insert(int position, const int &x);
	int indexOf(int val)const;
	
	bool numberOfNodes();
	bool isSymmetric(LinkedList l2);
	LinkedList sortAndMerge(LinkedList l1, LinkedList l2);
};
#endif