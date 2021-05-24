#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left,*right;
};



vector<int>right(Node*root)
{
    queue<Node*>q;
    vector<int>ans;
    if(!root) return ans;
    q.push(root);
    while(!q.empty())
    {
        int sz=q.size();
        Node*temp;
        while(sz--)
        {
            temp=q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        ans.push_back(temp->data);
    }
    return ans;
}
