#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left,*right;
};

Node*newnode(int data)
{
    Node*newnode= new Node();
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

void reverselevelorder(Node*root)
{

    queue<Node*>q;
    stack<Node*>s;
    q.push(root);

    while(q.empty()==false)
    {
        root= q.front();
         q.pop();
         s.push(root);



    
    if(root->right!=NULL)
    {
        q.push(root->right);
    }
    if(root->left!=NULL)
    {
        q.push(root->left);
    }

   
    }
     while(s.empty()==false)
    {
        root=s.top();
        cout<<root->data<<" ";
        s.pop();
    }



}
int main()
{
    Node*root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
   root->left->left=newnode(4);
    root->left->right=newnode(5);

    cout<<"Level order traversal"<<endl;
    reverselevelorder(root);
    return 0;
}