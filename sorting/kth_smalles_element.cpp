#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector<pair<int , int>>v;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            v.push_back({x,y});
        }
        sort(v.begin(),v.end());
        int idx=0;
        for(int i=1;i<v.size();i++)
        {
            if(v[idx].second >= v[i].first)
            {
                v[idx].second = max(v[idx].second, v[i].second);
            }else{
                idx++;
                v[idx]=v[i];
            }
        }
        while(q--)
        {
            int k;
            cin>>k;
            int ans= -1;
            for(int i=0;i<=idx;i++)
            {
                if((v[i].second - v[i].first +1)>=k)
                {
                    ans= v[i].first+k-1;
                }else{
                    k =k - (v[i].second - v[i].first +1);
                
                }
            }
            cout<<ans<<endl;



        }

    }
}