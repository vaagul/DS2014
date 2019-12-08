#include<iostream>
#include<stdlib.h>
using namespace std;
class stack
{
	public:
		int *s;
		int cap,top;
		stack(int scap=10);
		~stack();
		void push(int x);
	    void pop();
		bool isempty(){return (top==-1);};
		bool isfull(){return (top==cap-1);};
		void display();
		void empty();
};
stack::stack(int scap)
{
	cap=scap;
	top=-1;
	s=new int[cap];
}
stack::~stack()
{
	delete s;
}
void stack::push(int x)
{
	if(!isfull())
		s[++top]=x;
	else
	{
		cout<<"\nsize increased";
		s[++top]=x;
	}
}
void stack::pop()
{
	if(!isempty())
	//	return(top--);
		top--;
}
void stack::display()
{
	cout<<"\nthe solution for the maze is "<<endl;
	for(int i=0;i<=top;i++)
	{
		cout<<s[i]<<'\t';
	}
	cout<<endl<<"\nThe number of steps taken is :"<<top+1;
}
void stack::empty()
{
	top=-1;
}
