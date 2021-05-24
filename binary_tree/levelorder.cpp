#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node*left,*right;
};


vector<int>level(Node*root)
{
    vector<int>ans;
    queue<Node*>q;
    if(!root) return ans;

    q.push(root);
    while(!q.empty())
    {
        Node*temp= q.front();
      
        ans.push_back(temp->data);
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
          q.pop();

    }
    return ans;
}