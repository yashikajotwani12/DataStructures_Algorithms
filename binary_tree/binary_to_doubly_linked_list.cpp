#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left,*right;
};
Node*createnode(int data)
{
    Node*newnode=new Node();
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
void binarytodll(Node*root, Node**head)
{
    if(!root) return;
    Node*prev=NULL;

    binarytodll(root->left, head);
    if(prev==NULL)
    {
        *head=root;
    }else{

        root->left=prev;
        prev->right=root;
    }
    prev=root;

    binarytodll(root->right, head);
}
void printList(Node *node)
{
    while (node!=NULL)
    {
        cout << node->data << " ";
        node = node->right;
    }
}
int main()
{
    Node*root=createnode(10);
    root->left=createnode(12);
    root->right=createnode(15);
    root->left->left=createnode(25);
    root->left->right=createnode(30);
    root->right->left=createnode(36);


    Node*head=NULL;
    binarytodll(root,&head);

    printList(head);

return 0;
    
}