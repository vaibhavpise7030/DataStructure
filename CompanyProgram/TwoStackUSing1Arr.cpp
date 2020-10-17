#include <iostream>
using namespace std;

class Stack
{  public: 
    int *arr;
    int size,tos1,tos2;
    Stack(int n)
    {
        size=n;
        arr=new int[n];
        tos1=-1;
        tos2=size;
    }
    bool isFull()
    {
        if(tos1>=tos2-1)
            return true;
        else
    		return false;
    }
        void push1()
    	{
        	if(isFull())
        {	
            cout<<"Stack is full";
        }
			else
        	{
            	int temp;
            	cout<<"Enter element";
            	cin>>temp;
            	tos1++;
            	arr[tos1]=temp;
        }
    }
     void push2()
    {
        if(isFull())
        {
            cout<<"Stack is full";
        }else
        {
            int temp;
            cout<<"Enter element";
            cin>>temp;
            tos2--;
            arr[tos2]=temp;
    		
        }
    }
        bool isEmpty()
    {
    	if(tos1==-1 && tos2==size)
    		return true;
    	else
    		return false;
    }
         void pop1()
    {
    	if(isEmpty())
    	{
    		cout<<"Stack is empty ";
    	}else
    	{
    		cout<<arr[tos1]<<" ";
    		tos1--;
    	}
    }
    void pop2()
    {
    	if(isEmpty())
    	{
    		cout<<"Stack is empty ";
    	}else
    	{
    		cout<<arr[tos2]<<" ";
    		tos2++;
    	}
    }
        
    void print1()
    {
    	for(int i=tos1;i>=0;i--)
    	{
    		cout<<arr[i]<<" ";
    	}
    }
     void print2()
    {
    	for(int i=tos2;i<size;i++)
    	{
    		cout<<arr[i]<<" ";
    	}
    }
};


int main()
{
    int size,choice;
    Stack s(5);
    
    do{
        cout<<"\n 1.Push in 1st stack : \n 2).Push in 2nd stack : \n3.Pop 1:  \n4.Pop 2:\n 5.Print 1 \n 6.Print 2: \n 0.Exit \n:";
        cin>>choice;
        
        switch(choice){
        case 1:
                s.push1();
                break;
        case 2:
                s.push2();
                break;
		case 3:
			s.	pop1();
				break;
		case 4:
			s.pop2();
				break;
		case 5:
				s.print1();
				break;
		case 6:
				s.print2();
				break;
		case 0:
				exit(0);
		}
    }while(choice!=0);

    return 0;
}

