#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left,*right;
};
Node*newNode(int data)
{
    Node*temp = new Node();
    temp->data = data;
    temp->left = temp->right =NULL;
    return temp;

}
int count(Node*root)
{
    if(root==NULL) return 0;
    return count(root->left)+count(root->right)+1;
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

int valueat(Node*root)
{
    int ans=0;
    if(root==NULL) return ans;
    else
    return root->data;
    ans += valueat(root->left)+valueat(root->right);
    return ans;
}
int replacesum(Node*root)
{
    if(root== NULL) return 0;
    // leaf nodes
    if(root->left==NULL and root->right==NULL) return root->data;
    // recursive part

   
    int left= replacesum(root->left);
    int right = replacesum(root->right);
    int temp = root->data;
    root->data = left+right;
    return temp+root->data;


}
int main()
{
     Node*root = newNode(8);
    root->left = newNode(3);
    root->left->left = newNode(14);
    root->left ->left ->right = newNode(13);
    root->right = newNode(10);
    root->right->right = newNode(1);
    root->right->left = newNode(6);
    root->right->left->left= newNode(7);
    root->right->left->right = newNode(9);

 vector<int>ans = levelorder(root);
    
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
  
    replacesum(root);
    cout<<endl;
    ans = levelorder(root);
    
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
   levelorder(root);
  
    // cout<<count(root);
    return 0;
}