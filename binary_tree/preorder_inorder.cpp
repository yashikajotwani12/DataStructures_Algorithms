#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
};

class Solution{
    public:
    int idx=0;
    unordered_map<int, int>m;
    Node*solve(int pre[], int in[], int lb, int ub)
    {
        if(lb> ub) return NULL;
        Node*res= new Node(pre[idx++]);
        if(lb==ub) return res;
        int mid=m[res->data];
        res->left= solve(pre,in, lb,mid-1);
        res->right=solve(pre, in, mid+1,ub);
        return res;
        
    }
    
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        idx=0;
         m.clear();
         for(int i=0;i<n;i++)
         {
             m[in[i]]=i;
         }
          Node*root=solve(pre,in, 0, n-1);
          return root;
    }
};
