#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left, *right;
};
Node* getNode(int data)
{
    // allocate memory for the node
    Node* newNode = new Node();
  
    // put in the data
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void longestpath(Node*root, int len , int sum, int &maxlen, int &maxsum)
{
    if(!root)
    {
        if(maxlen < len)
        {
            maxlen=len;
            maxsum=sum;
        }else if(maxlen==len && maxsum < sum)
        {
            maxsum=sum;

        }
        return;
    }
    longestpath(root->left, len+1 , sum+root->data,maxlen ,maxsum );
    longestpath(root->right, len+1 , sum+root->data,maxlen ,maxsum );
}

int longestpathutil(Node*root)
{
    if(!root){
        return 0;
    }
    int maxsum=INT_MIN;
    int maxlen=0;
    longestpath(root, 0,0,maxlen,maxsum);
    return maxsum;
}
int main()
{
    // binary tree formation
    Node* root = getNode(4);         /*        4        */
    root->left = getNode(2);         /*       / \       */
    root->right = getNode(5);        /*      2   5      */
    root->left->left = getNode(7);   /*     / \ / \     */
    root->left->right = getNode(1);  /*    7  1 2  3    */
    root->right->left = getNode(2);  /*      /          */
    root->right->right = getNode(3); /*     6           */
    root->left->right->left = getNode(6);
  
    cout << "Sum = "
         << longestpathutil(root);
  
    return 0;
}