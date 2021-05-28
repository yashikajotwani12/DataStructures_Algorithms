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

void kthutil(Node* root, int k , int &c)
{
    if(root==NULL || c>=k)
    {
        return;
    }

    kthutil(root->right, k, c);

    c++;
    if(c==k)
    {
        cout<<"Kth largest element is "<<root->data<<endl;
        return;
    }
    kthutil(root->left, k, c);
}

void kthlargest(Node*root, int k)
{
    int c=0;
    kthutil(root, c, k);
}


Node* insert(Node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return new Node(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left  = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}
 
// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    int c = 0;
    for (int k=1; k<=7; k++)
        kthlargest(root, k);
 
    return 0;
}