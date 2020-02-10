#ifndef _STACK_
#define _STACK_
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
const int MAXSIZE = 1000;

template<class T>
class Stack{
private:
	int top;
	T items[MAXSIZE];
public:
	Stack(){
		top = -1;	
	}

	bool isEmpty()const{
		return top == -1;
	}

	bool isFull()const{
		return top == (MAXSIZE-1);
	}

	bool pop(T &topItem){
		if(isEmpty())
			return false;
		topItem = items[top];
		top--;
		return true;
	}

	void pop(bool &status, T &topItem){
		if(isEmpty())
			status = false;
		else{
			topItem = items[top];
			top--;
			status =  true;
		}
	}

	bool peek(T &res)const{
		if(isEmpty())
			return false;
		res = items[top];
		return true;
	}

	bool push(const T &item){
		if(isFull())
			return false;
		top++;
		items[top]= item;
		return true;
	}

};
#endif
