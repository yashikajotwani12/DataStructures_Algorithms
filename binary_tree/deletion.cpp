// #include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

struct node{
    int data;
    struct node*left;
    struct node*right;
};
 node*newnode(int data)
{
    struct node*temp=new node;
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
void inorder(int root)
{
    if(root==NULL)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void delete_node(struct node* root, struct node* node)
{
    queue< struct node*>q;
    q.push(root);
    struct node*temp;
    while(q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp==node)
        {
            
        }
    }

}