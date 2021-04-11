#include<iostream>
using namespace std;
class queue{
	private:
		int front,capacity,rare;
		int *a;
		public:
			queue(int capacity)
			{
				this->capacity=capacity;
				a=new int[this->capacity];
				front=-1;
				rare=-1;
			}
			void enque(int data)
			{
				if(front==-1 && rare==-1)
				 {
					front=0;
					rare=0;
					a[rare]=data;
				 }
				 else if((rare+1)%capacity==front)
				 {
					cout<<"Queue is full"<<endl;
				 }
				   else
				   {
					rare=(rare+1)%capacity;
					a[rare]=data;
				   }
			}
			void deque()
			{
				if(front==-1 && rare==-1)
				{
					cout<<"Queue is Empty"<<endl;
				}
				else if(front==rare)
				{
					cout<<a[front]<<endl;
					front=-1;
					rare=-1;
				}
				else
				{
					cout<<a[front]<<endl;
					front=(front+1)%capacity;
				}
			}
};
int main()
{
	int size;
	cout<<"Enter The Queue Size>> ";
	cin>>size;
	queue S(size);
	S.enque(55);
	S.enque(44);
	S.enque(33);
	S.enque(5);
	S.enque(44);
	S.deque();
	S.deque();
	S.deque();
	S.deque();
	S.deque();
	
}
