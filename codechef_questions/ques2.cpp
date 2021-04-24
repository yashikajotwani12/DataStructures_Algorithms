#include <bits/stdc++.h>
using namespace std;
#define long long int int

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	          int u,v,a,s;
	          cin>>u>>v>>a>>s;
	          int res;
	          if(u <= v)
	          {
	                    cout<<"Yes"<<endl;
	          }else if(u!=v)
	          {
	                 res=sqrt((u*u) - (2*a*s));
	                 res= lround(res);
	                 if(res <= v)
	                 {
	                           cout<<"Yes\n";
	                 }else
	                 {
	                           cout<<"No\n";
	                 }
	          }
	}
	return 0;
}