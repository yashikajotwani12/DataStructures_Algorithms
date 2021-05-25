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
        right=NULL;
    }
};


Node* search(Node*root, int key)
{

    if(!root) return NULL;

    if(root->data==key) return root;

    if(root->data > key)
    {
        return search(root->left, key);
    }
    
    
        return search(root->right, key);
    


}


int main()
{
    Node*root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right->right=new Node(6);
    if(search(root, 13)==NULL)
    {
        cout<<"does'nt exist"<<endl;
    }else{
        cout<<"Key exist"<<endl;
    }
    return 0;



}