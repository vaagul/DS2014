#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
class node
{
	public:
		int stck[2];
		node * next;
};
template <class T>
class stack
{
		
	public:
		node *top;
		stack duplicate();
		stack();
		void push(T,T);
		void pop();
		void display();
		inline int topper()
		{
			node *s=top;
			int count=0;
			while(s->next!=NULL)
			{
				s=s->next;
				count++;
			}
			return ++count;
		}
		inline bool isempty()
		{
			return (!top);
		}
};

template <class T>
stack<T> stack<T> ::duplicate()
{
	stack<T> dup;
	dup.top=(node *)malloc(sizeof(node));
	dup.top->stck[0]=top->stck[0];
	dup.top->stck[1]=top->stck[1];
	dup.top->next=NULL;
	node *n=top,*m=dup.top;
	n=n->next;
	while(n!=NULL)
	{
		node *g;
		g=(node *)malloc(sizeof(node));
		g->stck[0]=n->stck[0];
		g->stck[1]=n->stck[1];
		g->next=NULL;
		m->next=g;
		m=m->next;
		n=n->next;
	}
	return dup;
}

template <class T>
stack<T>::stack()
{
	top=NULL;
}

template <class T>
void stack<T>::push(T x,T y)
{
	node *n;
	n=(node *)malloc(sizeof(node));
	n->stck[0]=x;
	n->stck[1]=y;
	n->next=NULL;
	if(!top)
	{
		top=n;
	}
	else
	{
		n->next=top;
		top=n;	
	}
		
}
template <class T>
void stack<T>::pop()
{
	if(!top)
		{
			
		}
	else
		{
			node *n=top;
			top=top->next;
			n->next=NULL;
			free(n);
		}
}
template <class T>
void stack<T>::display()
{
	node *n=top;
	while(!n)
		return;
	while(n->next!=NULL)
	{
		cout<<" "<<n->stck[0]<<","<<n->stck[1]<<"\n";
		n=n->next;
	}
	cout<<" "<<n->stck[0]<<","<<n->stck[1];
}
