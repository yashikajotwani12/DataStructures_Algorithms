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
void reversetr(Node*root)
{
    vector<int>ans;
    if(!root) return ;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node*temp=q.front();
        ans.push_back(temp->data);
        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);
        q.pop();
    }
    reverse(ans.begin(), ans.end());
    for(int i=0;i <ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}