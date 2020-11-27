#include<iostream>
using namespace std;

int Que[100],front1,front2,rear1,rear2,size;
void init(int a)
{
	front1=0;
	front2=a-1;
	rear1=-1;
	rear2=a;
	size=a;
	Que[size];
}

bool isEmpty1()
{
	if(front1>rear1)
	{
		rear1=-1;
		return true;
	}
	
	else
	return false;
}
bool isEmpty2()
{
	if(front2<rear2)
	{
		rear2=size;
		return true;		
	}
	
	else
	return false;
}
bool isFull()
{
	if(rear1+1==rear2)
	return true;
	
	else
	return false;
}

void push1(int e)
{
	rear1++;
	Que[rear1]=e;
}
void push2(int e)
{
	rear2--;
	Que[rear2]=e;
}

int pop1()
{
	int temp;
	temp=Que[front1];
	front1++;
	return temp;
}


int pop2()
{
	int temp;
	temp=Que[front2];
	front2--;
	return temp;
}
 void print1()
 {
 	for(int i=front1;i<=rear1;i++)
 	{
 		cout<<Que[i]<<"\t";	
	}
	cout<<endl;
 }
 void print2()
 {
 	for(int i=front2;i>=rear2;i--)
 	{
 		cout<<Que[i]<<"\t";	
	}
 }

	int main()
{
	int size,ch;
	cout<<"Enter size of the array "<<endl;
	cin>>size;
	init(size);
	cout<<"\n1: Enqueue 1 \n2:Enqueue 2 \n3: Dequeue 1 \n4: Dequeue 2  \n5: Print Queue1 \n6: Print Queue2" <<endl;
	do{
		cout<<"Enter choice"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
			if(isFull())
			{
				cout<<"Array is full"<<endl;
			}
			else
			{
				int k;
				cout<<"Enter element to add : ";
				cin>>k;
				push1(k);
			}
			break;
		case 2:
			if(isFull())
			{
				cout<<"Array is full"<<endl;
			}
			else
			{
				int m;
				cout<<"Enter element to add : ";
				cin>>m;
				push2(m);
			}
			break;
		case 3:
			if(isEmpty1())
			{
				cout<<"Que1 is empty"<<endl;
			}
			else
			{
				int a=pop1();
				cout<<"poped:"<<a<<endl;
			}
			break;
		case 4:
			if(isEmpty2())
			{
				cout<<"Que2 is empty"<<endl;
			}
			else
			{
				int n=pop2();
				cout<<"poped:"<<n<<endl;
			}
			break;
		case 5:
			if(isEmpty1())
			{
				cout<<"Que1 is empty"<<endl;
			}
			else
			{
				print1();
			}
			break;
		case 6:
			if(isEmpty1())
			{
				cout<<"Que2 is empty"<<endl;
			}
			else
			{
				print2();
			}	
			break;
			
		default:
			cout<<"Enter valid choice"<<endl;
		}	
	}while(ch!=0);

}


