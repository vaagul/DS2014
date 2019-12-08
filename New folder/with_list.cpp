#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;
#define size 25
#include"list.cpp"
int adj[size][size],visited[size],n;
struct node *s=(struct node *)malloc(sizeof(struct node));
void entervalue()
{
	int i=0,j=0;
	cout<<"\nEnter the number of nodes:";
	cin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			adj[i][j]=0;
	i=j=0;
	cout<<"\nenter the coordinates whose values are 1 in the ADJACENCY MATRIX:";
	cout<<"\nNOTE:To terminate insertion enter the indices as 99 and 99";
	cout<<"\nPRESS ENTER TO PROCEED\n";
	getch();
	while(i!=99 && j!=99)
	{
		cout<<"enter the values :"<<endl;
		cin>>i>>j;
		adj[i][j]=1;
		adj[j][i]=1;
	}
	return;
}
void solution(int o,int e)
{
	int j;
	insert(&s,o);
	if(o==e)
	{
		display(&s);
		return;
	}
	visited[o]=1;
	for(j=0;j<n;j++)
		if(!visited[j]&&adj[o][j]==1)
		{
			solution(j,e);
			del(&s);
		}
}
void display_maze(int n)
{
	int r,no=0,no1=0;
	r=sqrt(n);
	cout<<"The given maze is :"<<endl;
	cout<<"\nNOTE: The lines represent the path of a perfect maze\n";
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
}
int main()
{
	int o,e;
	entervalue();
	for(int i=0;i<n;i++)
		visited[i]=0;
	system("cls");
	display_maze(n);
	cout<<"\nenter the starting point :";
	cin>>o;
	cout<<"\nenter the finishing point :";
	cin>>e;
	system("cls");
	display_maze(n);
	solution(o,e);
	return 0;
}
