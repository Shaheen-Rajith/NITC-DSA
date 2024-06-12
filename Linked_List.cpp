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

    void Insert_Tail(int num)
    {
        node* temp, *index=head;
        temp=make_node(num);
        while(index->next!=NULL)
            index=index->next;
        index->next=temp;
    }

    int Size()
    {
        node* index = head;
        int count=0;
        while(index!=NULL)
        {
            index = index->next;
            count++;
        }
        return count;
    }

    void Insert_Pos(int num, int pos)
    {
        if(pos==0)
        {
            Insert_Head(num);
            return;
        }
        if(pos>=Size())
        {
            cout<<"\nInvalid Index";
            return;
        }
        else
        {
            node* temp = make_node(num);
            node *index = head, *store;
            for(int i=0;i<pos;i++)
            {
                store=index;
                index=index->next;
            }
            store->next=temp;
            temp->next=index;
        }
        return;

    }

    void Delete_Pos(int pos)
    {
        if(pos==0)
        {
            node* temp = head;
            head=head->next;
            delete(temp);
            return;
        }

        if(pos>=Size())
        {
            cout<<"\nOut of Bound Index";
            return;
        }
        else
        {
            node *index = head, *store;
            for(int i=0;i<pos;i++)
            {
                store=index;
                index=index->next;
            }
            store->next=index->next;
            delete(index);
        }
        return;
    }

    void Sort()
    {
        node* index=head;
        int swap=0, temp;
        while(1)
        {
            swap=0;
            for(index=head;index->next!=NULL;index=index->next)
            {
                if(index->val > index->next->val)
                {
                    temp=index->val; 
                    index->val=index->next->val;
                    index->next->val=temp; 
                    swap=1;
                }
            }
            if(!swap)
                break;
        }
        return;
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
    int val,pos,op;
    Linked_List LL;
    while(1)
    {
        cout<<"\n\n--------Commands--------\n";
        cout<<"Press 1 to Insert at Head\n";
        cout<<"Press 2 to Insert at Tail\n";
        cout<<"Press 3 to Insert at Other Position\n";
        cout<<"Press 4 to Check size of List\n";
        cout<<"Press 5 to Delete at Any Position\n";
        cout<<"Press 6 to Sort the List\n";
        cout<<"Press 7 to Display the List\n";
        cout<<"Press 8 to Exit\n";
        cout<<"Enter Option: ";
        cin>> op;
        switch(op)
        {
            case 1:
            cout<<"\nEnter Value: ";
            cin>>val;
            LL.Insert_Head(val);
            break;

            case 2:
            cout<<"\nEnter Value: ";
            cin>>val;
            LL.Insert_Tail(val);
            break;

            case 3:
            cout<<"\nEnter Value: ";
            cin>>val;
            cout<<"\nEnter Position: ";
            cin>>pos;
            LL.Insert_Pos(val,pos);
            break;

            case 4:
            cout<<"\nSize of List is: "<<LL.Size();
            break;

            case 5:
            cout<<"\nEnter Position: ";
            cin>>pos;
            LL.Delete_Pos(pos);
            break;

            case 6:
            cout<<"\nSorting the List";
            LL.Sort();
            break;

            case 7:
            cout<<"\nDisplaying the List: ";
            LL.Display();
            break;

            case 8:
            return 0;

            default:
            cout<<"\nInvalid Number Pressed";
            break;  
        }
    }
    return 0;
}