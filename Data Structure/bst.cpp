#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left=NULL;
    node *right=NULL;
};
node* root;

void insert_node(int value)
{
    node *newnode=new node();
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL)
        root=newnode;
    else
    {
        node *temp=root;
        while(1)
        {
            if(newnode->data<=temp->data)
            {
                if(temp->left==NULL)
                {
                    temp->left=newnode;
                    //root=temp;
                    break;
                }
                else
                    temp=temp->left;
            }
            else
            {
                if(temp->right==NULL)
                {
                    temp->right=newnode;
                    //root=temp;
                    break;
                }
                else
                    temp=temp->right;
            }
        }
    }

/**
    if(root == NULL)
    {
        node *newnode=new node();
        newnode->data=value;
        newnode->left=NULL;
        newnode->right=NULL;
        root=newnode;
    }

    else if(data <= root->data)
        root->left = Insert(root->left, data);

    else
        root->right = Insert(root->right, data);

    return root;

*/

}

bool Search(int data)
{
    node* current=root;

    while(1)
    {
        if(current==NULL)
        {
            return false;
        }
        else if(current->data==data)
        {
            return true;
        }
        else if(current->data>=data)
            current=current->left;

        else if(current->data < data)
            current=current->right;
    }
    /*if(root == NULL)
        return false;
    else if(root->data == data)
        return true;
    else if(data <= root->data)
        return Search(root->left, data);
    else
        return Search(root->right, data);*/

}
int min_element_bst(node* root)
{
    if(root==NULL)
    {
        cout<<"bst empty"<<endl;
        return -1;
    }
    node* current=root;
    while(current->left!=NULL)
    {
        current=current->left;
    }
    return current->data;
}
int max_element_bst(node* root)
{
    if(root==NULL)
    {
        cout<<"empty"<<endl;
        return -1;
    }
    node* current=root;
    while(current->right!=NULL)
        current=current->right;
    return current->data;
}



void inorder(node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
void postorder(node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
}
void preorder(node* root)
{
    if(root == NULL)
        return;
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}
node* findmin(node* root)
{
    while(root->left!=NULL)
        root=root->left;

    return root;
}
node* Delet(node* root,int data)
{
    if(root==NULL)
        return root;
    else if(data<root->data)
        root->left=Delet(root->left,data);
    else if(data>root->data)
        root->right=Delet(root->right,data);
    else
    {
        if(root->left==NULL && root->right==NULL)  /// delete node has no child
        {
            delete(root);
            root=NULL;
        }
        else if(root->left==NULL)   /// delete node has no  child in left
        {
            node* temp=root;
            root=root->right;
            delete(temp);
            return root;
        }
        else if(root->right==NULL)  /// delete node has no child in right
        {
            node* temp=root;
            root=root->left;
            delete(temp);
            return root;
        }
        else                                       /// delete node has child in both left and right
        {
            node* temp=findmin(root->right);
            root->data=temp->data;
            root->right=Delet(root->right,temp->data);
        }
    }
    return root;
}

int main()
{
    root=NULL;
    /*root=insert_node(root,40);
    root=insert_node(root,60);
    root=insert_node(root,50);
    root=insert_node(root,33);
    root=insert_node(root,55);
    root=insert_node(root,11);*/
    insert_node(40);
    insert_node(35);
    insert_node(20);
    insert_node(37);
    insert_node(36);
    insert_node(50);
    insert_node(45);
    insert_node(60);
    insert_node(56);
    insert_node(52);
    insert_node(70);


    inorder(root);
    cout<<endl<<endl;
    postorder(root);
    cout<<endl<<endl;
    preorder(root);
    cout<<endl;

    if(Search(50))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    cout<<min_element_bst(root)<<endl;
    cout<<max_element_bst(root)<<endl<<endl;

    root=Delet(root,50);
    if(Search(50))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
