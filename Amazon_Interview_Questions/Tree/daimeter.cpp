#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node*left,*right;
    int data;
};

Node* newNode(int data)
{
    Node*temp=new Node();
  
    temp->data = data;
    temp->left = temp->right = NULL;
  
    return temp;
}
int height(Node*root)
{
    if(root== NULL) return 0;
    return max(height(root->left),height(root->right))+1;
}
int diameter(Node*root)
{
    if(root == NULL)
    {
        return 0;
    }
    int h1 = height(root->left);
    int h2= height(root->right);
    int op1 = h1+h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    return (max(op1, max(op2,op3)));
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
    root->right->left->right = newNode(9);

    cout<<diameter(root)<<endl;

    return 0;
}