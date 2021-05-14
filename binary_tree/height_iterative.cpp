#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left,*right;

};

int treeheight(Node*root)
{
    if(root==NULL){
        return 0;
    }
    queue<Node*>q;
    q.push(root);
    int height=0;
    while(1)
    {
        int nodecount= q.size();
        if(nodecount==0)
        {
            return height;
        }
        height++;

        while(nodecount>0)
        {
            Node*node=q.front();
            q.pop();
            if(node->left!=NULL)
            {
                q.push(node->left);
            }
            if(node->right!=NULL)
            {
                q.push(node->right);
            }
            nodecount--;
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

//  cout<<  maxdepth(root);
    // printlevelorder(root);
    cout<<" Height is : "<<treeheight(root);
    return 0;
}