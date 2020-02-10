#include "LinkedList.h"


LinkedList::LinkedList(){
	sz=0;
	head=NULL;
}

int LinkedList::size()const{
	return sz;
}

bool LinkedList::isEmpty()const{
	return sz==0;
}

bool LinkedList::isFull()const{
	return false;
}

void LinkedList::print()const{
	Node *walk=head;
	if(walk!=NULL){
		while(walk!=NULL)
		{
			cout<<walk->data<<"->";
			walk=walk->next;
		}
		cout<<"NULL";
	}
	else
		cout<<"Empty"<<endl;
}

void LinkedList::insertFront(int data){
	Node *newNode=new Node(data);
	newNode->next=head;
	head=newNode;
	sz++;
}

void LinkedList::insertEnd(int data){
	Node *newNode = new Node(data);
	Node *walk = head;
	if(walk ==NULL){
		head =newNode;
		sz++;
		return;
	}
	while (walk->next!=NULL)
	{
		walk = walk->next;
	}
	walk->next = newNode;
	sz++;
}

bool LinkedList::retrieve(int position, int &x) const{
	Node *walk=head;
	int count=0;
	while(walk!=NULL){
		if(0 <= position && position < sz)
		{
			if(count == position)
			{
				x=walk->data;
				return true;
			}

			walk=walk->next;
			count++;
		}

		else
			return false;
	}
	return false;
}

bool LinkedList::remove(int position, int &x){
	Node *prev=NULL;
	Node *walk = head;
	int count=0;
	if(!isEmpty())
	{
		if(0 <= position && position < sz)
		{
			while(walk!=NULL)
			{
				if(count == position)
				{
					if(prev == NULL)
					{
						x=walk->data;
						Node *t=head;
						head=head->next;
						delete t;
						sz--;
						return true;
					}
					else
					{
						x=walk->data;
						prev->next = walk->next;
						delete walk;
						sz--;
						return true;
					}
				}

				else
				{
					prev = walk;
					walk = walk->next;
					count++;
				}
			}

		}

		else
			return false;
	}
	return false;
}

bool LinkedList::insert(int position, const int &x){
	Node *prev=NULL;
	Node *newNode = new Node(x);
	Node *walk = head;
	int count=0;

	if(!isFull())
	{
		if(position <= sz && position >= 0)
		{
			if(count == position){
				newNode->next = head;
				head = newNode;
				sz++;
				return true;
			}

			while (count!=position)
			{
				prev = walk;
				walk = walk->next;
				count++;
			}

			if(walk == NULL)
			{
				prev->next = newNode;
				sz++;
				return true;
			}

			else
			{
				walk->next = newNode;
				sz++;
				return true;
			}
		}
		return false;
	}
	return false;
}

void LinkedList::clear(){
	Node *t=head;
	if(!isEmpty())
	{
		while(t!=NULL)
		{
			head = head->next;
			delete t;
			sz--;
			t = head;
		}
	}
}

bool LinkedList::remove(int val){
	Node *prev=NULL;
	Node *walk=head;
	int flag=0;
	if(!isEmpty())
	{
		while(head!=NULL)
		{
			if(head->data == val)
			{
				Node *t=head;
				head=head->next;
				delete t;
				sz--;
				flag=1;
			}

			else
				break;
		}

		if(head!=NULL)
		{
			prev=head;
			walk=head->next;
			while(walk!=NULL)
			{
				if(walk->data==val)
				{
					prev->next=walk->next;
					delete walk;
					sz--;
					flag=1;
					walk=prev->next;
				}
				else
				{
					prev=walk;
					walk=walk->next;
				}
			}
		}

		if(flag==1)
			return true;
		return false;
	}
	return false;
}

int LinkedList::indexOf(int val)const{
	Node *walk=head;
	int count=0;
	while(walk!=NULL)
	{
		if(walk->data == val)
			return count;
		else
		{
			walk=walk->next;
			count++;
		}
	}
	return -1;
}

bool LinkedList::numberOfNodes(){
	Node *walk=head;
	int count=0;

	while(walk!=NULL)
	{
		walk = walk->next;
		count++;
	}

	if(count % 2 == 0)
		return true;

	return false;
}

bool LinkedList::isSymmetric(LinkedList l2)
{
	Stack<int> s;
	Node *walk=l2.head;
	Node *walk2=head;

	if(sz != l2.sz)
		return false;

	while(walk != NULL)
	{
		s.push(walk->data);
		walk=walk->next;
	}

	while(walk2 != NULL)
	{
		int d;
		s.pop(d);

		if(walk2->data != d)
			return false;

		walk2=walk2->next;
	}

	return true;
}

LinkedList LinkedList::sortAndMerge(LinkedList l1, LinkedList l2)
{
	LinkedList l3;
	Node *walk1=l1.head;
	Node *walk2=l2.head;

	if(walk1->data < walk2->data)
	{
		Node *newNode = new Node(walk1->data);
		l3.head=newNode;
		walk1=walk1->next;
	}
	else
	{
		Node *newNode = new Node(walk2->data);
		l3.head=newNode;
		walk2=walk2->next;
	}

	Node *walk3=l3.head;

	while(walk1!=NULL || walk2!=NULL)
	{
		if(walk1 == NULL)
		{
			Node *newNode = new Node(walk2->data);
			walk3->next=newNode;
			walk3=walk3->next;
			walk2=walk2->next;
		}

		else if(walk2 == NULL)
		{
			Node *newNode = new Node(walk1->data);
			walk3->next=newNode;
			walk3=walk3->next;
			walk1=walk1->next;
		}
		else
		{
			if(walk1->data < walk2->data)
			{
				Node *newNode = new Node(walk1->data);
				walk3->next=newNode;
				walk3=walk3->next;
				walk1=walk1->next;
			}
			else
			{
				Node *newNode = new Node(walk2->data);
				walk3->next=newNode;
				walk3=walk3->next;
				walk2=walk2->next;
			}
		}
	}

	return l3;
}






































