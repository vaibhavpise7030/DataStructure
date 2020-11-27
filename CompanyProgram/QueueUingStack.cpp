#include<iostream>
using namespace std;

int s1[5],s2[5];
int top1=-1,top2=-1,size=5;

void push1(int val)
{
   s1[++top1]=val;
}

void push2(int val)
{
   s2[++top2]=val;
}

void pop1()
{
    --top1;
}

void pop2()
{
    --top2;
}

int isEmpty1()
{
    if(top1==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty2()
{
    if(top2==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Attop1()
{
    return s1[top1];
}

int Attop2()
{
    return s2[top2];
}

void EnQueue(int val)
{
   if(top1+1==size)
   {
      cout<<"Queue is Full"<<endl;
   }

   else
   {
    while(isEmpty1()!=1)
   {
       push2(Attop1());
       pop1();
   }

   push1(val);

   while(isEmpty2()!=1)
   {
       push1(Attop2());
       pop2();
   }

   }

}

void DeQueue()
{
    if(isEmpty1())
    {
        cout<<"Queue is Empty"<<endl;
    }
    else
    {
    	int res= Attop1();
    	pop1();
    	cout<<"Deleted Element: "<<res<<endl;	
	}
    
}

int main()
{
    EnQueue(10);
    EnQueue(20);
    EnQueue(30);
    EnQueue(40);
    EnQueue(50);
    DeQueue();
    EnQueue(50);
    DeQueue();


    DeQueue();
    DeQueue();
    DeQueue();
    return 0;
}

