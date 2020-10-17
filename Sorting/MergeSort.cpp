#include<iostream>
using namespace std;

int maxsize;

void MergeArray(int *a, int low, int high, int mid)
{
    int i=low;
    int j=mid+1;
    int k=0;
    int temp[maxsize];

    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
        }
    }

    while(i<=mid)
    {
        temp[k++]=a[i++];
    }

    while(j<=high)
    {
        temp[k++]=a[j++];
    }

    k=0;
    for(i=low;i<=high; i++)
    {
        a[i]=temp[k++];
    }
}

void MergeSorting(int *a, int l, int h)
{
    int mid;

    if(l<h)
    {
      mid=(l+h)/2;

      MergeSorting(a,l,mid);
      MergeSorting(a,mid+1,h);

      MergeArray(a,l,h,mid);
    }

}


int main()
{
    int size,i;
    cout<<"Enter Size of Array"<<endl;
    cin>>size;
    maxsize=size;

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

    MergeSorting(arr,0,size-1);

    for(i=0; i<size; i++)
    {
        cout<<arr[i]<<"\t";
    }

    return 0;
}

