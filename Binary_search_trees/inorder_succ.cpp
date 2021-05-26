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
        right= NULL;
    }
};
Node*minval(Node*root)
{
    Node*curr= root;
    while(curr && curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}

Node*inordersucc(Node*root, Node*node)
{
    if(node->right !=NULL)
    {
        return minval(node->right);
    }
    Node*succ =NULL;

    while(root!=NULL)
    {
        if(node->data < root->data)
        {
            succ= root;
            root= root->left;
        }
        else if(node->data > root->data)
        {
            root=root->right;
        }else{
            break;
        }
    }
    return succ;
}
Node*insert(Node*root, int val)
{
    if(root==NULL) return new Node(val);

    if(val < root->data)
    {
        root->left = insert(root->left, val);
    }
    if(val > root->data)
    {
        root->right = insert(root->right, val);
    }
    return root;
}
int main()
{
     Node *root = NULL, *temp, *succ, *min;
 
    // creating the tree given in the above diagram
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    temp = root->left->right->right;
     
    // Function Call
    succ = inordersucc(root, temp);
    if (succ != NULL)
        printf(
            "\n Inorder Successor of %d is %d ",
            temp->data, succ->data);
    else
        printf("\n Inorder Successor doesn't exit");
 
    getchar();
    return 0;
}