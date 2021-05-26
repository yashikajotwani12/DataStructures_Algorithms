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

Node* constructtreeutil(int pre[], int*preindex, int key, int min, int max, int size)
{
    //base case
    if(*preindex >= size) return NULL;

    Node* root =NULL;

    if(key > min && key < max)
    {
        root = new Node(key);
        *preindex = *preindex+1;

        if(*preindex < size)
        {

            root->left = constructtreeutil(pre, preindex, pre[*preindex], min, key, size);

        }
        if(*preindex < size)
        {

            root->right = constructtreeutil(pre, preindex, pre[*preindex], key, max, size);

        }
    }
    return root;




}
Node* constructTree(int pre[], int size)
{
    int preIndex = 0;
    return constructtreeutil(pre, &preIndex, pre[0],
                             INT_MIN, INT_MAX, size);
}

void printInorder(Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
 
// Driver code
int main()
{
    int pre[] = { 10, 5, 1, 7, 40, 50 };
    int size = sizeof(pre) / sizeof(pre[0]);
 
    // Function call
    Node* root = constructTree(pre, size);
 
    cout << "Inorder traversal of the constructed tree: \n";
    printInorder(root);
 
    return 0;
}