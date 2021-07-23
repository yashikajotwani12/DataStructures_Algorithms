#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode*left,*right;

};
TreeNode*getnode(int val)
{
   TreeNode*temp = new TreeNode;
   temp->val = val;
   temp->left=temp->right =NULL;
   return temp;


}
class Solution{
    public:

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n= preorder.size();
        if(n==0) return NULL;
        
    }

};

int main()
{
    return 0;
}