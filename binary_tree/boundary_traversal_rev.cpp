#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};
void leftboundary(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    if (root->left)
    {
        ans.push_back(root->data);
        leftboundary(root->left,ans);
    }
    else if(root->right)
    {
         ans.push_back(root->data);
        leftboundary(root->right,ans);

    }
}
void leaf(Node *root, vector<int> &ans)

{
    if (!root)
        return;
    if (root->right)
    {
        ans.push_back(root->data);
        leftboundary(root->right,ans);
    }
    else if(root->left)
    {
         ans.push_back(root->data);
        leftboundary(root->left,ans);

    }
}
void rightboundary(Node *root, vector<int> &ans)

{
    if(!root)
    {
        return;
    }
    leaf(root->left, ans);
    if(!root->left && !root->right) ans.push_back(root->data);
      leaf(root->right, ans);
}

vector<int> boundary(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    ans.push_back(root->data);
    leftboundary( root->left, ans);
    leaf( root, ans);
    rightboundary(root->right, ans);

    return ans;
}
Node* newNode(int data)
{
    Node*temp=new Node();
  
    temp->data = data;
    temp->left = temp->right = NULL;
  
    return temp;
}
  
// Driver program to test above functions
int main()
{
    // Let us construct the tree given in the above diagram
    Node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
  
    boundary(root);
  
    return 0;
}