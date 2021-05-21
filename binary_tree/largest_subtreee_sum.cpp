#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left,*right;
};

Node* newNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
  
int solve(Node*root, int &ans)
{
    if(!root)
    {
        return 0;
    }
    int currentsum= root->data+ solve(root->left, ans)+solve(root->right, ans);
    ans= max(ans, currentsum);
    return currentsum;
    
}
int solved(Node*root)
{
    int ans=INT_MIN;
    solve(root, ans);
    return ans;
}

int main()
{
    /*
               1
             /   \
            /     \
          -2       3
          / \     /  \
         /   \   /    \
        4     5 -6     2
    */
  
    Node* root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);
  
    cout << solved(root);
    return 0;
}