#include<iostream>
using namespace std;

void SelectionSort(int *a, int n)
{
    cout<<"\nSelection Sorting:"<<endl;
    int i,j,key,temp;

    for(i=0; i<n-1; i++)
    {
        key=i;

        for(j=i+1; j<=n-1; j++)
        {
            if(a[key]>a[j])
            {
                key=j;
            }
        }

        temp=a[i];
        a[i]=a[key];
        a[key]=temp;
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

    SelectionSort(arr,size);

    for(i=0; i<size; i++)
    {
        cout<<arr[i]<<"\t";
    }

    return 0;
}


