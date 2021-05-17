#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left=NULL;
    Node* right=NULL;

};
Node*createnode(int data)
{
    Node*newnode=new Node();
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
void printleft(Node* root)
{
    if(!root)
    return;

    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
       int  n=q.size();
       
        for(int i=1;i<=n;i++)
        {
            Node*temp=q.front();
            q.pop();
            if(i==1)
            {
                cout<<temp->data<<" ";
            }
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
        }
    }
}
int main()
{
    Node*root=createnode(10);
    root->left=createnode(2);
    root->right=createnode(3);
    root->left->left=createnode(7);
    root->left->right=createnode(8);
    root->right->right=createnode(15);
    root->right->left=createnode(12);
    root->right->right->left=createnode(14);
printleft(root);
return 0;
}