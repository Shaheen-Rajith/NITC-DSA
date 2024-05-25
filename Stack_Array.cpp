#include <iostream>
using namespace std;

class Stack
{
    private:
    int top;
    int arr[100];
    public:
    Stack()
    {
        top=-1;
    }

    bool IsEmpty()
    {
        if(top==-1)
            return true;
        else
            return false;
    }

    void Push(int num)
    {
        if(top==99)
        {
            cout<<"Stack Overflow Error\n";
            return;
        }
        top++;
        arr[top]=num;
    }

    int Pop()
    {
        if(IsEmpty())
        {
            cout<<"Stack Underflow Error\n";
            return -1;
        }
        int val=arr[top];
        top--;
        return val;
    }

    int Size()
    {
        return top+1;
    }

    int Top()
    {
        if(IsEmpty())
        {
            cout<<"Cannot Display Empty Stack"<<endl;
            return -1;
        }
        return arr[top];
    }

    void Display()
    {
        if(top==-1)
        {
            cout<<"Cannot Display Empty Stack"<<endl;
            return;
        }
        for(int i=top;i>=0;i--)
        {
            cout<<arr[i] <<", ";
        }
    }


};

int main()
{
    int value,option; 
    Stack ST; 
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