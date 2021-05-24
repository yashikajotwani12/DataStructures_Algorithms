#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;
};


void mir(Node*root)
{
    if(!root) return ;
    mir(root->left);
    mir(root->right);
    swap(root->left, root->right);
    



}