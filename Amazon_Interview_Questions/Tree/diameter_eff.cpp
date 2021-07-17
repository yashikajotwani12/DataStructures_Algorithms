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
class Pair{
    public:
    int height;
    int diameter;
};
Pair diameter(Node*root)
{
    Pair p;
    if(root==NULL)
    {
        p.diameter = p.height=0;
        return p;
    }
    //otherwise
    Pair left = diameter(root->left);
    Pair right = diameter(root->right);
    p.height = max(left.height, right.height)+1;
    p.diameter = max(left.height+ right.height, max(left.diameter, right.diameter));
    return p;

  
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

   Pair p = diameter(root);
   cout<<p.height<<endl;
   cout<<p.diameter<<endl;

    return 0;
}