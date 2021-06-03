#include<bits/stdc++.h>
using namespace std;
vector<int> support(vector<int>arr, int n)
{
    stack<int>st;
    vector<int>ans;
    for(int i=0;i<arr.size();i++)
    {
       while(st.size() > 0 and st.top() >= arr[i])
       {
           st.pop();
       }
       if(st.size()==0)
       {
           ans.push_back(-1);
       }
       else{
           ans.push_back(st.top());
       }
       st.push(arr[i]);


    }
    return ans;
}

int main()
{
    vector<int>arr;
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(12);
    arr.push_back(10);
   vector<int>ans = support(arr,5);
   for(int i=0;i<ans.size();i++)
   {
       cout<<ans[i]<<" ";
   }

    return 0;
}