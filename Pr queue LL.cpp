#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
		node (int data)
		{
			this->data=data;
			this->next=NULL;
		}
};
class Queue{
	public:
		node *front;
		node *rare;
		Queue()
		{
			front=NULL;
			rare=NULL;
		}
		void enqueue(int data)
		{
			if(front==NULL && rare==NULL)
			{
				rare=new node(data);
				front=rare;
			}
			else
			{
				rare->next=new node(data);
				rare=rare->next;
			}
		}
		void dequeue()
		{
			if(front==NULL && rare==NULL)
			{
			cout<<"EMPTY";
			}
			else if(front==rare)
			{
				node *temp=front;
				front=NULL;
				rare=NULL;
				delete(temp);
			}
			else
			{
				node *temp=front;
				front=front->next;
				delete(temp);
			}
		}
		int peek()
		{
			if(front==NULL && rare==NULL)
			{
			cout<<"EMPTY";
			return 0;
			}
			else
			return front->data;
		}
};
int main()
{
	Queue Q; 
	Q.enqueue(6);
	Q.enqueue(8);
	Q.enqueue(3);
	Q.enqueue(7);
//	Q.enqueue(1);
	cout<<Q.peek()<<" ";
	Q.dequeue();
	cout<<Q.peek()<<" ";
	Q.dequeue();
	cout<<Q.peek()<<" ";
	Q.dequeue();
	cout<<Q.peek()<<" ";
	Q.dequeue();
	cout<<Q.peek()<<" ";
	Q.dequeue();
}
