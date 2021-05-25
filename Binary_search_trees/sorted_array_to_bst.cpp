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


Node* sortedarraytobst(int arr[], int start, int end)
{

    if(start > end)
    {
        return NULL;
    }
    int mid = (start+end)/2;
    Node*root = new Node(arr[mid]);

    root->left = sortedarraytobst(arr, start,mid-1);
    root->right = sortedarraytobst(arr, mid+1, end);


    return root;

}
void preorderprint(Node*root)
{
    if(root==NULL) return;

    cout<<root->data<<" ";
    preorderprint(root->left);
    preorderprint(root->right);
}
int main()
{
    int arr[]={10,20,30,40,50};
    int n=5;
    Node*root=sortedarraytobst(arr,0,n-1);
    preorderprint(root);
    cout<<endl;

    return 0;
}