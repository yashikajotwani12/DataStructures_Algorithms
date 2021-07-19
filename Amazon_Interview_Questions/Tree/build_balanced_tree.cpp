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
Node* buildtree(int *a , int s,int e)
{
    // base case
    if(s > e) return NULL;
    int mid =(s+e)/2;
    Node*root =  newnode(a[mid]);
    root->left = buildtree(a,s,mid-1);
    root->right = buildtree(a,mid+1,e);
    return root;


}
vector<int>levelorder(Node*root)
{
    vector<int>ans;
    if(!root) return  ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node*temp = q.front();
        ans.push_back(temp->data);
        q.pop();
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return ans;
}

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9};
    int n=9;

    Node*root = buildtree(a,0,n-1);
    vector<int>ans= levelorder(root);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}