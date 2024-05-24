#include <iostream>
#include <cstdlib>
using namespace std;

void Insertion_Sort(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 & arr[j]>=key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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
    Insertion_Sort(arr,size);
    cout<<"\nThe Array after Sorting is:"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<", ";
    }
    return 0;
}