#include<bits/stdc++.h>
using namespace std;
bool campare(pair<int,int>p1, pair<int, int>p2)
{
    return p1.second<p2.second;
}

int main()
{
    int t,n,s,e;
    cin>>t;
    while(t--)
    {
        vector<pair<int,int>>v;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>s>>e;
            v.push_back(make_pair(s,e));
        }
        // sort acti acc the ending time
        sort(v.begin(),v.end(),campare);
        // start picking activities
        int res=1;
        int fin = v[0].second;

        for(int i=1;i<n;i++)
        {
            if(v[i].first >= fin)
            {
                fin= v[i].second;
                res++;
            }
        }
        cout<<res<<endl;

        v.clear();
    }

    return 0;
}