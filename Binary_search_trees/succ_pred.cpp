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

void find(Node* root, Node* &pre, Node*& suc, int key)
{
    if(root == NULL) return;

    if(root->data == key)
    {
        if(root->left !=NULL)
        {
            Node*temp =root->left;
            while(temp->right)
            {
                temp= temp->right;
            }
            pre=temp;
        }
        if(root->right !=NULL)
        {
            Node*temp =root->right;
            while(temp->left)
            {
                temp= temp->left;
            }
            suc=temp;
        }
        return;
    }
    if(root->data > key)
    {
        suc=root;
        find(root->left, pre, suc, key);
    }
    else{
        pre=root;
        find(root->right, pre, suc, key);
    }
}
Node* insert(Node* node, int key)
{
    if (node == NULL) return  new Node(key);
    if (key < node->data)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}
int main()
{
    int key = 65;    //Key to be searched in BST
 
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
 
 
    Node* pre = NULL, *suc = NULL;
 
    find(root, pre, suc, key);
    if (pre != NULL)
      cout << "Predecessor is " << pre->data << endl;
    else
      cout << "No Predecessor";
 
    if (suc != NULL)
      cout << "Successor is " << suc->data;
    else
      cout << "No Successor";
    return 0;
}