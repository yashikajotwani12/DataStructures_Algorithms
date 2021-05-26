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


Node* search(Node*root, int key )
{
    if(root==NULL|| root->data==key) return root; 

   if(root->data > key)
   {
       return search(root->left, key);
   }
   return search(root->right, key);
}


int main()
{
    Node*root= new Node(2);
    root->left= new Node(1);
    root->right = new Node(3);
    int key = 3;
    cout<<search(root, key)<<endl;


    return 0;
}
