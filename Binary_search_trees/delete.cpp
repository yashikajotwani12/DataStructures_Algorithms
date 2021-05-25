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

Node*inordersuc(Node*root)
{
    Node*curr=root;
    while( curr && curr->left!=NULL)
    {
        curr=curr->left;

    }
    return curr;

}

Node* deletebst(Node*root, int key)
{
    if(key < root->data)
    {
        root->left = deletebst(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = deletebst(root->right, key);
    }
    else{

        if(root->left==NULL)
        {
            Node*temp=root->right;
            free(root);
            return temp;
        }
        if(root->right==NULL)
        {
            Node*temp=root->left;
            free(root);
            return temp;
        }

        Node* temp=inordersuc(root->right);
        root->data=temp->data;
        root->right=deletebst(root->right, temp->data);

    }
    return root;
    


}
void inorder(Node*root)
{
    if(root==NULL) return;
    inorder(root->left);
     cout<<root->data<<" ";
    inorder(root->right);


}

int main()
{
    Node*root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right->right=new Node(6);
    inorder(root);
    cout<<endl;

    root= deletebst(root, 2);
    inorder(root);
    cout<<endl;
   
    return 0;



}