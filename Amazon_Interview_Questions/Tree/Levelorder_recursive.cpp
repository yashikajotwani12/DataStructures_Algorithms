#include<bits/stdc++.h>
using namespace std;
class TreeNode
{
    public:
    int data;
    TreeNode*left,*right;

};
TreeNode* newNode(int data)
{
    TreeNode*temp=new TreeNode();
  
    temp->data = data;
    temp->left = temp->right = NULL;
  
    return temp;
}

int height(TreeNode*root)
{
    if(root== NULL)
    {
        return 0;
    }
    return max(height(root->right),height(root->left))+1;

}
void printkthlevel(TreeNode*root, int k)
{
    if(root==NULL) return;
    if(k==1)
    {
        cout<<root->data<<" ";
        return;
    }
    printkthlevel(root->left,k-1);
    printkthlevel(root->right,k-1);

}
void printalllevels(TreeNode*root)
{
    int n= height(root);
    for(int i=1;i<=n;i++)
    {
        printkthlevel(root, i);
        cout<<endl;
    }
}
int main()
{
    TreeNode*root = newNode(8);
    root->left = newNode(3);
    root->left->left = newNode(14);
    root->left ->left ->right = newNode(13);
    root->right = newNode(10);
    root->right->right = newNode(1);
    root->right->left = newNode(6);
    root->right->left->left= newNode(7);
    root->right->left->right = newNode(9);
   printalllevels(root);

    return 0;

}