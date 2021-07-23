#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*left;
    Node*right;
    int data;
};

Node*newnode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right =NULL;
    return node;
}
// st =0 end= len-1
Node*buildtree(vector<int>&A, vector<int>&B, int start, int end, unordered_map<int , int>&m)
{
    int p =0;
    if(start > end) return NULL;
    // int current = A[index++];
    Node* node = newnode(A[p++]);
    if(start == end) return node;
    int index = m[A[p++]];

    node->left = buildtree(A,B,start,index-1,m);
    node->right = buildtree(A,B,index+1,end,m);
    return node;
}

Node*buildtreeutil(vector<int>&A, vector<int>&B, int len)
{
    unordered_map<int,int>m;
    for(int i=0;i<len;i++)
    {
        m[B[i]]=i;
    }
    return buildtree(A,B,0,len-1,m);
}
void printInorder(struct Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%c ", node->data);
    printInorder(node->right);
}
int main()
{
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(in) / sizeof(in[0]);
 
    struct Node* root = buildtreeutil(in, pre, len);
 
    /* Let us test the built tree by printing
      Inorder traversal */
    printf("Inorder traversal of the constructed tree is \n");
    printInorder(root);
}