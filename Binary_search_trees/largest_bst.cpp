#include<bits/stdc++.h>
#include<climits>
using namespace std;


struct Node{
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

struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool isbst;

};

Info largestbstinbt(Node* root)
{
    if(root==NULL)
    {
        return {0,INT_MIN, INT_MAX,0, true};
    }
    if(root->left ==NULL && root->right ==NULL)
    {
        return {1,root->data, root->data, 1,true};
    }

    Info leftinfo =largestbstinbt(root->left);
    Info rightinfo =largestbstinbt(root->right);

    Info current;
    current.size =(1+ leftinfo.size + rightinfo.size);

    if(leftinfo.isbst && rightinfo.isbst && leftinfo.max < root->data && rightinfo.min > root->data)
    {
        current.min= min(leftinfo.min , min(rightinfo.min, root->data));
        current.max= max(rightinfo.max , max(leftinfo.min, root->data));


        current.ans= current.size;
        current.isbst =true;

        return current;
    }

    current.ans = max(leftinfo.ans,rightinfo.ans);
    current.isbst =false;

    return current;
}

int main()
{
    Node*root= new Node(15);
    root->left = new Node(20);
    root->right= new Node(30);
    root->left->left = new Node(5);


    cout<<"Largest BST is BT "<<largestbstinbt(root).ans<<endl;
    return 0;


}