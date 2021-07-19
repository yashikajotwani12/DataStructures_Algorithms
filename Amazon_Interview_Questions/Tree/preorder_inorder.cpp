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
// pointer variable should be global or static bcoz we are making a recursive function
// type of linear search 
// like we pick a element from preorder and search it in inoreder and the make it as a index and then recursively call from s to index-1 for the left subtree and index+1 to end for the right subrtree
Node* createtree(int *in, int*pr, int s,int e)
{

  static int i=0;
  // base case
  if(s > e) return NULL;
  Node*root = newnode(pr[i]);
  int index =-1;
  for(int j=s;s<=e;j++)
  {
      if(in[j]== pr[i])
      {
          index =j;
          break;
      }

  }
  i++;
  root->left = createtree(in,pr,s,index-1);
  root->right = createtree(in,pr,index+1,e);
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
    int in[] ={3,2,8,4,1,6,7,5};
    int pr[]={1,2,3,4,8,5,6,7};
    int n= sizeof(in)/sizeof(int);
    Node*root = createtree(in,pr,0,n-1);
    vector<int>ans= levelorder(root);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;

    
}