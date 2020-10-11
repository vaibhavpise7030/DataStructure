#include <iostream>
using namespace std;
int que[10],rear=-1,front=0,size=10,cnt;

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
	if(isfull())
	{
	   cout<<"circular que is really full";	
	}
	else
	{
	
   rear=(rear+1)%size;
    cnt++;
	que[rear]=e;
   }
}
bool isempty()
 {
 	if(cnt==0)
 	{
 		return 1;
	 }
	 else
	 {
	 	return 0;
	 }
	 
 }
int deque()
{
	if(isempty())
	{
		cout<<"circular que is empty";
	}
	else
	{
	
	cnt--;
	int temp=que[front];
	front=(front+1)%size;
	return temp;
     }
	
}
void printque()
{
	int c,i;
	i=front;
	c=0;
	while(c<cnt)
	{
		cout<<que[i];
		i=(i+1)%size;
		c=c+1;
	}
	
}
 
 
 int main()
 {
 	int choice,e;
   do
    {
        cout<<"\n1.enque: \n2.deque \n3.printQue";
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
		
            e=deque();
            cout<<"popped"<<e;
        }
        break;
       
        case 3:
          printque();
        break;
  }
    
    }
        while(choice!=0);   
	}
 

