#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
int count=0;
using namespace std;
struct med
{	
	int sno;
	int days;
};
struct ll
{
	int rollno;
	char name[25];
	int att;
	//int med=0;
	struct ll *next;
}typedef node;
class list
{	
	public:
		node *q;
		list();
		void insert(int loc,int val,char *nam);
		void del(int loc);
		void display();
		void reverse();
		void free();
	//	void sort();
};
list::list()
{
	q=NULL;
}
void list::insert(int loc,int val,char* nam)
{
	node *temp,*s=q;
	if(!(q))
	{
		q=(node *)malloc(sizeof(node));
		q->rollno=val;
		strcpy(q->name,nam);
		q->next=NULL;
		cout<<"\nList created";
	}
	else if(loc==1)
	{
	
		temp=(node *)malloc(sizeof(node));
		temp->rollno=val;
		strcpy(temp->name,nam);
		if(count==0)
		{
		temp->next=NULL;
		q=temp;
		}
		else
		{
			temp->next=s;
			(q)=temp;
		}
	}
	else
	{	
		for(;s->next!=NULL;)
		{
			s=s->next;
		}
		node *temp=(node *)malloc(sizeof(node *));
		temp->rollno=val;
		strcpy(temp->name,nam);
		temp->next=s->next;
		s->next=temp;
		//q=s;
	}
	count++;
	cout<<"\nElement inserted";
}
void list::del(int loc)
{
	node *temp,*s=q,*t;
	temp=(node *)malloc(sizeof(node));
	if(q==NULL)
	{
		cout<<"\nthe list is empty";
	}
	else if(loc==1)
	{
		q=(q)->next;
	}
	else if(loc<=count)
	{
		for(int i=2;i<loc;i++)
			s=(s)->next;
		t=s;
		s=(s)->next;
		temp=s;
		if(loc==count)
			t->next=NULL;
		else
			t->next=(s)->next;
		delete temp;
			
	}
	else
	{
		cout<<"\nenter correct location.....\navailable locations till...."<<count;
		return;
	}
	count--;
}
void list::display()
{
	node *s=q;
	for(;s!=NULL;)
	{
		cout<<s->name<<'\t';
		s=s->next;
	}
}
void list::reverse() 
{
	
	cout<<"\nFUNC IN";
	node *p=NULL,*n,*head=q;
	while(head!=NULL)
	{
		n=head->next;
		head->next=p;
		p=head;
		head=n;
	}
	q=p;
	display();
}
void list::free()
{
	delete q;
}
/*void list::sort()
{
    int swapped, i;
    node *ptr1;
    node *lptr = NULL;
    if (ptr1 == NULL)
        return;
 
    do
    {
        swapped = 0;
        ptr1 = q;
 
        while (ptr1->next != lptr)
        {
            if (ptr1->rollno > ptr1->next->rollno)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
void swap(node *a,node *b)
{
    int temp = a->;
    a->data = b->data;
    b->data = temp;
}
 */
int main()
{
	list l;
	int ch,c=1,lo,d;
	char n[100];
	while(c)
	{	//system("cls");
		cout<<"\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.free\n5.EXIT\n6.REVERSE";
		cin>>ch;
		switch(ch)
		{
			case 1:	cout<<"\nEnter the value,name to be inserted and the location";
					cin>>d>>n>>lo;
					l.insert(lo,d,n);
					break;
			case 2:	cout<<"\nEnter the location to be deleted";
					cin>>lo;
					l.del(lo);
					break;
			case 3:	cout<<"\nThe elements are";
					l.display();
					break;
			case 4:l.free();
			case 5:	c=0;
					break;
			case 6:cout<<"\nREVERSING A LINKED LIST";
					l.reverse();
					break;
			//case 7:l.sort();
			default:cout<<"\nWrong choice";
		}
	}
	//delete l;
	cout<<"\nList deleted";
}

	
	

