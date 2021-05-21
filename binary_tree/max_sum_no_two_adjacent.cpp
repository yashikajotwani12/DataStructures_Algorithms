#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left,*right;
};

Node* newnode(int data)
{
    Node*newnode = new Node();
    newnode->data=data;
    newnode->left=newnode->right=NULL;

    return (newnode);

}
unordered_map<Node*, int>dp;
int getmaxutil(Node*root)
{
    if(!root) return 0;
    if(dp[root]) return dp[root];
    int inc= root->data;
    if(root->left)
    {
        inc+=getmaxutil(root->left->left);
        inc+=getmaxutil(root->left->right);
        
    }
    if(root->right)
    {
        inc+=getmaxutil(root->right->left);
        inc+=getmaxutil(root->right->right);

    }
    int exc=getmaxutil(root->left)+getmaxutil(root->right);

    dp[root]= max(inc, exc);
    return dp[root];
}
int main()
{
    Node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->right->left = newnode(4);
    root->right->right = newnode(5);
    root->left->left = newnode(1);
 
    cout << getmaxutil(root) << endl;
    return 0;
}