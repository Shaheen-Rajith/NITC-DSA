#include <iostream>
using namespace std;

class node
{
    public:
    int val;
    node* next;
};

class Linked_List
{
    private:
    node* head;
    public:
    Linked_List()
    {
        head=NULL;
    }

    node* make_node(int num)
    {
        node* temp= new node;
        temp->val = num;
        temp->next = NULL;
        return temp;
    }

    void Insert_Head(int num)
    {
        node* temp = make_node(num);
        if(head==NULL)
            head=temp;
        else
        {
            temp->next=head;
            head=temp;
        }
    }

    void Display()
    {
        node* temp = head;
        while(temp!=NULL)
        {
            cout<<temp->val <<", ";
            temp=temp->next;
        }
    }
};

int main()
{
    int val,num;
    Linked_List LL;
    while(1)
    {
    cout<<"\n1 to insert at head, 2 to display linked list, 3 to quit"<<endl;
    cin>>val;
    if(val==1)
    {
        cout<<"Enter value to be Inserted: ";
        cin>>num;
        LL.Insert_Head(num);
    }
    if(val==2)
        LL.Display();
    if(val==3)
        break;


    }
}