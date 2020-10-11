#include <iostream>
using namespace std;
int que[10],rear=-1,front=0,size=10,cnt;


bool isfull()
{
	if(size-1==rear)
        {
		return true;
		}
		else
		{
		
		return false;
	}
}
void enque(int e)
{
	if(isfull())
	{
		cout<<"que is full";
	}
	else
	{
	
	rear++;
	que[rear]=e;
}
}
void priority()
{
	for(int j=front;j<rear;j++)
	{
		for(j=front;j<rear;j++)
		{
			if(que[j]>que[j+1])
			{
				int temp=que[j];
				que[j]=que[j+1];
				que[j+1]=temp;
			}
		}
	}
}

bool isempty()
{
	if(front>rear)
	{
		return true;
	}
	else
	{
	return false;
   }
}
int deque()
{
	if(isempty())
	{
		cout<<"nthing to deque";
	}
	else
	{
		int temp=que[front];
		front++;
		return(temp);
	}
}

void printque()
{
	for(int i=front;i<=rear;i++)
	{
		cout<<que[i];
	}
}
int main()
{
		int choice,e;
   do
    {
        cout<<"\n1.enque: \n2.priority   \n.3deque \n.4 printque";
        cin>>choice;
        switch(choice)
        {
            case 1:
            
               {
				cout<<"Enter data to be pushed:";
                cin>>e;
                enque(e);
               }
        break;
        case 2:
        {
		
           priority();
        }
        break;
       
        case 3:
           e=deque();
            cout<<"popped"<<e;
        break;
        case 4:
        	printque();
  }
    
    }
        while(choice!=0);
}
