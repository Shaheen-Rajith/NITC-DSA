#include <iostream>
#include <cstdlib>
using namespace std;

void Bubble_Sort(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
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
    Bubble_Sort(arr,size);
    cout<<"\nThe Array after Sorting is:"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<", ";
    }
    return 0;
}