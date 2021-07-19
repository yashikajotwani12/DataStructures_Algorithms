#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left,*right;
};
Node*newNode(int data)
{
    Node*temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;

}
Node*lca(Node*root,int a, int b)
{
    if(!root) return NULL;
    // root's value is equal to value of a or b
    if(root->data == a or root->data ==b)
    {
        return root;
    }
    // search in the left or right subtrees
    Node*left = lca(root->left,a,b);
    Node*right = lca(root->right,a,b);

    if(left!=NULL and right!=NULL) return root;

    if(left!=NULL) return left;
    else return right;

}
int main()
{
    Node*root = newNode(8);
    root->left = newNode(3);
    root->left->left = newNode(14);
    root->left ->left ->right = newNode(13);
    root->right = newNode(10);
    root->right->right = newNode(1);
    root->right->left = newNode(6);
    root->right->left->left= newNode(7);
    
    return 0;
}