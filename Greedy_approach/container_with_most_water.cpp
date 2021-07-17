#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, l = 0, r = height.size() - 1;
        while(l < r){
            ans = max(ans, min(height[l], height[r])*(r - l));
            height[l] < height[r] ? l++ : r--;
        }
        return ans;
    }
};