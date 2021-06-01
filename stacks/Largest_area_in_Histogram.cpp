#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n),right(n);
        
        stack<int> mystack;
        for(int i=0;i<n;++i)    //Fill left
        {
            if(mystack.empty())
            {    left[i] = 0;   mystack.push(i);    }
            else
            {
                while(!mystack.empty() and heights[mystack.top()]>=heights[i])
                    mystack.pop();
                left[i] = mystack.empty()?0:mystack.top()+1;
                mystack.push(i);
            }
        }
        while(!mystack.empty()) //Clear stack
            mystack.pop();
        
        for(int i=n-1;i>=0;--i) //Fill right
        {
            if(mystack.empty())
            {   right[i] = n-1; mystack.push(i);    }
            else
            {
                while(!mystack.empty() and heights[mystack.top()]>=heights[i])
                    mystack.pop();
                right[i] = mystack.empty()?n-1:mystack.top()-1;
                mystack.push(i);
            }
        }
        int mx_area = 0;    //Stores max_area
        for(int i=0;i<n;++i)
            mx_area = max(mx_area,heights[i]*(right[i]-left[i]+1));
        return mx_area;
    }
};