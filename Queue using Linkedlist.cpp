#include<iostream>
using namespace std;
class queue{
	public:
		int data;
		queue *next;
		queue(int data)
		{
			this->data=data;
			this->next=NULL;
		}
};
queue *front=NULL;
queue *rare=NULL;
void enqueue(int data)
{
	if(rare==NULL && front==NULL)
	{
		rare=new queue(data);
		front=rare;
	}
	else
	{
		rare->next=new queue(data);
		rare=rare->next;
	}
}
void dequeue()
{
	
	if(front==NULL)
	{
		cout<<"EMPTY Queue ALREADY"<<endl;
	}
	else if(rare==front)
	{
		rare=NULL;
		front=NULL;
		cout<<"DELETION DONE"<<endl;
	}
	else
	{
		front=front->next;
		cout<<"DELETION DONE"<<endl;
	}
}
void display()
{
	if(front==NULL && rare==NULL)
	{
		cout<<"Empty Queue\n";
	}
	else
	{
	queue *temp=front;
	while(temp!=rare)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<temp->data<<" "<<endl;
    }
}
void peek()
{
	if(front!=NULL)
	{
		cout<<front->data<<endl;
	}
	else
	{
		cout<<"Empty Queue\n";
	}
}
int main()
{
	char G;
	int data;
	cout<<"1> FOR ENTER DATA PRESS 'E'>>\n2> FOR DELETING DATA PRESS 'D'>>\n3> FOR DISPLAY THE PEEK PRESS 'P'>>\n4> FOR DISPLAY ALL ELEMENT PRESS 'W'>>\n";
	A:
		cout<<"CHOOSE ONE:>>";
		cin>>G;
	if(G=='E')
	{
		cout<<"ENTER YOUR DATA>>";
		cin>>data;
		enqueue(data);
	}
	else if(G=='D')
	{
		dequeue();
	}
	else if(G=='P')
	{
		peek();
	}
	else if(G=='W')
	{
		display();
	}
	goto A;
	return 0;
}
