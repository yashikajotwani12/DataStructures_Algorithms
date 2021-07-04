// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.


// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Output: Because nums[0] + nums[1] == 9, we return [0, 1].

// brute force approach is to use two for loops tc (o(n^2))
// use two pointers approach with sorting :
// first sort the array and then two pointers i and j
// such that arr[i] + arr[j] > k then decrement j else inc i
// tc is o (nlog n)
// efficient approach is using hashmaps
// construct a empty hashmap then traverse the array

#include<bits/stdc++.h>
using namespace std;
vector<int>twosum(vector<int> &nums , int target)
{
    vector<int>result;
    unordered_map<int , int>mp;

    for(int i=0;i<nums.size();i++)
    {
        if(mp.find(target-nums[i])!=mp.end())
        {
            result.push_back(mp.find(target-nums[i])->second);
            result.push_back(i);

        }else{
            mp.insert(make_pair(nums[i],i));
        }

    }
    return result;

}

int main()
{
    vector<int>arr={0,-1,2,-3,1};
  int x=-2;
  vector<int>ans;
  ans=twosum(arr,x);
  for(auto x:ans)
  {
      cout<<x<<endl;
  }

return 0;

}
