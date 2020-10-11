#include<iostream>
#include<conio.h>
using namespace std;

int s[50];
int tos=-1;


void push(int n)
{
	tos++;
	s[tos]=n;
}

int pop()
{
	int temp;
	temp=s[tos];
	tos--;
	return temp;
}

int main()
{
	int num,n;
	cout<<"Enter the number\n";
	cin>>num;
	while(num)
	{
		n=num%2;
		push(n);
		num=num/2;
	}
	for(int i=tos;i>-1;i--)
	{
		cout<<"\t"<<pop();
	}
	getch();
	return 0;

}