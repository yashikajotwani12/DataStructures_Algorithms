#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int size = s.size();
        if(size == 1) return 1;

        unordered_map<char, int>mp;
        int ans=0;
        for(int i=0;i<size;i++)
        {
            mp[s[i]]++;
        }
        for(auto i :mp)
        {
            if(i.second > 1)
            {
              ans+=i.second;
              if(i.second%2!=0)
              {
                  ans--;
              }
            }

        }
        if(ans!=size)
        {
            return ans+1;
        }else{
            return ans;
        }
    }
};