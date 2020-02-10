#pragma once
#include "BTNode.h"
#include "Queue.h"

template <class T>
class BinaryTree
{
private:
	BTNode<T>*root;
	void preOrder(BTNode<T> *r){
		if (r == NULL)		
			return;		
		cout<<r->data<<" ";
		preOrder(r->lchild);
		preOrder(r->rchild);
	}
	void inOrder(BTNode<T> *r){
		if (r == NULL)		
			return;		
		inOrder(r->lchild);
		cout<<r->data<<" ";
		inOrder(r->rchild);
	}

	void postOrder(BTNode<T> *r){
		if (r == NULL)		
			return;		
		postOrder(r->lchild);
		postOrder(r->rchild);
		cout<<r->data<<" ";
	}
	void destroy(BTNode<T> *r){
		if (r==NULL)		
			return ;		
		destroy(r->lchild);
		destroy(r->rchild);
		delete r;
	}
	bool isMember(BTNode<T> *r, T data){
		if (r == NULL)
			return false;
		else if(r->data == data)
			return true;
		return isMember(r->lchild,data) || isMember(r->rchild,data);
	}
	bool isClone(BTNode<T> *r1, BTNode<T> *r2){
		if(r1==NULL && r2==NULL)
			return true;
		else if((r1==NULL && r2 != NULL) || (r1!=NULL && r2 == NULL))
			return false;
		else if(r1->data != r2->data)
			return false;
		return isClone(r1->lchild,r2->lchild) && isClone(r1->rchild,r2->rchild) ;
	}

	bool isSimilar(BTNode<T> *r1, BTNode<T> *r2){
		if(r1==NULL && r2==NULL)
			return true;
		else if((r1==NULL && r2 != NULL) || (r1!=NULL && r2 == NULL))
			return false;
		return isSimilar(r1->lchild,r2->lchild) && isSimilar(r1->rchild,r2->rchild) ;
	}

	int countNodes(BTNode<T> *r)
	{
		if(r==NULL)
			return 0;
		return 1+countNodes(r->lchild);
		return 1+countNodes(r->rchild);
	}

	int greaterParents(BTNode<T> *r)
	{
		if(r==NULL)
			return 0;
		
		if(r->lchild!=NULL || r->rchild!=NULL)
		{
			if(r->rchild == NULL)
			{
				if(r->lchild < r)
					return 1+greaterParents(r->lchild);
				else
					return 0+greaterParents(r->lchild);
			}
			else if(r->lchild == NULL)
			{
				if(r->rchild < r)
					return 1+greaterParents(r->rchild);
				else
					return 0+greaterParents(r->rchild);
			}
			else
			{
				if(r->lchild < r && r->rchild < r)
					return 1+greaterParents(r->lchild);
				else
					return 0+greaterParents(r->lchild);
			}
		}

	}

	bool isFullCompleted(BTNode<T> *r)
	{
		Queue<BTNode<T>*> q;
		int level=1;
		int numOfNodes=1;
		
		if(r == NULL)
			return true;

		q.enqueue(r);

		while(!q.isEmpty())
		{
			BTNode<int> *t;

			for(int i=0; i<numOfNodes; i++)
			{
				if(t=q.dequeue() == NULL)
					break;
				
				if(t->data!=level)
					return false;
				
				q.enqueue(t->lchild);
				q.enqueue(t->rchild);
			}

			if(i < numOfNodes)
				return false;
			
			level++;
			numOfNodes*=2;
		}

	}




public:
	BinaryTree():root(NULL){}
	void buildTree(){
		if (root ==NULL)
			root = new BTNode<T>(5);
		root->lchild = new BTNode<T>(4);
		root->rchild = new BTNode<T>(9);
		root->lchild->rchild = new BTNode<T>(2);
		root->rchild->lchild = new BTNode<T>(6);
		root->rchild->rchild = new BTNode<T>(15);
	}

	void buildTree(int dummy){
		if (root ==NULL)
			root = new BTNode<T>(5);
		root->lchild = new BTNode<T>(4);
		root->rchild = new BTNode<T>(9);
		root->lchild->rchild = new BTNode<T>(dummy);
		root->rchild->lchild = new BTNode<T>(6);
		root->rchild->rchild = new BTNode<T>(15);
	}
	void preOrder(){//wrapper method
		cout<<"\nPreOrder : ";
		preOrder(root);
	}
	void inOrder(){//wrapper method
		cout<<"\nInOrder : ";
		inOrder(root);
		
	}
	void postOrder(){//wrapper method
		cout<<"\nPostOrder : ";
		postOrder(root);
	}
	void levelOrder(){
		if(root==NULL)
			return;
		Queue<BTNode<T>*> que;
		que.enqueue(root);
		while (!que.isEmpty())
		{
			BTNode<T> *r = que.dequeue();
			cout<<r->data<<" ";
			if(r->lchild !=NULL)
				que.enqueue(r->lchild);
			if(r->rchild !=NULL)
				que.enqueue(r->rchild);
		}		
	}
	bool isMember(const T &data){
		return isMember(root,data);
	}
	bool isClone(const BinaryTree &bt){
		return isClone(root,bt.root);	
	}

	bool isSimilar(const BinaryTree &bt){
		return isSimilar(root,bt.root);	
	}
	~BinaryTree(){
		destroy(root);
		root = NULL;
	}

	bool numberOfNodes()
	{
		int c;
		c=countNodes(root);

		if(c % 2 == 0)
			return true;

		return false;
	}



};




