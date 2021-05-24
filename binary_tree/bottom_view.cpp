#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left,*right;
};

vector<int>bottom(Node*root)
{
    map<int, int>m;
    queue<pair<Node*, int>>q;
    vector<int>ans;
    if(!q.empty()) return ans;
    q.push({root, 0});
    while(!q.empty())
    {
        Node*temp=q.front().first;
        int h=q.front().second;

        q.pop();
        m[h]=temp->data;
        if(temp->left) q.push({root->left, h-1});
        if(temp->right) q.push({root->right, h+1});
    }
    for(auto x: m)ans.push_back(x.second);
    return ans;
}