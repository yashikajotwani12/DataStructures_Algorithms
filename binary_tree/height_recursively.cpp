#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left,*right;

};

int maxdepth(Node*node){
    if(node==NULL)
    {
        return 0;
    }
    else{
        int ld=maxdepth(node->left);
        int rd=maxdepth(node->right);


        // if(ld > rd)
        // {
        //     return (ld+1);
        // }else{
        //     return (rd+1);
        // }

        return( ld > rd ?ld+1:rd+1);
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

 cout<<  maxdepth(root);
    // printlevelorder(root);
    return 0;
}