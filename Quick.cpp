#include <iostream>
#include <cstdlib>
using namespace std;

int Partition(int arr[],int left, int right)
{
    int pivot=arr[left];
    int count=0;
    int i,j;
    for(i=left+1;i<=right;i++)
    {
        if(arr[i]<=pivot)
            count++;
    }
    int pivotindex=left+count;
    int temp=arr[pivotindex];
    arr[pivotindex]=arr[left];
    arr[left]=temp;
    i=left,j=right;
    while(i<pivotindex && j>pivotindex)
    {
        while(arr[i]<=pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if (i<pivotindex && j>pivotindex)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
    return pivotindex;
}

void Quick_Sort(int arr[],int left,int right)
{
    if(left<right)
    {
        int p=Partition(arr,left,right);
        Quick_Sort(arr,left,p-1);
        Quick_Sort(arr,p+1,right);
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
    Quick_Sort(arr,0,size-1);
    cout<<"\nThe Array after Sorting is:"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<", ";
    }
    return 0;
}