#include <iostream>
#include <cstdlib>
using namespace std;

void Merge(int arr[],int left, int right, int middle)
{
    int i=left,j=middle+1,k=left;
    int temp[right+1];
    while(i<=middle && j<=right)
    {
        if(arr[i]>arr[j])
        {
            temp[k]=arr[j];
            j++;
        }
        else
        {
            temp[k]=arr[i];
            i++;
        }
        k++;
    }

    if(i>middle)
    {
        temp[k]=arr[j];
        j++;
        k++;
    }

    if(j>right)
    {
        temp[k]=arr[i];
        i++;
        k++;
    }

    for(int i=left;i<=right;i++)
    {
        arr[i]=temp[i];
    }   
}

void Merge_Sort(int arr[],int left,int right)
{
    int mid = (left+right)/2;
    if(left<right)
    {
        Merge_Sort(arr,left,mid);
        Merge_Sort(arr,mid+1,right);
        Merge(arr,left,right,mid);
    }
}

int main()
{
    int size;
    cout<<"Enter Size of Array: ";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        arr[i]=rand()%size+1;
    }
    cout<<"\nThe Generated Array is:"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<", ";
    }
    Merge_Sort(arr,0,size-1);
    cout<<"\nThe Array after Sorting is:"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<", ";
    }
    return 0;
}