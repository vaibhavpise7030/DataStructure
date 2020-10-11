#include<iostream>
using namespace std;
int Q[100],size,front,rear,cnt;

void createQue(int a)
{
	size=a;
	front=0;
	rear=-1;
	cnt=0;
}

bool isfull()
{
	if(cnt==size)
	{
		return true;
	}
	else
	return false;
}
void enque(int e)
{
	rear=(rear+1)%size;
	cnt++;
	Q[rear]=e;
}
 
int deque()
{
	int temp;
	cnt--;
	temp=Q[front];
	front=(front+1)%size;
	return temp;
}
bool isempty()
{
	if(cnt==0)
	{
		return true;
	}
	else
	return false;
	
}
void printque()
{
/*	for(int i=front;i<=rear;i++)
	{
		cout<<Q[i]<<"\t";
	}
	cout<<"\n"<<endl;*/
	
	
	int c,i;
	i=front;
	c=0;
	while(c<cnt)
	{
		cout<<Q[i]<<" ";
		i=(i+1)%size;
		c=c+1;
	}
	
}
int main()
{
	cout<<"Enter size of Queue "<<endl;
	int a, choice;
	cin>>a;
	createQue(a);
	
	cout<<" \n1.Enqueue \n2.Dequeue \n3.print \n0.Exit"<<endl;
	do
	{
		cout<< "Enter choice:"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				if(isfull())
				{
					cout<<"Stack is full"<<endl;
				}
					else
				{
					int k;
					cout<<"Enter element to Enqueue"<<endl;
					cin>>k;
					enque(k);
				}
				break;
				
				case 2:
					if(isempty())
					{
						cout<<"Stack in empty"<<endl;
					}
					
					else
					{
						int b=deque();
						cout<<"Deleted Element: "<<b<<endl;
					}
					break;
				
				case 3:
					if(isempty())
					{
						cout<<"Stack in empty"<<endl;
					}
					else
					{
						printque();
					}
					break;
				case 0:
					cout<<"Exit"<<endl;
					break;
					
					default:
						cout<<"Enter Valid Choice"<<endl;
	}
	}while(choice!=0);

}
