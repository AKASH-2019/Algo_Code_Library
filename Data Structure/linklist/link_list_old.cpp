#include<bits/stdc++.h>
using namespace std;

struct node
{

    int value;
    node *next;

};

node *root=NULL;


void append(int value)
{
    if(root==NULL)
    {
        root=new node();
        root->value=value;
        root->next=NULL;

    }
    else
    {
        node *current_node=root;
        while(current_node->next!=NULL)
        {
            current_node=current_node->next;
        }
        node *newnode=new node();

        newnode->value=value;
        newnode->next=NULL;
        current_node->next=newnode;

    }

}

void display()
{
    node *current_node=root;

    while(current_node!=NULL)
    {
        cout<<current_node->value<<" ";
        current_node=current_node->next;
    }
}

void delete_node(int value)
{
    node *current_node=root;
    node *prev_node=root;

    while(current_node->value!=value)
    {
        prev_node=current_node;
        current_node=current_node->next;
    }

    if(current_node==root)
    {
        node *temp=root;
        root=root->next;
        delete(temp);
    }
    else
    {
        prev_node->next=current_node->next;
        delete(current_node);
    }

}

void insert_node(int pos,int value)
{
    node *current_node=root;
    node *next_node=new node();
    node *insert_node=new node();
    node *prev_node=new node();

    insert_node->value=value;
    insert_node->next=NULL;

    while(current_node->value!=pos)
    {
        current_node=current_node->next;
    }
    next_node=current_node->next;

    if(current_node==root)
    {
        node *temp=root;
        insert_node->next=temp->next;
        root->next=insert_node;
    }
    else
    {
        insert_node->next=next_node;
        current_node->next=insert_node;

    }

}

int main()
{
    int n,v;
    cin>>n;
    for(int i=1; i<=n; i++)
        append(i);

    display();

    int choice;
    cout<<endl<<endl;
    while(1)
    {
        cout<<"0. break"<<endl;
        cout<<"1. print -> "<<endl;
        cout<<"2. insert -> "<<endl;
        cout<<"3. delete -> "<<endl;

        cin>>choice;
        if(choice == 0) break;

        switch(choice)
        {
        case 1:
            cout<<"Linklist display : "<<endl;
            display();
            cout<<endl<<endl;
            break;

        case 2:
            int pos, item;
            cout<<"Enter the position and data to insert: "<<endl;
            cin>>pos>>item;
            insert_node(pos, item);
            break;

        case 3:
            int v;
            cout<<"Enter the value to delete: ";
            cin>>v;
            delete_node(v);
            break;
        }
    }


}
