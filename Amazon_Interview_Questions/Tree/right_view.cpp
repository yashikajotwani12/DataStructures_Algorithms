#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left,*right;
};
Node*newnode(int data)
{
    Node*temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;

}
// by referenece store the global max no copies will be made while recursive calls

void printrightview(Node*root,int level,int &maxlevel)
{
    if(root == NULL) return;
    if(maxlevel < level)
    {
        cout<<root->data<<" ";
        maxlevel = level;
    }
    // right
    // left
    printrightview(root->right, level+1,maxlevel);
    printrightview(root->left,level+1,maxlevel);

}
int main()
{
    Node*root = NULL;
    cin>>root;
    cout<<root<<endl;
    int maxlevel =-1;
    printrightview(root,0,maxlevel);
    return 0;
}