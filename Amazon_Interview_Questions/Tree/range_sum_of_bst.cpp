// Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

//  Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
// Output: 32
// Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
#include<bits/stdc++.h>
using namespace std;

  class TreeNode {
      public:
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  class Solution {
public:
int sum(TreeNode*root, int low,int high)
{
    if(!root) return -1;
    queue<TreeNode*>q;
    int ans=0;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
    TreeNode*temp = q.front();
    q.pop();
     
        if(temp!=NULL)
        {
            if(temp->val >=low and temp->val <=high)
        {
            ans+=temp->val;

        }

        }
        
        if(temp->left)
        {
            q.push(root->left);
        }
        if(temp->right)
        {
            q.push(root->right);
        }
        else if(!q.empty())
        {
            q.push(NULL);
        }
    

    }
    return ans;
   
}
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        return sum(root,low,high);
        
    }
};