#include<iostream>
using namespace std;

void InsertionSort(int *a, int n)
{
    cout<<"\nInsertion Sorting:"<<endl;
    int i,j,temp;

    for(i=1; i<n; i++)
    {
        temp=a[i];
        j=i-1;

        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
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

    InsertionSort(arr,size);

    for(i=0; i<size; i++)
    {
        cout<<arr[i]<<"\t";
    }

    return 0;
}

