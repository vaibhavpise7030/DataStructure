//Binary Search

#include<iostream>
using namespace std;

int Search(int arr[],int l,int r,int key)
{
	while(l<=r)
	{
		int mid=(l+r)/2;
		
		if(arr[mid]==key)
		{
			return mid;
		}
		if(arr[mid]<key)  
		{	 
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}		
	}	
}

int main()
{
	int key;
	int arr[]={1,2,3,4,5,10,20,30,50};
	
	int size=sizeof(arr)/sizeof(arr[0]);
	cout<<"Enter Element to be search"<<": ";
	cin>>key;
	int result=Search(arr,0,,size-1,key);
	if(result)
	{
		cout<<"Found";
	}
	else
	{
		cout<<"Not found";
	}
}
