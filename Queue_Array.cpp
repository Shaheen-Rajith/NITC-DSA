#include <iostream>
#define size 50
using namespace std;

class Queue
{
    private:
    int back,front;
    int arr[size];
    public:
    Queue()
    {
        back=-1;
        front=-1;
    }

    bool IsEmpty()
    {
        if(back==-1 && front==-1)
            return true;
        else
            return false;
    }

    void Enqueue(int num)
    {
        if((back+1)%size==front)
        {
            cout<<"Queue Overflow Error\n";
            return;
        }
        if(front==-1)
            front=0;
        back=(back+1)%size;
        arr[back]=num;
    }

    int Dequeue()
    {
        if(IsEmpty())
        {
            cout<<"Queue Underflow Error\n";
            return -1;
        }
        int val=arr[front];
        if(front==back)
        {
            front=-1;
            back=-1;
        }
        else
            front=(front+1)%size;
        return val;
    }

    int Size()
    {
        if(IsEmpty())
            return 0;
        else
            return back-front+1;
    }

    int Front()
    {
        if(IsEmpty())
        {
            cout<<"Cannot Display Empty Queue"<<endl;
            return -1;
        }
        return arr[front];
    }

    void Display()
    {
        if(IsEmpty())
        {
            cout<<"Cannot Display Empty Queue"<<endl;
            return;
        }
        for(int i=front;i<=back;i++)
        {
            cout<<arr[i] <<", ";
        }
    }


};

int main()
{
    int value,option; 
    Queue QU; 
    while(1) 
    { 
        cout<<"\n--------- Commands ---------"<<endl; 
        cout<<"1.Enqueue Value onto Queue"<<endl; 
        cout<<"2.Dequeue Value from Queue"<<endl; 
        cout<<"3.Show Value at front of Queue"<<endl; 
        cout<<"4.Show Size of Queue"<<endl; 
        cout<<"5.Display entire Queue"<<endl; 
        cout<<"6.Check if Queue is empty"<<endl; 
        cout<<"7.Quit "<<endl; 
        cout<<"Enter Option: "; 
        cin>>option; 
        switch(option)
        { 
            case 1: 
            cout<<"\nEnter value: "; 
            cin>>value; 
            QU.Enqueue(value);
            break; 

            case 2: 
            value=QU.Dequeue(); 
            cout<<"\nThe value Dequeued is: "; 
            cout<<value; 
            break; 

            case 3: 
            cout<<"\nThe Value at front of Queue is: "; 
            value=QU.Front(); 
            cout<<value; 
            break;

            case 4: 
            cout<<"\nThe Size of Queue is: "; 
            value=QU.Size(); 
            cout<<value; 
            break;

            case 5:
            cout<<"\nDisplaying Queue:: ";
            QU.Display(); 
            break; 

            case 6: 
            cout<<"\nQueue Status: "; 
            cout<<QU.IsEmpty();  
            break; 

            case 7: 
            return 0; 

            default: 
            cout<<"Invalid Option"<<endl;
        }

    }
    return 0;
}