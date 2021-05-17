#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;
};

Node* createnode(int data)
{
    Node* newnode= new Node();
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
void inorder(Node*node)
{
    stack<Node*>s;
    Node*curr = node;
    while(!s.empty() || curr!=NULL)
    {
        if(curr !=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }else{
            curr= s.top();
            s.pop();
            cout<<curr->data<<" ";
            curr=curr->right;

        }
    }

}

int main()
{
    Node* node=createnode(5);
    node->left=createnode(3);
    node->right=createnode(6);
    node->left->left=createnode(2);
    node->left->right=createnode(4);
    cout<<"Original tree: ";
    inorder(node);
    // mirrortree(node);

    // cout<<" Mirror tree : ";
    // inorder(node);

    return 0;
}
