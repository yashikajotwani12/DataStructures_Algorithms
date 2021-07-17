// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []
// /**

//  Definition for a binary tree node.
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
   vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>>ans;
       if(!root) return ans;
       vector<int>result;
       int size;
       queue<TreeNode*>q;
       q.push(root);
       int f=1;
       while(!q.empty())
       {
           size= q.size();
           while(size--)
           {
               TreeNode* temp = q.front();
               result.push_back(temp->val);
               if(temp->left) q.push(temp->left);
               if(temp->right) q.push(temp->right);
               q.pop(); 
           }
           if(f%2==0)
           {
               reverse(result.begin(),result.end());
           }
           ans.emplace_back(result);
           result.erase(result.begin(),result.end());
           f=!f;

       }
       return ans;
   }
};
