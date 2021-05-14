#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;

};

Node*createnode(int data)
{
    Node*newnode=new Node();
   newnode->data=data;
   newnode->left=NULL;
   newnode->right=NULL;
}

Node*insertnode(Node*root, int data)
{
    if(root==NULL){
      root =  createnode(data);
      return root;
    }

    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node*temp=q.front();
        q.pop();

        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }else{
            temp->left=createnode(data);
            return root;
        }

        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }else{
            temp->right=createnode(data);
            return root;
        }


    }


}

void inorder(Node*temp)
{
    if(temp==NULL){
        return;

    }
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
}

int main()
{
    Node*root=createnode(10);
    root->left=createnode(11);
    root->left->left=createnode(7);
    root->right=createnode(9);
    root->right->left=createnode(15);
    root->right->right=createnode(8);

    cout<<"Inorder traversal ";
    inorder(root);
    cout<<endl;

    int key=12;
    root=insertnode(root,key);

    cout<<"Inorder after ";
    inorder(root);
    return 0;

}