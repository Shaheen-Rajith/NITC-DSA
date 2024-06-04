#include <iostream>
using namespace std;

class node
{
    public:
    int val;
    node* next;
};

class Stack
{
    private:
    node* top;
    public:
    Stack()
    {
        top=NULL;
    }

    bool IsEmpty()
    {
        if(top==NULL)
            return true;
        else
            return false;
    }

    node* make_node(int num)
    {
        node* temp= new node;
        temp->val=num;
        temp->next=NULL;
        return temp;
    }

    void Push(int num)
    {
        node* temp = make_node(num);
        if(temp==NULL)
        {
            cout<<"\n Stack Overflow Error"; 
            return ;
        }
        if(top==NULL)
            top=temp;
        else
        {
            temp->next=top;
            top=temp;
        }
    }

    int Pop()
    {
        if(IsEmpty())
        {
            cout<<"\n Stack Underflow Error"; 
            return -1;
        }  
        node* temp=top;
        top=top->next;
        int num=temp->val;
        delete(temp);
        return num;
    }

    int Size()
    {
        int count=0;
        node* index=top;
        while(index!=NULL)
        {
            index=index->next;
            count++;
        }
        return count;
    }

    int Top()
    {
        if(IsEmpty())
        {
            cout<<"\n Cannot display top for Empty Stack"; 
            return -1;
        }
        return top->val;
    }

    void Display()
    {
        if(IsEmpty())
        {
            cout<<"Cannot Display Empty Stack"<<endl;
            return;
        }
        node* index=top;
        while(index!=NULL)
        {
            cout<<index->val <<", ";
            index=index->next;
        }
    }

};

int main()
{
    int value,option; 
    Stack ST=Stack(); 
    while(1) 
    { 
        cout<<"\nMain Menu: "<<endl; 
        cout<<"1.Push value into Stack"<<endl; 
        cout<<"2.Pop value out of Stack"<<endl; 
        cout<<"3.Show Value at top of Stack"<<endl; 
        cout<<"4.Show Size of Stack"<<endl; 
        cout<<"5.Display entire Stack"<<endl; 
        cout<<"6.Check if Stack is empty"<<endl; 
        cout<<"7.Quit "<<endl; 
        cout<<"Enter Option: "; 
        cin>>option; 
        switch(option)
        { 
            case 1: 
            cout<<"Enter the value to be pushed: "; 
            cin>>value; 
            cout<<"Pushing value into Stack: "<<endl; 
            ST.Push(value); 
            cout<<endl; 
            break; 
            case 2: 
            cout<<"Poping value out of Stack: "<<endl; 
            value=ST.Pop(); 
            cout<<"The value popped is: "; 
            cout<<value<<endl; 
            break; 
            case 3: 
            cout<<"The Value at top of stack is: "; 
            value=ST.Top(); 
            cout<<value<<endl; 
            break;
            case 4: 
            cout<<"The Size of stack is: "; 
            value=ST.Size(); 
            cout<<value<<endl; 
            break; 
            case 5: cout<<"Displaying entire Stack: "<<endl; 
            ST.Display(); 
            cout<<endl;
            break; 
            case 6: 
            cout<<"Checking if Stack is empty: "<<endl; 
            cout<<ST.IsEmpty(); 
            cout<<endl; 
            break; 
            case 7: 
            return 0; 
            default: 
            cout<<"Invalid Option"<<endl;
        }

    }
    return 0;
}