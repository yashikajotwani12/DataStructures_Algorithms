#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left,*right;
};


class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int>ans;
       queue<Node*>q;
       if(!root) return ans;
       
       q.push(root);
       while(!q.empty())
       {
           int sz=q.size();
           Node*t;
           while(sz--)
           {
               t=q.front();
               q.pop();
               if(t->left)  q.push(t->left);
               if(t->right) q.push(t->right);
           }
           ans.push_back(t->data);
       }
       return ans;
       
    }
};
