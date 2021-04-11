#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
		node(int data)
		{
			this->next=NULL;
			this->data=data;
		}
};
class queue{
	public:
		node* front;
		node* rare;
		public:
			queue()
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
				if(rare==NULL && front==NULL)
				{
					cout<<"EMPTY STACK";
					exit(0);
				}
				else if(front==rare)
				{
					front=NULL;
			        rare=NULL;
				}
				else
				{
					node *temp=front;
					front=front->next;
					delete (temp);
				}
			}
			int last()
			{
				return (rare->data);
			}
			int top()
			{
				return (front->data);
			}
			void dispay()
			{
				node *temp=front;
				while(temp!=NULL)
				{
					cout<<temp->data<<" ";
					temp=temp->next;
				}
					}		
};
class stack{
	private:
		queue Q1,Q2;
		public:
			void push(int data)
			{
				Q1.enqueue(data);
			}
				void display()
				{
					Q1.dispay();
				}
			int pop()
			{
				while(Q1.top()!=Q1.last())
				{
					Q2.enqueue(Q1.top());
					Q1.dequeue();
				}
				int c=Q1.last();
				Q1.dequeue();
		if(Q2.front!=NULL)
		{
		
					while(Q2.top()!=Q2.last())
				{
					Q1.enqueue(Q2.top());
					Q2.dequeue();
				}
				Q1.enqueue(Q2.top());
					Q2.dequeue();
				}
				return c;
			}
		
};
int main()
{
	stack S;
	S.push(2);
	S.push(9);
	S.push(0);
	S.push(5);
	S.push(8);
	cout<<S.pop()<<" ";
	cout<<S.pop()<<" ";
	cout<<S.pop()<<" ";
	cout<<S.pop()<<" ";
	cout<<S.pop()<<" ";
}
