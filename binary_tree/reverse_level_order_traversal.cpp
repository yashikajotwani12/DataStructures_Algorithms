#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left,*right;
};

void reverseorder(Node*root)
{
    stack<Node*>s;
    queue<Node*>q;
    q.push(root);
     Node*temp;
    while(q.empty()==false)
    {
        temp=q.front();
        q.pop();
        s.push(temp);
         if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);
       

    }
    while(s.empty()==false)
    {
        temp = s.top();
        cout<<temp->data<<" ";
        s.pop();

    }
}
Node*newNode(int data)
{
    Node*temp=new Node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}

int main()
{
  Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);
  
    cout << "Level Order traversal of binary tree is \n";
   reverseorder(root);
  
    return 0;
}