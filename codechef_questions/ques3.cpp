//https://www.codechef.com/problems/MKSMEVN
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	          int n;
	          cin>>n;
	          int arr[n];
	          int sum=0;
	          int ans=0;
	          for(int i=0;i<n;i++)
	          {
	                    cin>>arr[i];
	                    sum+=arr[i];
	          }
	         
	          if(sum%2==0)
	          {
	                    cout<<'0'<<endl;
	          }else
	          {
	                    for(int i=0;i<n;i++)
	                    {
	                              if(arr[i]==2)
	                              {
	                                        ans=1;
	                                        break;
	                              }
	                    }
	                    if(ans==1)
	                    {
	                              cout<<'1'<<endl;
	                    }else
	                    {
	                              cout<<"-1"<<endl;
	                    }
	                     
	          }
	          
	}
	return 0;
}
