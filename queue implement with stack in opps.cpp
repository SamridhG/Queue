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
	private:
		node *head;
		public:
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
			int top()
			{
				return head->data;
			}
			void pop()
			{
				node *temp=head;
				head=head->next;
				delete (temp);
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
class queue{
	private:
		stack s1,s2;
		public:
			void enqueue(int data)
			{
				s1.push(data);
			}
			int dequeue()
			{
				if(s1.empty())
				{ 
                   cout<<"empty"; 
				}
				else
				{
				while(!s1.empty())
				{
					s2.push(s1.top());
					s1.pop();
				}
				int D=s2.top();
				s2.pop();
				while(!s2.empty())
				{
					s1.push(s2.top());
					s2.pop();
				}
				return D;
			}
			}
};
int main()
{
	queue Q;
	Q.enqueue(3);
		Q.enqueue(4);
			Q.enqueue(7);
				Q.enqueue(2);
					Q.enqueue(5);
						Q.enqueue(9);
						  cout<<Q.dequeue()<<" ";
						  cout<<Q.dequeue()<<" ";
						  cout<<Q.dequeue()<<" ";
						  cout<<Q.dequeue()<<" ";
						  cout<<Q.dequeue()<<" ";
						  cout<<Q.dequeue()<<" ";
						  cout<<Q.dequeue()<<" ";
}
