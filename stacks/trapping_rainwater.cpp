#include<bits/stdc++.h>
using namespace std;

class Sloution{
    public:
    int trap(vector<int>& height)
    {
        int n=height.size();
        int maxleft =height[0];
        int maxright =height[n-1];
        int trappedwater=0;
        int left = 1;
        int right = n-2;
        while(left <= right)
        {
            if(maxleft < maxright)
            {
                if(height[left] >= maxleft)
                {
                    maxleft =height[left];
                }
               else{
                  trappedwater +=maxleft -height[left];
                  left++;
                }
            }else{

                 if(height[right] > maxright)
                {
                    maxright =height[right];
                }
               else{
                  trappedwater +=maxright - height[right];
                  right++;
                }

            }
        }
        return trappedwater;

    }
};