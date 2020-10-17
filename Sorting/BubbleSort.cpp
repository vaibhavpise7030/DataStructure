#include<iostream>
using namespace std;

void BubbleSort(int *a, int n)
{
    cout<<"\nBubble Sorting:"<<endl;
    int i,j,temp;

    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i;j++)
        {
            if(a[j+1]<a[j])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }

    }
}

int main()
{
    int size,i;
    cout<<"Enter Size of Array"<<endl;
    cin>>size;

    int arr[size];

    cout<<"Enter Array Elements"<<endl;
    for(i=0; i<size; i++)
    {
        cin>>arr[i];
    }

    cout<<"Array Before Sorting"<<endl;
    for(i=0; i<size; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;

    BubbleSort(arr, size);

    for(i=0; i<size; i++)
    {
        cout<<arr[i]<<"\t";
    }

    return 0;
}

