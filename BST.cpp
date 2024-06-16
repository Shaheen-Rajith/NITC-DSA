#include <iostream>
using namespace std;

class node
{
    public:
    int val;
    node* left;
    node* right;
    node* parent;

};

class BST
{
    private:
    node* root;
    
    public:
    BST()
    {
        root=NULL;
    }

    node* Point_Root()
    {
        return root;
    }

    node* make_node(int num)
    {
        node* temp= new node;
        temp->val = num;
        temp->parent = NULL;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    void Insert(int num)
    {
        node* temp = make_node(num);
        node* pos, *index=root;
        if(root==NULL)
        {
            root=temp;
            return;
        }
        while(index!=NULL)
        {
            pos=index;
            if(num<index->val)
                index=index->left;
            else
                index=index->right;
        }
        temp->parent=pos;
        if(num<pos->val)
            pos->left=temp;
        else
            pos->right=temp;
    }

    void Display(node* nod)
    {   
        if(nod!=NULL)
        {
            Display(nod->left);
            cout<<nod->val <<", ";
            Display(nod->right);
        }
    }

    void Delete(node* temp)
    {
        if(temp==NULL)
            return;
        if(temp->left == NULL && temp->right == NULL)
        {
            delete(temp);
            return;
        }

        else if(temp->left == NULL && temp->right != NULL)
        {
            temp->right->parent = temp->parent;
            if(temp==temp->parent->left)
                temp->parent->left=temp->right;
            else
                temp->parent->right=temp->right;
            delete(temp);
            return;
        }

        else if(temp->left != NULL && temp->right == NULL)
        {
            temp->left->parent = temp->parent;
            if(temp==temp->parent->left)
                temp->parent->left=temp->left;
            else
                temp->parent->right=temp->right;
            delete(temp);
            return;
        }

        else
        {
            node* Succ = Search(Successor(temp->val));
            temp->val = Succ->val;
            Delete(Succ);
        }
        
    }


    node* Search(int num)
    {
        node* index=root;
        while(index!=NULL)
        {
            if(index->val==num)
            {
                return index;
            }
            if(index->val>=num)
                index=index->left;
            else
                index=index->right;
        }
        cout<<"\nValue NOT Found in BST";
        return NULL;
    }

    int Min()
    {
        node* index=root;
        while(index->left!=NULL)
            index=index->left;
        return index->val;
    }

    int Max()
    {
        node* index=root;
        while(index->right!=NULL)
            index=index->right;
        return index->val;
    }

    int Successor(int num)
    {
        node* temp = Search(num);
        if(temp==NULL)
            return -1;
        if(temp->right != NULL)
        {
            node* index=temp->right;
            while(index->left!=NULL)
                index=index->left;
            return index->val;
        }
        else
        {
            while(temp==temp->parent->right)
                temp=temp->parent;
            if(temp->parent==NULL)
            {
                cout<<"\nNo Successor found in BST";
                return -1;
            }
            else
                return temp->parent->val;
        }
    }

    int Predecessor(int num)
    {
        node* temp = Search(num);
        if(temp==NULL)
            return -1;
        if(temp->left != NULL)
        {
            node* index=temp->left;
            while(index->right!=NULL)
                index=index->right;
            return index->val;
        }
        else
        {
            while(temp==temp->parent->left)
                temp=temp->parent;
            if(temp->parent==NULL)
            {
                cout<<"\nNo Predecessor found in BST";
                return -1;
            }
            else
                return temp->parent->val;
        }
    }

};


int main()
{
    int val,pos,op;
    BST Tree;
    while(1)
    {
        cout<<"\n\n--------Commands--------\n";
        cout<<"Press 1 to Insert a Node\n";
        cout<<"Press 2 to Delete a Node\n";
        cout<<"Press 3 to Search a Node\n";
        cout<<"Press 4 to Find Max Node\n";
        cout<<"Press 5 to Find Min Node\n";
        cout<<"Press 6 to Find Successor of a Node\n";
        cout<<"Press 7 to Find Predecessor of a Node\n";
        cout<<"Press 8 to Display the BST\n";
        cout<<"Press 9 to Exit\n";
        cout<<"Enter Option: ";
        cin>> op;
        switch(op)
        {
            case 1:
            cout<<"\nEnter Value: ";
            cin>>val;
            Tree.Insert(val);
            break;

            case 2:
            cout<<"\nEnter Value: ";
            cin>>val;
            Tree.Delete(Tree.Search(val));
            break;

            case 3:
            cout<<"\nEnter Value: ";
            cin>>val;
            if(Tree.Search(val)!=NULL)
                cout<<"\nValue found in BST";
            break;

            case 4:
            cout<<"\nMax value in BST is: "<<Tree.Max();
            break;

            case 5:
            cout<<"\nMin value in BST is: "<<Tree.Min();
            break;

            case 6:
            cout<<"\nEnter Value: ";
            cin>>val;
            cout<<"\nSuccessor of value is: "<<Tree.Successor(val);
            break;

            case 7:
            cout<<"\nEnter Value: ";
            cin>>val;
            cout<<"\nPredecessor of value is: "<<Tree.Predecessor(val);
            break;

            case 8:
            cout<<"\nDisplaying the Tree Inorder: ";
            Tree.Display(Tree.Point_Root());
            break;

            case 9:
            return 0;

            default:
            cout<<"\nInvalid Number Pressed";
            break;  
        }
    }
    return 0;
}