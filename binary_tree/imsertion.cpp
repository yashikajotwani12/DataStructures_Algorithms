#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node*left;
    struct node*right;

};
node*createnode(int data)
{
    struct node*newnode=new node();
    if(!newnode)
    {
        cout<<"memory error\n";
        return NULL;
    }
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
node*insertnode(node* root, int val)
{
    if(root==NULL)
    {
        root=createnode(val);
        return root;
    }
    queue<node*>q;
    q.push(root);
   while(!q.empty())
   {
       node*temp=q.front();
       q.pop();
       if(temp->left!=NULL)
       {
           q.push(temp->left);

       }else{
           temp->left=createnode(val);
           return root;     
             }


      if(temp->right!=NULL)
      {
          q.push(temp->right);

      }else{
          temp->right=createnode(val);
          return root;
      }

   }



}
void inorder(node*temp)
{
    if(temp==NULL)
    return ;

    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
}
int main()
{
    node* root = createnode(10);
    root->left = createnode(11);
    root->left->left = createnode(7);
    root->right = createnode(9);
    root->right->left = createnode(15);
    root->right->right = createnode(8);
 
    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;
 
    int key = 12;
    root = insertnode(root, key);
 
    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;
 
    return 0;
}