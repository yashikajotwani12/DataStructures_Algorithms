#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left,*right;
};

vector<int>zigzag(Node*root)
{
    vector<int>v;
    queue<Node*>q;
    if(!root) return v;
    q.push(root);
    int f=1;
    while(!q.empty())
    {
        vector<int>temp;
        int sz=q.size();
        while(sz--)
        {
            Node*t=q.front();
            temp.push_back(t->data);
            q.pop();
            if(t->left) q.push(t->left);
            if(t->right)q.push(t->right);

        }
        if(f%2==0) reverse(temp.begin(),temp.end());

        for(int i=0;i<temp.size();i++)
        {
            v.push_back(temp[i]);
        }
        f=!f;

    }
    return v;
}