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
queue *frontt=NULL;
queue *rare=NULL;
void enqueue(int data)
{
	if(front==NULL && rare==NULL)
	{
		front=new queue(data);
		rare=front;
	}
	else
	{
		rare->next=new queue(data);
		rare=rare->next;
	}
}
int dequeue()
{
	int c;
	if(front==rare)
	{
		c= front->data;
		front=NULL;
		rare=NULL;
	}
	else if(front==NULL && rare==NULL)
	{
		cout<<"EMPTY QUEUE>>0>>";
		return 0;
	}
	else
	{
		c=front->data;
		queue *temp=front;
		front=front->next;
	}
		return c;	
}
void reverse()
{
	while(front!=NULL)
	{
		int c=dequeue();
		if(frontt==NULL)
		{
			frontt=new queue(c);
			rare=frontt;
		}
		else
		{
			queue *temp=frontt;
			frontt=new queue(c);
			frontt->next=temp;
		}
		
	}
	front=frontt;
	queue *temp=front;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
void display()
{
	queue *frontk=front;
	while(frontk!=NULL)
	{
		cout<<frontk->data<<" ";
		frontk=frontk->next;
	}
	cout<<endl;
}
int main()
{
enqueue(55);
enqueue(23);
enqueue(90);
enqueue(10);
enqueue(43);
enqueue(30);
display();
	reverse();
}
