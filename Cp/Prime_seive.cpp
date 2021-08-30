#include<bits/stdc++.h>
using namespace std;
void prime_seive(int*p)
{
    for(int i=3;i<=1000000;i+=2)
    {
        p[i]=1;
    }

    for(long long i=3;i<=1000000;i+=2)
    {
        if(p[i]==1)
        {
            for(long long j = i*i;j<=1000000;j+=i)
            {
                p[j]=0;
            }
        }

    }
    p[2]=1;
    p[1]=p[0]=0;


}
int main()
{
    int n;
    cin>>n;
    int p[1000005]={0};
    prime_seive(p);
    for(int i=0;i<=n;i++)
    {
        if(p[i]==1)
        {
            cout<<i<<" ";

        }
    }
    int csum[1000005]={0};
    for(int i=1;i<=1000000;i++)
    {
        csum[i]=csum[i-1]+p[i];
    }
    int q;
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        cout<<csum[b]-csum[a]<<endl;
    }

    return 0;
}