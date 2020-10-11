#include<iostream>
using namespace std;
int Q[100],size,front,rear;

void creatQueue(int a)
{
	size=a;
	front=0;
	rear=-1;
}

bool isFull()
{
	if(rear==size-1)
	return true;
	else
	return false;
}

void Enqueue(int e)
{
	//rear++;
	Q[++rear]=e;
}


bool isEmpty()
{
	if(front>rear)
	return true;
	else
	return false;
}

int Dequeue()
{
	int temp;
	temp=Q[front];
	front++;
	return temp;
}

void printQueue()
{
	int i;
	for(i=front;i<=rear;i++)
	cout<<Q[i]<<"\t";
}

void priority()
{
	for(int j=front;j<rear;j++)
	{
		for(j=front;j<rear;j++)
		{
			if(Q[j]>Q[j+1])
			{
				int temp=Q[j];
				Q[j]=Q[j+1];
				Q[j+1]=temp;
			}
		}
	}
}
int atTop()
{
	return Q[front];
}
int main()
{
	cout<<"Enter size of Queue "<<endl;
	int a, choice;
	cin>>a;
	creatQueue(a);
	
	cout<<" \n1.Enqueue \n2.Dequeue \n3.Top \n4.print \n5.Priority \n0.Exit"<<endl;
	do
	{
		cout<< "Enter choice:"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				if(isFull())
				{
					cout<<"Stack is full"<<endl;
				}
					else
				{
					int k;
					cout<<"Enter element to Enqueue"<<endl;
					cin>>k;
					Enqueue(k);
				}
				break;
				
				case 2:
					if(isEmpty())
					{
						cout<<"Stack in empty"<<endl;
					}
					
					else
					{
						int b=Dequeue();
						cout<<"Deleted Element: "<<b<<endl;
					}
					break;
					
				case 3:
					if(isEmpty())
					{
						cout<<"Stack in empty"<<endl;
					}
					else
					{
						cout<<atTop()<<endl;
					}
					break;
				case 4:
					if(isEmpty())
					{
						cout<<"Stack in empty"<<endl;
					}
					else
					{
						printQueue();
					}
					break;
					
				case 5:
					priority();
					break;
				case 0:
					cout<<"Exit"<<endl;
					break;
					
					default:
						cout<<"Enter Valid Choice"<<endl;
	}
	}while(choice!=0);

}




