#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
// Node* newNode(int data)
// {
//     Node*newnode = new Node();
//     newnode->data=data;
//     newnode->left=newnode->right=NULL;

//     return (newnode);

// }

void printvector(const vector<int>& v, int i)
{
    for(int j=i;j<v.size();j++)
    {
        cout<<v[j]<<" ";
    }
    cout<<endl;
}

void func(Node*root, vector<int>& path, int k)
{
    if(!root) return;

    path.push_back(root->data);
    func(root->left, path,k);
    func(root->right, path, k);

    int sum=0;

    for(int j=path.size()-1;j>=0;j--)
    {
        sum+=path[j];
         if(sum==k)
         {
             printvector(path,j);

         }

    }
    path.pop_back();
   
}
// Driver code
int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);
  
    int k = 5;
    vector<int>path;
    func(root,path,k);
  
    return 0;
}