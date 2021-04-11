#include<iostream>
using namespace std;
class node{
	public:
	       int data;
	       node *next;
	node(int data)
	{
		this->data=data;
		this->next=NULL;
	}
};
class stack{
     public:
            node *head;
     stack()
	 {
	 	head=NULL;
	}
			void push(int data)
			{
				if(head==NULL)
				{
					head=new node(data);
				}
				else 
				{
						node *temp=head;
					head=new node(data);
					head->next=temp;	
				}
				
		    }
		    void pop()
		    {
		    
		    		node *temp=head;
		    		head=head->next;
		    		delete(temp);
				
			}
			int top()
			{
				return head->data;
			}
			bool empty()
			{
				if(head==NULL)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
};
class Queue{
	public:
	stack Q1,Q2;
	void enqueue(int data)
	{
		Q1.push(data);
	}
	int dequeue()
	{
	    while(!Q1.empty())
	{
		Q2.push(Q1.top());
		Q1.pop();
	}
	int c=Q2.top();
	Q2.pop();
	while(!Q2.empty())
	{
		Q1.push(Q2.top());
		Q2.pop();
	}
		return c;
	}
	
};
int main()
{
	Queue Q;
	Q.enqueue(6);
	Q.enqueue(8);
	Q.enqueue(3);
	Q.enqueue(7);
	Q.enqueue(1);
	cout<<Q.dequeue();
	cout<<Q.dequeue();
	cout<<Q.dequeue();
	cout<<Q.dequeue();
	cout<<Q.dequeue();
	
}
