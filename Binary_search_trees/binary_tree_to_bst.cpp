#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left,*right;


    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};


int countnodes(Node*root)
{
    if(root==NULL) return 0;
    return countnodes(root->left)+countnodes(root->right)+1;
}


int compare(const void* a, const void *b)
{
    return (*(int*)a - *(int*)b);
}


void storeinorder(Node*node, int inorder[], int*index)
{
    if(node==NULL) return;

    storeinorder(node->left, inorder, index);
    inorder[*index] = node->data;
    (*index)++;
    storeinorder(node->left, inorder, index);

}

void arraytobst(int *arr, Node* root, int*index)
{
    if(root==NULL) return;
    arraytobst(arr, root->left, index);
    root->data= arr[*index];
   (*index)++;
    arraytobst(arr, root->right, index);
}


void bt_to_bst(Node*root)
{
    if(root==NULL) return;

    int n=countnodes(root);
    int*arr = new int[n];
    int i=0;
    storeinorder(root, arr, &i);
    qsort(arr, n,sizeof(arr[0]),compare);

    i=0;
    arraytobst(arr, root,&i);

    delete[] arr;

}


void printInorder(Node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    printf("%d ", node->data);
 
    /* now recur on right child */
    printInorder(node->right);
}
 
/* Driver function to test above functions */
int main()
{
     Node* root = NULL;
 
    /* Constructing tree given in the above figure
        10
        / \
        30 15
    /     \
    20     5 */
    root = new Node(10);
    root->left = new Node(30);
    root->right = new Node(15);
    root->left->left = new Node(20);
    root->right->right = new Node(5);
 
    // convert Binary Tree to BST
     printInorder(root);
     cout<<endl;
    bt_to_bst(root);
 
    printf("Following is Inorder Traversal of the converted BST: \n");
    printInorder(root);
 
    return 0;
}