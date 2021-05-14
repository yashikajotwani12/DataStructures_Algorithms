#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;
};

Node*createnode( int data)
{
    Node*newnode=new Node();
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
void inorder(Node*temp)
{
    if(!temp)
    {
        return;

    }
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->left);
}

Node* deletion(Node*root, int key)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(root->left ==NULL && root->right ==NULL)
    {
        if(root->data==key)
        {
            return NULL;
        }else
        {
            return root;
        }
    }
    queue<Node*>q;
    q.push(root);
    Node*temp;
    Node*keynode=NULL;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();

        if(temp->data == key)
        {
            keynode = temp;
        }
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }

    }

    if(keynode!=NULL){
        int x =temp->data;
        


    }




}