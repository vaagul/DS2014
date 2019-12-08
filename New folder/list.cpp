#include<iostream>
#include<stdlib.h>
using namespace std;
int count=0;
struct node
{
	int data;
	struct node *next;
};
void insert(int num)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp=*s;
	struct node *n;
	n->data=num;
	n->next=NULL;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=n;
	return;
}
void del(struct node **q)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp=*q;
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	t=temp->next;
	while(t->next!=NULL)
	{
		temp=temp->next;
		t=t->next;
	}
	temp->next=NULL;
	return;
}
void display(struct node **q)
{
	cout<<"\nthe solution for the maze is:";
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp=*q;
	while(temp->next!=NULL)
	{
		cout<<temp->data<<'\t';
		temp=temp->next;
	}
	cout<<temp->data;
	return;
}
