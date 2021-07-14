#include<bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
    }
 };

void rightview(BinaryTreeNode<int>*root, int level, int *maxlevel, vector<int>&ans)
{
    // base case
    if(root ==NULL)
    {
        return;
    }
    // if currentlevel is more than the max level it means
    // this is the rightmost node
    if(*maxlevel < level)
    {
        ans.push_back(root->data);
        *maxlevel = level;
    }


    // recursive case
    rightview(root->right,level+1,maxlevel,ans);
    rightview(root->left,level+1,maxlevel,ans);

}
vector<int> printRightView(BinaryTreeNode<int>* root) {
    int maxlevel=0;
    vector<int>ans;
    rightview(root,1,&maxlevel, ans);

    // Write your code here.
    return ans;
}