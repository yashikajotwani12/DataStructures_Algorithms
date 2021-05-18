#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left,*right;
};

vector<int> bottomview(Node*root)
{
    map<int , int>m;
    vector<int>v;
    queue<pair<Node*, int>>q;
    if(!root) return v;
    q.push({root,0});
    while(!q.empty())
    {
        Node*temp=q.front().first;
        int h=q.front().second;
        q.pop();
        m[h]=temp->data;
        if(temp->left) q.push({temp->left, h-1});
        if(temp->right) q.push({temp->right, h+1});

    }
    for(auto x: m) v.push_back(x.second);


    return v;

}

