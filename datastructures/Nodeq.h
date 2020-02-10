#ifndef _NODEQ_
#define _NODEQ_
#include <iostream>
using namespace std;
template <class T>
class Nodeq{
public:
	T data;
	Nodeq *next;
	Nodeq():next(NULL){}
	Nodeq (const T &d):data(d),next(NULL){}
};

#endif