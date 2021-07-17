// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.

//2 methods
// method 1 -> we will traverse and store the paths of n1 from root and n2 dfrom root and then we will traverse and see if the bot paths till the value is same and return the element just before the mismatch.,

// findpath

//method 2
// 1 traversal
// n1 or n2 == root root is lca
// traverse n1 is present and n2 is not present return false
// if n1 and n2 same side ie left subtree true lca return 
// and viceversa
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*left,*right;
    int data;
    Node(int data)
    {
        data=data;
        *left = NULL;
        *right =NULL;
    }

};
// v1 and v2 use ? bcoz if n1 not prsent so check and viceversa
// This function returns pointer to LCA of two given values n1 and n2.
// v1 is set as true by this function if n1 is found
// v2 is set as true by this function if n2 is found
Node*findlca(Node*root, int n1, int n2, bool &v1, bool &v2)
{
    if(root ==NULL) return NULL;
    if(root->data == n1) v1=true; return root;
    if(root->data== n2)  v2= true; return root;

    // look in the left and right subtrees
    Node*left = findlca(root->left, n1,n2,v1,v2);
    Node*right = findlca(root->right, n1,n2,v1,v2);

    // one key is present in one side and other key is present on other side // returning non null value
    if(left and right) return root;

    return (left !=NULL)? left:right;

}

bool find(Node*root, int k)
{
    if(root == NULL) return false;
    if(root->data == k || find(root->left,k) || find(root->right,k))
    {
        return true;
    }
    return false;
}


Node*lca(Node*root, int n1, int n2)
{
    bool v1= false,v2=false;
    Node*lca1=findlca(root,n1,n2,v1,v2);
    if(v1 and v2 or v1 and find(lca1,n2) or find(lca1,n1))
    return lca1;

     return NULL;
}
int main()
{
    // Let us create binary tree given in the above example
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Node *lca1 =  lca(root, 4, 5);
    if (lca != NULL)
       cout << "LCA(4, 5) = " << lca1->data;
    else
       cout << "Keys are not present ";
 
    lca1 =  lca(root, 4, 10);
    if (lca != NULL)
       cout << "nLCA(4, 10) = " << lca1->data;
    else
       cout << "nKeys are not present ";
 
    return 0;
}