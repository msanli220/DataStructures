#include "LinkedList.h"
#include "BinaryTree.h"
#include <iostream>

void printPattern(int sz);
int main(void)
{
	//final 2015-2016 question 2-b
	LinkedList l;
	int b;
	l.insertEnd(1);
	l.insertEnd(1);
	l.insertEnd(1);
	l.insertEnd(1);
	l.insertEnd(1);
	l.insertEnd(1);
	l.insertEnd(1);
	l.insertEnd(1);
	l.insertEnd(1);
	l.insertEnd(1);
	cout<<"List: ";
	l.print();
	cout<<endl;

	b = l.numberOfNodes();

	if(b == 1)
	cout<<"Number of nodes: even"<<endl;
	else
	cout<<"Number of nodes: odd"<<endl;

	//final 2015-2016 question 2-a
	BinaryTree<int> bt;

	bt.buildTree();
	cout<<"Binary tree: ";
	bt.preOrder();
	cout<<endl;

	b=bt.numberOfNodes();

	if(b == 1)
	cout<<"Number of nodes: even"<<endl;
	else
	cout<<"Number of nodes: odd"<<endl;
	
	//final 2015-2016 question 4
	printPattern(4);

	//final 2015-2016 question 5
	LinkedList l1;
	LinkedList l2;
	l1.insertEnd(1);
	l1.insertEnd(2);
	l1.insertEnd(3);
	l2.insertEnd(3);
	l2.insertEnd(2);
	l2.insertEnd(1);

	if(l1.isSymmetric(l2) == true)
		cout<<"List 1 and List 2 are symmetric"<<endl;
	else
		cout<<"List 1 and List 2 are not symmetric"<<endl;

	//final 2014-2015 question 1
	LinkedList listA;
	LinkedList listB;
	LinkedList newList;
	
	listA.insertEnd(2);
	listA.insertEnd(4);
	listA.insertEnd(6);
	listA.insertEnd(8);
	listA.insertEnd(10);
	listB.insertEnd(1);
	listB.insertEnd(3);
	listB.insertEnd(5);
	listB.insertEnd(7);
	listB.insertEnd(9);

	cout<<"List A: ";
	listA.print();
	cout<<endl;
	cout<<"List B: ";
	listB.print();
	cout<<endl;

	newList=newList.sortAndMerge(listA, listB);

	cout<<"New merged list: ";
	newList.print();
	cout<<endl;





	getchar();
	getchar();
	return 0;
}

void printPattern(int sz)
{
	if(sz == 0)
		return ;

	for(int j=4; (j-sz)!=0; j--)
	{
		cout<<" ";
	}

	for(int i=0; i<sz; i++)
	{
		cout<<"* ";
	}

	cout<<endl;

	return printPattern(--sz);
}

















