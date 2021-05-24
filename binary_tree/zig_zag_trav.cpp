#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left,*right;
};

vector<int>zigzag(Node*root)
{
    vector<int>ans;
    queue<Node*>q;
    if(!root) return ans;
    q.push(root);
    int f=1;
    while(!q.empty())
    {
        Node*temp;
        vector<int>res;
        int sz=q.size();
        while(sz--)
        {
            temp=q.front();
            q.pop();
            res.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        if(f%2==0)
        {
            reverse(res.begin(), res.end());
        }
        
        for(int i=0;i<res.size();i++)
        {
            ans.push_back(res[i]);
        }
        f=!f;
    }
    return ans;
}