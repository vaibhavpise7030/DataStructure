#include <iostream>
#include<string.h>
#include<conio.h>
using namespace std;

int s[100];
int tos = -1;
int size;
char postfix[100];
int z;

void push(char no)
{
	s[size];
	tos++;
	s[tos] = no;
}
char pop()
{
	char temp;
	temp = s[tos];
	tos--;
	return temp;
}
int atTop()
{
	return s[tos];
}
int priority(char op)
{
	switch(op)
	{
	case '+':case'-':
		return 1;break;

	case '*':case '/':case '%':
		return 2;break;

	case '^':
		return 3;break;

	case '(':
		return 0;break;
	}
}

int main()
{
	int c1,c2;
	char arr[100];
	cout<<"enter the expression \n";
	cin>>arr;
	arr[strlen(arr)];
	for(int i=0;i<strlen(arr);i++)
	{

		if((arr[i]>=65 && arr[i]<=90)||(arr[i]>=97 && arr[i]<=122))
		{
			postfix[z] = arr[i];
			z++;
		}
		else if(arr[i]=='+' || arr[i]=='-' || arr[i]=='*' || arr[i]=='/' || arr[i]=='%' || arr[i]=='^' || arr[i]=='(' || arr[i]==')' )
		{
			if(tos == -1)
			{
				push(arr[i]);
			}
			else
			{
				c1 = priority(atTop());
				c2 = priority(arr[i]);

				if(arr[i]=='(')
				{
					push(arr[i]);
				}
				else if(arr[i]==')')
				{
					while(tos!=-1)
					{
						char c = pop();
						if(c!='(')
						{
						postfix[z] = c;
						z++;
						}
					}
				}
				else if(c2<=c1)
				{
					while(tos!=-1)
					{
						postfix[z] = pop();
						z++;
					}
					push(arr[i]);
				}
				else
				{
					push(arr[i]);
				}
			}
		}
	}
	while(tos!=-1)
	{
		postfix[z] = pop();
		z++;
	}
	for(int i=0;i<strlen(postfix);i++)
	{
		cout<<postfix[i];
	}
	getch();
return 0;
}