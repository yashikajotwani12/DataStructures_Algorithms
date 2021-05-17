#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;
};

Node* createnode(int data)
{
    Node* newnode= new Node();
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
void inorder(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node*mirrortree(Node*root)
{
    if(root==NULL)
    {
        return root;
    }
    swap(root->left,root->right);
    if(root->left)
    {
        mirrortree(root->left);
    }

    if(root->right)
    {
        mirrortree(root->right);
    }
    return root;
}

int main()
{
    Node* node=createnode(5);
    node->left=createnode(3);
    node->right=createnode(6);
    node->left->left=createnode(2);
    node->left->right=createnode(4);
    cout<<"Original tree: ";
    inorder(node);
    mirrortree(node);

    cout<<" Mirror tree : ";
    inorder(node);

    return 0;
}



