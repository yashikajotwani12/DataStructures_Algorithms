#include<bits/stdc++.h>
using namespace std;


vector<long long int> productexceptself(vector<long long int> &nums, int n)
{
    vector<long long int> l(n),r(n);

    l[0]=1;
    r[n-1]=1;
    for(int i=1;i<n;i++)
    {
        l[i]= l[i-1]* nums[i-1];

    }
    for(int i=n-2;i>=0;i--)
    {
        r[i]=r[i+1]*nums[i+1];
    }
    for(int i=0;i<n;i++)
    {
        nums[i]=l[i]*r[i];

    }
    return nums;
}

int main()
{
   
    vector<long long int>nums;
    nums.push_back(10);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(2);
    int n=nums.size();
    productexceptself(nums,n);
    // vector<long long int>ans;
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}