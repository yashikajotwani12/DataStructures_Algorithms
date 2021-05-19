#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left,*right;
};

vector<int>diagonal(Node*root)
{
    queue<Node*>q;
    vector<int>ans;
    if(!root) return ans;

    q.push(root);
    while(!q.empty())
    {
        Node*temp=q.front();
        q.pop();
        while(temp)
        {
            if(temp->left) q.push(temp->left);
            ans.push_back(temp->data);
            temp=temp->right;
        }
    }
    return ans;
}