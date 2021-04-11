#include<iostream>
using namespace std;
class queue{
	public:
		int front,rare,capacity;
		int *ar;
		queue(int size)
		{
			 front=-1;
			rare=-1;
		 capacity=size;
			ar=new int[size];
		}
		void enqueue(int data)
		{
			if(front==-1 && rare==-1)
			{
				rare=0;
				front=0;
				ar[rare]=data;
			}
			else if(((rare+1)%capacity)==front)
			{
				cout<<"QUEUE IS FULL: \n";
			}
			else
			{
				rare=(rare+1)%capacity;
				ar[rare]=data;
			}
		}
		void dequeue()
		{
			if(front==-1 && rare==-1)
			{
				    cout<<"QUEUE IS EMPTY: \n";
			}
			else if(front==rare)
			{
			
				front=-1;
				rare=-1;
			}
			else
			{
				front=(front+1)%capacity;
			}
		}
		int peek()
		{
		if(front==-1 && rare==-1)
			{
				    cout<<"QUEUE IS EMPTY: ";
				    return 0;
				    
			}
			else
			{
				return ar[front];
				}	
		}
};
int main()
{  int q;
	cout<<"Enter the size of Queue";
	cin>>q;
	queue Q(q);
	Q.enqueue(6);
	Q.enqueue(8);
	Q.enqueue(3);
	Q.enqueue(7);
	Q.enqueue(1);
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
