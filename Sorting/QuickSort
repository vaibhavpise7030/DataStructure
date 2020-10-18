#include<iostream>
using namespace std;

int QuickSortPartion(int *a, int low, int high)
{
    int pivot= a[(low+high)/2];

    while(low<=high)
    {
        while(a[low]<pivot)
        {
            low++;
        }

        while(a[high]>pivot)
        {
            high--;
        }

        if(low<=high)
        {
            int temp=a[low];
            a[low]=a[high];
            a[high]=temp;

            low++;
            high--;
        }
    }

    return low;
}

void  QuickSort(int *a, int low, int high)
{
    int p= QuickSortPartion(a,low,high);

    if(low<p-1)
    {
        QuickSort(a,low,p-1);
    }

    if(high>p)
    {
        QuickSort(a,p,high);
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

    QuickSort(arr,0,size-1);

    for(i=0; i<size; i++)
    {
        cout<<arr[i]<<"\t";
    }

    return 0;
}
