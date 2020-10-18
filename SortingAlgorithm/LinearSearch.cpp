//Linear Search

#include<iostream>
using namespace std;

int Search(int arr[],int size,int key)
{
	for(int i=0;i<size;i++)
	{
		if(arr[i]==key)
		{
			return 1;
			break;
		}		
	}
	return 0;
}
int main()
{
	int key;
	int arr[]={1,2,3,4,5,10,20,30,50};
	
	int size=sizeof(arr)/sizeof(arr[0]);
	cout<<"Enter Element to be search"<<": ";
	cin>>key;
	int result=Search(arr,size,key);
	if(result)
	{
		cout<<"Found";
	}
	else
	{
		cout<<"Not found";
	}
	
}
