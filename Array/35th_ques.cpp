#include<bits/stdc++.h>
using namespace std;
class Solution{
    vector<int> spiralorder(const vector<vector<int>>&a);

};

vector<int>Solution :: spiralorder(const vector<vector<int>>&a)
{
    int t,b,l,r,dir;
    t=0;
    b=a.size();
    l=0;
    r=a[0].size();
    int i;
    vector<int> ans;
    while(t<=b && l<=r)
    {
        if(dir==0)
        {
            for(i=l;i<=r;i++)
            {
                ans.push_back(a[t][i]);
            }
            t++;
        }
        if(dir==1)
        {
            for(i=t;i<=b;i++)
            {
                ans.push_back(a[i][r]);
            }
            r--;
        }
        if(dir==2)
        {
            for(i=r;i>=l;i--)
            {
                ans.push_back(a[b][i]);
            }
            b--;
        }
        if(dir==3)
        {
            for(i=b;i>=t;i--)
            {
                ans.push_back(a[i][l]);
            }
            l++;
        }
        dir=(dir+1)%4;
    }
    return ans;

}
// int main()
// {
//     int arr[][]={{

//     }}
// }