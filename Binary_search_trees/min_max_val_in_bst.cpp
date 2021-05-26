#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left,*right;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};


int minvalue(Node* root)
{
    if(root==NULL) return 0;

    Node*current=root;
    while(current && current->left!=NULL)
    {
        current=current->left;
    }
    return current->data;
}
int maxvalue(Node* root)
{
    if(root==NULL) return 0;

    Node*current=root;
    while(current && current->right!=NULL)
    {
        current=current->right;
    }
    return current->data;
}

void inorder(Node*root)
{
    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data;
    inorder(root->right);

}

int main()
{
    Node*root= new Node(27);
    root->left= new Node(25);
    root->left->right= new Node(26);
    root->right= new Node(30);
    root->right->right= new Node(31);

    inorder(root);
    cout<<" Maximum is "<< maxvalue(root)<<endl;
    cout<<" Minimum is "<< minvalue(root)<<endl;


    return 0;



}