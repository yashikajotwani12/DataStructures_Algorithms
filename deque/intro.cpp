#include<bits/stdc++.h>
using namespace std;

int main()
{
    deque<int>dq;

    dq.push_back(5);
    dq.push_back(7);
    dq.push_front(6);
    dq.push_front(8);
    for(auto i :dq)
    {
        cout<<i<<" ";

    }
     cout<<endl;
     dq.pop_back();
      dq.pop_front();
      for(auto i :dq)
    {
        cout<<i<<" ";

    }
    cout<<endl;
    return 0;
}