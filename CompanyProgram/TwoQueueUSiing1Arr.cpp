#include<iostream>

using namespace std;

int s[100],maxSize,front1,front2,rear1,rear2;

void queueInit(int size)
{
	maxSize=size;
	front1=0;
	rear1=-1;
	front2=size-1;
	rear2=size;
}
void enqueu1()
{
	if(rear1<rear2-1)
	{		
		int e;
		cout<<"\n Enter an element ";
		cin>>e;
		rear1++;
		s[rear1]=e;
	}
	else
	{
	   cout<<"Queue is full"; 
	}
}
void enqueu2()
{
	if(rear1<rear2-1)
	{		
		int e;
		cout<<"\n Enter an element ";
		cin>>e;
		rear2--;
		s[rear2]=e;
	}
	else
	{
	   cout<<"Queue is full"; 
	}
}
void dequeue1()
{
	if(front1<=rear1)
	{
		cout<<s[front1];
		front1++;
	}else
	{
	    cout<<"Queue is empty";
	}
}
void dequeue2()
{
	if(front2>=rear2)
	{
		cout<<s[front2];
		front2--;
	}else
	{
	    cout<<"Queue is empty";
	}
}
 void print()
 {
		for(int i=front1;i<=front2;i++)
		 {
			 cout<<" "<<s[i];
		 }
 }


int main()
{
	int size,ch;
	std::cout<<"Enter size of the array ";
	cin>>size;
	queueInit(size);

	do{
		cout<<"\n:1 to Enqueue 1 \n:2Enqueue 2 \n:3 Dequeue 1 \n:4 Dequeue 2  \n:5 Print Queue \n:0 exit";
		cin>>ch;
		switch(ch)
		{
		case 1:
			enqueu1();
			break;
		case 2:
			enqueu2();
			break;
		case 3:
			dequeue1();
			break;
		case 4:
			dequeue2();
			break;
		case 5:
			print();
			break;
		case 6:
		    exit(0);
		}	
	}while(ch!=0);

}

