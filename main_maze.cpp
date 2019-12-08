#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;
#define size 25
#include"stack.cpp"
int adj[size][size],visited[size];
stack s(size);
int entervalue()
{
	int count=1;
	int i=0,j=0,n;
	cout<<"\nEnter the number of nodes:";
	cin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			adj[i][j]=0;
	i=j=0;
	cout<<"\nenter the indices whose values are 1 in the ADJACENCY MATRIX:";
	cout<<"\nNOTE:To terminate insertion enter the indices as 99 and 99";
	cout<<"\nPRESS ENTER TO PROCEED\n";
	getch();
	while(i!=99 && j!=99)
	{
		
		cout<<"enter value number "<<count<<":"<<endl;
		cin>>i>>j;
		adj[i][j]=1;
		adj[j][i]=1;
		count++;
	}
	return n;
}
void solution(int n,int o,int e)
{
	int j;
	s.push(o);
	if(o==e)
	{
		s.display();
		return;
	}
	visited[o]=1;
	for(j=0;j<n;j++)
		if(!visited[j]&&adj[o][j]==1)
		{
			solution(n,j,e);
			s.pop();
		}
	cout<<"\n\n";
}
void display_maze(int n)
{
	int r,no=0,no1=0;
	r=sqrt(n);
	cout<<"The given maze is :"<<endl;
	for(int i=0;i<(2*r);i++)
	{
		if(i%2==0)
		{
			for(int j=0;j<r;j++)
			{
				cout<<no;
				if(adj[no][no+1]==0)
					if(no/10 > 0)
						cout<<"  ";
					else
						cout<<"   ";
				else
					if(no/10 > 0)
						cout<<"--";
					else
						cout<<"---";
				no++;
			}
		}
		else
		{
			for(int j=0;j<r;j++)
			{
				if(adj[no1][no1+r]==0)
					cout<<" ";
				else
					cout<<"|";
				cout<<"   ";
				no1++;
			}
		}
		cout<<endl;
	}
	cout<<"\nNOTE: The lines represent the path of a perfect maze\n";
}
int main()
{
	int o,e;
	char ch='y';
	int n=entervalue();
	for(int i=0;i<n;i++)
		visited[i]=0;
	system("cls");
	display_maze(n);
	while(ch=='y')
	{
	for(int i=0;i<n;i++)
		visited[i]=0;	
	s.empty();	
	cout<<"\nenter the starting point :";
	cin>>o;
	cout<<"\nenter the finishing point :";
	cin>>e;
	system("cls");
	display_maze(n);
	solution(n,o,e);
	cout<<"\ndo you want to continue with the same graph?(y/n) ";
	cin>>ch;
}
	return 0;
}
