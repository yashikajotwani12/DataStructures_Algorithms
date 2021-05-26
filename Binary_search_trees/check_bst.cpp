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
        right= NULL;
    }
};


bool isbst(Node*root, Node* min=NULL, Node* max=NULL)
{

    if(root==NULL)
    {
        return true;
    }
    if(min!=NULL && root->data <= min->data )
    {
        return false;

    }
    if(max!=NULL && root->data >= max->data )
    {
        return false;

    }

 bool leftvalid =isbst(root->left, min, root);
 bool rightvalid= isbst(root->right, root, max);

 return leftvalid && rightvalid;

}

int main()
{
    Node*root1= new Node(5);
    root1->left =new Node(2);
    root1->right =new Node(8);


    if(isbst(root1, NULL, NULL))
    {
        cout<<"Valid Bst "<<endl;
    }else{
        cout<<"Not Valid Bst "<<endl;
    }


    return 0;

}