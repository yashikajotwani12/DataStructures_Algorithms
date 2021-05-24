#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;
};


vector<int>left(Node*root)
{
    vector<int>ans;
    queue<Node*>q;
    if(!root) return ans;
    q.push(root);
    while(!q.empty())
    {
        int sz=q.size();
        ans.push_back(q.front()->data);
        while(sz--)
        {
            Node*temp=q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);


        }
    }
    return ans;
}