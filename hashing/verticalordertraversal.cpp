#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }

};
void verticalorderprint(node*root,int d,map<int, vector<int>>&m)
{
    if(root==NULL) return;
    m[d].push_back(root->data);
    verticalorderprint(root->left, d-1,m);
    verticalorderprint(root->right,d+1,m);

return;
}


int main()
{
    node*root = new node(1);
   root->left = new node(2);
   root->right = new node(3);
   root->left->left= new node(4);
   root->left->right= new node(5);
   root->right->left= new node(6);
   root->right->right= new node(7);
   root->right->right->right= new node(9);
   root->left->right->right= new node(8);

   map<int, vector<int>>m;
   int dist=0;
   verticalorderprint(root,dist,m);

   for(auto p:m)
   {
    //    cout<<p.first<<"->";
       for(int x:p.second)
       {
           cout<<x<<" , ";

       }
       cout<<endl;


   }

    return 0;
}