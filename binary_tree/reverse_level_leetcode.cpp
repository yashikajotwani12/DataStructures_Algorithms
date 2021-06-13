#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode*left,*right;
};

TreeNode*newnode(int data)
{
    TreeNode*newnode= new TreeNode();
    newnode->val=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}


int depth(TreeNode* root)     //function to find the no of levels in tree
{
    if(root==NULL)
        return 0;
    return 1+max(depth(root->left),depth(root->right));
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    int d=depth(root);
    vector<vector<int>> ans(d);
    if(d==0)
        return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            TreeNode* cur=q.front();
            q.pop();
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
            ans[d-1].push_back(cur->val);
        }
        d--;
    }
    return ans;
}

// my solution 
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        vector<int>res;
        queue<TreeNode*>q;
        if(!root) return ans;
        int nodecount=0;
        q.push(root);
        while(!q.empty())
        {
            nodecount=q.size();
          
            while(nodecount--)
            {
                  TreeNode*temp=q.front();
                res.push_back(temp->val);
                
                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);
                q.pop();    
            }
            reverse(res.begin(), res.end());
            ans.emplace_back(res);
            res.erase(res.begin(), res.end());
        }
        reverse(ans.begin(), ans.end());
        return  ans;
        
    }
};