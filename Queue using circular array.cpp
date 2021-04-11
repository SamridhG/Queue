#include<iostream>
using namespace std;
class Queue{
	private:
		int front,rare;
		int capacity;
		int *array;
	public:
		Queue(int capacity)
		{
			this->capacity=capacity;
			front=rare=-1;
		
			array=new int[this->capacity];
		}
		void EnQueue(int data)
		{
			if(rare==-1 && front==-1)
			{
				front=rare=0;
				
				array[rare]=data;
			}
			else if((rare+1)%capacity==front)
			{
				cout<<"OVERFLOW\n";
			}
			else
			{
				rare=(rare+1)%capacity;
				array[rare]=data;
			}
		}
		void Dequeue()
		{
			if(front==-1 && rare==-1)
			{
				cout<<"EMPTY QUEUE\n";
			}
			else if(front==rare)
			{
				rare=-1;
				front=-1;
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
			   cout<<"EMPTY QUEUE>>";
				return 0;
			}
			else
			{
				return array[front];
			}
		}
		void Display()
		{
			if(front==-1 && rare==-1)
			{
				cout<<"EMPTY QUEUE>>";
				
			}
			else
			{
				int i=front;
				while(i!=rare)
				{
					cout<<array[i]<<" ";
					i=(i+1)%capacity;
				}
				cout<<array[i]<<" "<<endl;;
			}
		}
		
};
int main()
{
	int size,data;
	cout<<"ENTER SIZE OF QUEUE>> ";
	cin>>size;
	Queue Q(size);
	char G;
	cout<<"1> FOR ENTER DATA PRESS 'E'>>\n2> FOR DELETING DATA PRESS 'D'>>\n3> FOR DISPLAY THE PEEK PRESS 'P'>>\n4> FOR DISPLAY ALL ELEMENT PRESS 'W'>>\n";
	A:
		cout<<"CHOOSE ONE:>>";
		cin>>G;
	if(G=='E')
	{
		cout<<"ENTER YOUR DATA>>";
		cin>>data;
		Q.EnQueue(data);
	}
	else if(G=='D')
	{
		Q.Dequeue();
	}
	else if(G=='P')
	{
		cout<<Q.peek()<<endl;
	}
	else if(G=='W')
	{
		Q.Display();
	}
	goto A;
	return 0;
}
