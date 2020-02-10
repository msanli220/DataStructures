#ifndef _QUEUE_
#define _QUEUE_
#include "Nodeq.h"
#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

template<class T>
class Queue
{
private:
	Nodeq<T> *front,*back;
public:
	Queue():front(NULL),back(NULL){}
	bool isEmpty()const{
		return front==NULL;
	}
	bool isFull()const{
		return false;
	}
	void enqueue(const T &val)
	{
		if(!isFull())
			if(isEmpty())
			{
				front=back=new Nodeq<T>(val);
			}else{
				back->next=new Nodeq<T>(val);
				back=back->next;
			}
	}
	T dequeue()	{
		if(isEmpty() )
			exit(0);
		T val=front->data;
		Nodeq<T> *old=front;
		if(front==back){
			delete old;
			front=back=NULL;
		}
		else{
			front=front->next;
			delete old;
		}
		return val;
	}
	T itemAtFront()const{
		if(isEmpty() )
			exit(0);
		T val=front->data;
		return val;
	}
	~Queue(){
		Nodeq <T> *tmp=front;
		while(front!=NULL){
			tmp=front;
			front = front ->next;
			delete tmp;

		}
		back=front=NULL;
	}
	Queue(const Queue &other){
		Nodeq<T> *walk,*walk_other;
		if(other.front!=NULL){
			front=new Nodeq<T>(other.front->data);
			walk=front;
			walk_other=other.front->next;
			while(walk_other != NULL){
				walk->next=new Nodeq<T>(walk_other->data);
				back=walk->next;
				walk_other=walk_other->next;
				walk=walk->next;
			}
		}
	}
	const Queue operator=(const Queue &rhs){
		if(this !=&rhs){//in order to avoid self assignment
			Nodeq <T> *tmp=front;
			while(front!=NULL){
				tmp=front;
				front = front ->next;
				delete tmp;

			}
			back=front=NULL;
			Nodeq<T> *walk,*walk_other;
			if(rhs.front!=NULL){
				front=new Nodeq<T>(rhs.front->data);
				walk=front;
				walk_other=rhs.front->next;
				while(walk_other != NULL){
					walk->next=new Nodeq<T>(walk_other->data);
					back=walk->next;
					walk_other=walk_other->next;
					walk=walk->next;
				}

			}
		}
		return *this;
	}

	void readFromFile(Queue<T> &q, char *fname)
	{
		ifstream fileread;
		fileread.open(fname, ios::in);
		while (!fileread.eof())
		{
			T val;
			fileread>>val;
			q.enqueue(val);
		}
		fileread.close();
	}



};//end of Queue class


template<class T>
void printQueue(Queue<T> q)
{
	cout<<"Queue:"<<endl;
	cout<<"Front: ";
	while(! q.isEmpty() )
		cout<<q.dequeue()<<" ";
	cout<<" Back"<<endl;
}

template<class T>
void printQueue(Queue<T> q,string qname)
{
	cout<<"Queue("<<qname<<"):"<<endl;
	cout<<"Front: ";
	while(! q.isEmpty() )
		cout<<q.dequeue()<<" ";
	cout<<" Back"<<endl;
}

#endif