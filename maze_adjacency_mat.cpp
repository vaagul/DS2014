#include<iostream>
#include<math.h>
using namespace std;
#define size 25
#include"stack.cpp"
int adj[size][size],visited[size],n;
stack s(size);
void dfs(int i,int e)
{
	int j;
	//cout<<endl<<i;
	s.push(i);
	if(i==e)
	{
		s.display();
		return;
	}
	visited[i]=1;
	for(j=0;j<n;j++)
		if(!visited[j]&&adj[i][j]==1)
		{
			dfs(j,e);
			s.pop();
		}	
}
void display_maze(int n)
{
	int r,no=0,no1=0;
	r=sqrt(n);
	cout<<"the given maze is :"<<endl;
	for(int i=0;i<(2*r);i++)
	{
		if(i%r==0)
		{
			for(int j=0;j<r;j++)
			{
				cout<<no;
				if(adj[no][no+1]==0)
					cout<<"   ";
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
}
int main()
{
	int i,j;
	int o,e;
	cout<<"\nEnter the number of nodes:";
	cin>>n;
	cout<<"\nenter the adjacency matrix:"<<endl;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>adj[i][j];
	for(i=0;i<n;i++)
		visited[i]=0;
	system("cls");
	display_maze(n);
	cout<<"\nenter the starting point :";
	cin>>o;
	cout<<"\nenter the finishing point :";
	cin>>e;
	display_maze(n);
	cout<<"\nThe staring point is :"<<o;
	cout<<"\nThe ending point is :"<<e;
	system("cls");
	display_maze(n);
	dfs(o,e);
	return 0;
}
