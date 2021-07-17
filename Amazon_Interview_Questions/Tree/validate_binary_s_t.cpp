// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.


//  Definition for a binary tree node
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
    bool isvalid(TreeNode*root, long long min, long long max)
    {
        if(!root) return true;
        bool b1 = isvalid(root->left,min, root->val);
        bool b2 = isvalid(root->right,root->val, max);
        return b1 and b2 and root->val > min and root->val < max;

    }
    
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(root->left == NULL and root->right == NULL)
        return true;
        long long int min = LONG_MIN;
        long long int max = LONG_MAX;

        return isvalid(root, min, max);
      
        
    }
};