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
void calcpointer(Node*root, Node** first, Node**mid,Node**last, Node**prev)
{
    if(root==NULL){return;}
    calcpointer(root->left, first, mid, last, prev);

    if(*prev && root->data < (*prev)->data)
    {
        if(!*first)
        {
            *first = *prev;
            *mid=root;

        }else{
            *last=root;

        }

    }
    *prev=root;
    calcpointer(root->right, first, mid, last, prev);

}
void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y =temp;
}
void restorebst(Node*root)
{
    Node*first,*mid,*last,*prev;
    first=NULL;
    mid=NULL;
    last=NULL;
    prev=NULL;

    calcpointer(root, &first,&mid,&last,&prev);


    if(first && last)
    {
        swap(&(first->data), &(last->data));
    }
    else if(first && mid)
    {
        swap(&(first->data) , &(mid->data));

    }


}
void inorder(Node*root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
 
 }
int main()
{                                        

Node*root= new Node(6);
root->left= new Node(9);
root->right = new Node(3);
root->left->left = new Node(1);
root->left->right = new Node(4);
root->right->right = new Node(13);

inorder(root);

restorebst(root);
cout<<endl;      
inorder(root);



    return 0;

}