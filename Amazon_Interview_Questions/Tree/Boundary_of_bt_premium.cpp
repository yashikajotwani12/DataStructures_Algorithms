

// Description
// Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.

// Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.

// The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.

// The right-most node is also defined by the same way with left and right exchanged.
// Input: {1,#,2,3,4}
// Output: [1,3,4,2]
// Explanation: 
//   1
//    \
//     2
//    / \
//   3   4
//   The root doesn't have left subtree, so the root itself is left boundary.
//   The leaves are node 3 and 4.
//   The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
//   So order them in anti-clockwise without duplicates and we have [1,3,4,2].

#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution {
public:
    
	void printLeaves(TreeNode *root, vector<int> &res){
		if(!root) return;
		if(!root->left && !root->right) res.push_back(root->val);
		printLeaves(root->left, res);
		printLeaves(root->right, res);
	}

	void printLeft(TreeNode *root, std::vector<int> &res) {
		if(!root) return;
		res.push_back(root->val);
		if(!root->left) {
			printLeft(root->right, res);
		}else{
			printLeft(root->left, res);	
			printLeaves(root->right, res);		    
		}
	}

	void printRight(TreeNode *root, std::vector<int> &res) {
		if(!root) return;
		if(!root->right) {
			printRight(root->left, res);
		}else{
			printLeaves(root->left, res);
			printRight(root->right, res);
		}
		
		res.push_back(root->val);
	}

	vector<int> boundaryOfBinaryTree(TreeNode * root) {
		std::vector<int> res;
		if(!root) return res;
		res.push_back(root->val);
		printLeft(root->left, res);
		printRight(root->right, res);
		return res;
	}
};	
