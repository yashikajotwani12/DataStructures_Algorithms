#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left,*right;
};

int solve(Node*root)
{
    if(!root) return 0;
    int a=solve(root->left);
    int b=solve(root->right);
    int x=root->data;

    root->data=a+b;
    return a+b+x;
}

void solvefin(Node*root)
{
    solve(root);
}