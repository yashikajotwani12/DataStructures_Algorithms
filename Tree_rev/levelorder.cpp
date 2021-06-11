#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }

};


/*
         1 
       /   \
      2    3  
    / \   /  \
   5  6   7   8   
*/

void levelorder(Node*root)
{
    
}