#include<stdio.h>
#include<iostream.h>
#define max 20
using namespace std;
int adj[max][max];
int n;
create_graph()
{
	int i,max_edges,origin,destin;
	cout<<"enter the number of nodes";
	cin>>n;
	max_edges=n*(n-1)/2;
	for(i=1;i<=max_edges;i++)
	{
		cout<<"\nenter edge "<<i;
		cout<<"\ngive the values 0 0 to exit";
		cin>>origin>>destin;
		if((origin==0)&&(destin==0))
			break;
		if(origin>n || destin<n || origin<=0 || destin<=0)
		{
			cout<<"\ninvalid entry";
			i--;
		}
		else
		{
			adj[origin][destin]=1;
			adj[destin][origin]=1;
		}	
	}
}
display()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cout<<'\t'<<adj[i][j];
		cout<<endl;
	}
}
main()
{	
	int choice;
	int node,origin,destin;
	create_graph();
	while(1)
	{
			cout<<"1.Insert a node"<<endl;
			cout<<"2.insert an edge"<<endl;
			cout<<"5.display"<<endl;
			cout<<"6.exit"<<endl;
			cout<<"Enter your choice:";
			cin>>choice;
			switch(choice)
			{
				case 1:
					insert_node();
					break;
				case 2:
					cout<<"enter an edge to be inserted";
					break;
				case 5:
					display();
					break;
				case 6:
					exit();
				default:
					cout<<"\nwrong choice";
			}
	}
}
