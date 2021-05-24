#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left,*right;
};
int f=1;

int solve(Node*root)
{
    if(!root) return 0;
    int l=solve(root->left);
    int r=solve(root->right);
    if(abs(l-r)>1) f=0;

    return max(l,r)+1;
}

bool isbalanced(Node*root)
{
    f=1;
    solve(root);
    return f;
}