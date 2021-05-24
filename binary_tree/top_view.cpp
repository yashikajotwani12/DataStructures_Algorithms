#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left,*right;
};


void topview(Node*root)
{
    unordered_map<int , int>m;
    queue<pair<Node*, int>>q;
    if(!root) return;

    q.push({root,0});

    while(!q.empty())
    {
        Node*temp=q.front().first;
        int h=q.front().second;
        q.pop();
        if(!m[h]) m[h]=temp->data;
        if(temp->left) q.push({temp->left, h-1});
        if(temp->right) q.push({temp->right, h+1});




    }
    for(auto x:m) cout<<x.second<<" ";
}