#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int no;
    int xior =0;
    int a[1000005];
    for(int i=0;i<n;i++)
    {
        cin>>no;
        a[i]=no;
        xior = xior^no;

    }
    int temp = xior;
    int pos=0;
    while((temp &1)!=1)
    {
        pos++;
        temp = temp>>1;
    }
    // mask = 1<< pos ==2;
    // ==100
    int mask = (1<<pos);
    int x =0;
    int y=0;
    for(int i=0;i<n;i++)
    {
        if((a[i]& mask)>0)
        {
            x = x^a[i];
        }

    }
    y = xior^x;

cout<<min(x,y)<<" "<<max(x,y);

return 0;

}