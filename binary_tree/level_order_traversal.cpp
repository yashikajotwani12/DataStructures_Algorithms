#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node*left,*right;

};
void printlevelorder(Node*root)
{
    if(root==NULL)
    return;

    queue<Node*>q;
    q.push(root);

    while(q.empty()==false)
    {
        Node*temp=q.front();
         cout<<temp->data<<" ";
        q.pop();

       

        if(temp->left !=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
}

Node* newnode(int data)
{
    Node*newnode = new Node();
    newnode->data=data;
    newnode->left=newnode->right=NULL;

    return (newnode);

}

int main()
{
    Node*root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
   root->left->left=newnode(4);
    root->left->right=newnode(5);

    cout<<"Level order traversal"<<endl;
    printlevelorder(root);
    return 0;
}