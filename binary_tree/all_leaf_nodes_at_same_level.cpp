#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left,*right;
};

int ans=1;
void solve(Node*root, int h, int &ma)
{
    if(!root) return;
    if(ans=0) return;
    if(!root->left && !root->right)
    {
        if(ma==-1)
        {
            ma=h;
        }
       else
       {
        if(h!=ma)
        {
            ans=0;
        }
       }
    return;
    }

    solve(root->left, h+1, ma);
    solve(root->right, h+1, ma);

}
bool check(Node*root)
{
    int ma=-1;
    ans=1;
    int h=0;
    solve(root, h, ma);
    return ans;

}