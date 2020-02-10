#pragma once
#include <iostream>
using namespace std;
template <class T>
class BTNode{
public:
	T data;
	BTNode *lchild;
	BTNode *rchild;
	BTNode():lchild(NULL),rchild(NULL){}
	BTNode(const T &d):data(d),lchild(NULL),rchild(NULL){}
};