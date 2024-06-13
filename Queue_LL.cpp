#include <iostream>
using namespace std;

class node
{
    public:
    int val;
    node* next;
};


class Queue
{
    private:
    node *back, *front;
    public:
    Queue()
    {
        back=NULL;
        front=NULL;
    }

    node* make_node(int num)
    {
        node* temp= new node;
        temp->val=num;
        temp->next=NULL;
        return temp;
    }

    bool IsEmpty()
    {
        if(back==NULL && front==NULL)
            return true;
        else
            return false;
    }

    void Enqueue(int num)
    {
        node* temp = make_node(num);
        if(temp==NULL)
        {
            cout<<"Queue Overflow Error\n";
            return;
        }
        if(IsEmpty())
        {
            front=temp;
            back=temp;
            return;
        }
        else
        {
            back->next=temp;
            back=temp;
            return;
        }
    }

    int Dequeue()
    {
        if(IsEmpty())
        {
            cout<<"Queue Underflow Error\n";
            return -1;
        }
        node* temp=front; 
        if(Size()==1) 
        { 
            int val=temp->val; 
            front=NULL; 
            back=NULL; 
            delete(temp); 
            return val; 
        }
        else
        {
            front=front->next; 
            int val=temp->val; 
            delete(temp); 
            return val;
        }
    }

    int Size()
    {
        node* temp=front; 
        int count=0; 
        while(temp!=NULL) 
        { 
            count++; 
            temp=temp->next; 
        } 
        return count; 
    }

    int Front()
    {
        if(IsEmpty())
        {
            cout<<"Cannot Display Empty Queue"<<endl;
            return -1;
        }
        return front->val;
    }

    void Display()
    {
        if(IsEmpty())
        {
            cout<<"Cannot Display Empty Queue"<<endl;
            return;
        }
        node* temp=front; 
        while(temp!=NULL) 
        { 
            cout<<temp->val<<", "; 
            temp=temp->next; 
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