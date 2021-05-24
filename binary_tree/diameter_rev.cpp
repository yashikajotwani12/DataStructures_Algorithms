#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left,*right;
};

Node*newnode(int data)
{
    Node*newnode= new Node();
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

int ma;
int solve(Node*root)
{
    if(!root) return 0;
    int x=solve(root->left);
    int y=solve(root->right);

    ma=max(ma, x+y+1);
    return (max(x,y)+1);
}

int diam(Node*root)
{
    ma=INT_MIN;
    int x=solve(root);
    return ma;
}