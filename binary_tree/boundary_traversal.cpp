#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left,*right;
};

void lefttree(Node*root, vector<int>&ans)
{
    if(!root) return ;
    if(root->left)
    {
    ans.push_back(root->data);
    lefttree(root->left, ans);
    }
    else if(root->right)
    {
    ans.push_back(root->data);
    lefttree(root->right, ans);
    }
}
void righttree(Node*root, vector<int>&ans)
{
    if(!root) return ;
    if(root->right)
    {
     righttree(root->right, ans);
    ans.push_back(root->data);
   
    }
    else if(root->left)
    {
    righttree(root->left, ans);
    ans.push_back(root->data);
    
    }
}
void leaf(Node*root, vector<int>&ans)
{
    if(!root) return;
    leaf(root->left, ans);
    if(!root->left && !root->right)
    ans.push_back(root->data);
    leaf(root->right, ans);

}
vector <int> printBoundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        ans.push_back(root->data);
        lefttree(root->left,ans);
        leaf(root, ans);
        righttree(root->right,ans);
        return ans;
    }