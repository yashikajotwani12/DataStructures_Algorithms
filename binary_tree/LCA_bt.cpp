#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left, *right;
    
};
Node* newNode(int data)
{
    Node*newnode = new Node();
    newnode->data=data;
    newnode->left=newnode->right=NULL;

    return (newnode);

}

Node*findLCA(Node*root, int n1, int n2)
{
    if(!root) return NULL;

    if(root->data ==n1 or root->data== n2)
    {
        return root;
    }
    Node*l= findLCA(root->left, n1, n2);
    Node*r=findLCA(root->right, n1,n2);
    if(l and r) return root;
    if(l) return l;
    else return r;

}
int main()
{
    // Let us create binary tree given in the above example
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->data;
    cout << "nLCA(4, 6) = " << findLCA(root, 4, 6)->data;
    cout << "nLCA(3, 4) = " << findLCA(root, 3, 4)->data;
    cout << "nLCA(2, 4) = " << findLCA(root, 2, 4)->data;
    return 0;
}

