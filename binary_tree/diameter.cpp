#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node*left,*right;

};
int ma;
int func(Node*root)
{
    if(!root) return 0;

    int x=func(root->left);
    int y=func(root->right);
    ma= max(ma, x+y+1);
    return max(x,y)+1;
}

int diameter(Node*root)
{
    ma=INT_MIN;
    int x= func(root);
    return ma;
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

    cout<<"Diameter is "<<endl;
    // printlevelorder(root);
    cout<< diameter(root);
    return 0;
}