#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int key;
    Node*left;
    Node*right;

};

Node*newNode(int k)
{
    Node*newnode = new Node;
    newnode->key=k;
    newnode->left=newnode->right =NULL;
    return newnode;
}
unsigned int countnodes(Node*root)
{
    if(root==NULL)
    {
        return (0);
    }
    return (1+countnodes(root->left)+countnodes(root->right));
}

bool iscomplete(Node*root, int index, int number_nodes)
{
    if(root==NULL) return (true);

    if(index >= number_nodes)
    {
        return (false);
    }

    return (iscomplete(root->left, 2*index+1, number_nodes) and iscomplete(root->right, 2*index+2, number_nodes));

}
bool isheaputil(Node*root)
{
    if(root->left==NULL and root->right==NULL)
    {
        return (true);
    }
    if(root->right==NULL)
    {
        return (root->key >= root->left->key);

    }else{
        if(root->key >= root->left->key and root->key >= root->right->key)
        {
            return ((isheaputil(root->left))and (isheaputil(root->right)));
        }else{
            return (false);
        }
    }

}
bool isheap(Node*root)
{
    unsigned int node_count = countnodes(root);
    int index=0;
    if(iscomplete(root, index, node_count) and isheaputil(root))
       return true;
    return false;

}

int main()
{Node* root = NULL;
    root = newNode(10);
    root->left = newNode(9);
    root->right = newNode(8);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    root->left->left->left = newNode(3);
    root->left->left->right = newNode(2);
    root->left->right->left = newNode(1);
  
    // Function call
    if (isheap(root))
        cout << "Given binary tree is a Heap\n";
    else
        cout << "Given binary tree is not a Heap\n";
  
    return 0;

}