#include<iostream>
#include<conio.h>
using namespace std;

int s[100];
int tos=-1;
int size;

int isEmpty()
{
if(tos==-1)
	return 1;
else
	return 0;
}

int isFull()
{
	if(tos==size-1)
		return 1;
	else
		return 0;
}

int pop()
{
if(isEmpty())
	cout<<"Stack is Empty UnderFlow";
else
{
	int temp;
	temp=s[tos];
	tos--;
	return temp;
}
}

void push(int n)
{
	if(size==0)
	{
	  cout<<"Enter the Stack size you want\n";
	  cin>>size;
	}
	else 
	{
		if(isFull())
		{
			cout<<"Stack is full OverFlow";
		}
		else
		{
			s[size];
			tos++;
			s[tos]=n;
		}
	}
}

void printStack()
{
	if(isEmpty())
		cout<<"stack is Empty";
	else
	{
		for(int i=0;i<=size-1;i++)
		{
		cout<<s[i]<<"\t";
		}
	}
}

int atTop()
{
	if(isEmpty())
		cout<<"Stack is Empty";
	else
	return s[tos];
}

int main()
{
int choice;
do{
	cout<<"Select which operation you want to perform\n";
	cout<<"1 \t push\n";
	cout<<"2 \t pop\n";
	cout<<"3 \t atTop\n";
	cout<<"4 \t printStack\n";
	cout<<"0 \t for exit\n";
	cin>>choice;

	switch(choice)
	{
	case 1:int num;
			cout<<"\nEnter element to add";
			cin>>num;
			push(num);
			break;
	case 2:cout<<"\n"<<pop();
			break;
	case 3:cout<<"\n"<<atTop();
			break;
	case 4:printStack();
			break;

	default:"\n Wrong choice entered"; 
	}

} while(choice);
getch();
return 0;
}