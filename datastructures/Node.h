#ifndef _NODE_
#define _NODE_

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

class Node{
public:
	int data;
	Node *next;
	Node();
	Node(int d);
};

#endif