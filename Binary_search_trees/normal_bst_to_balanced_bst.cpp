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

void store(Node*root, vector<Node*>&nodes)
{
    if(root==NULL) return;

    store(root->left, nodes);
    nodes.push_back(root);
    store(root->right, nodes);
}

Node*create(vector<Node*>&nodes, int start, int end)
{
    if(start > end) return NULL;

    int mid= (start + end)/2;

    Node* root = nodes[mid];
    root->left = create(nodes, start, mid-1);
    root->right =  create(nodes,  mid+1, end);
    return root;
}

Node* build(Node*root)
{
    vector<Node*>nodes;
    store(root, nodes);
    int n=nodes.size();
  return  create(nodes, 0, n-1);
}


void preorder(Node*root)
{
    if(root==NULL) return;

    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    Node*root= new Node(10);
    root->left = new Node(8);
    root->left->left = new Node(7);
    root->left->left->left = new Node(6);
    root->left->left->left->left = new Node(5);
    preorder(root);
    root=build(root);

    cout<<" Preorder traversal "<<endl;
    preorder(root);
    return 0;
}