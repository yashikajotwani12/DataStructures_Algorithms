#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node*left,*right;
    node(int d)
    {
        val = d;
        left = right =NULL;
    }
};
node*createtree()
{
    int data;
    cin>>data;
    if((data)==-1) return NULL;
    node*root= new node(data); 
    root->left =createtree();
    root->right=createtree();
    return root;
}
int findnode()
{

}
int bigbang(node*root, int x,int n)
{
    
}

int main()
{
    int N,n,x;
    cin>>N>>n>>x;
    node*root= createtree();

}
