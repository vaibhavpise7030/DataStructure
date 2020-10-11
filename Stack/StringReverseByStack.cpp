#include <iostream>
#include<string.h>
#include<conio.h>
using namespace std;

int s[100];
int tos=-1;

void push(char c)
{
	tos++;
	s[tos]=c;
}

char pop()
{
		char temp;
		temp=s[tos];
		tos--;
		return temp;
}

int main()
{
	char arr[20];
	cout<<"\n Enter String for Reverse\n";
	cin>>arr;

	
for(int i=0;i<strlen(arr);i++)
{
push(arr[i]);
}

for(int i=0;i<strlen(arr);i++)
{
cout<<pop();
}


getch();
return 0;


}