#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

bool checksum(int arr[], int n)
{
    int presum=0;
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        presum += arr[i];
        if(presum=0 or s.find(presum)!=s.end())
        {
            return true;

        }
        s.insert(presum);
    }
    return false;

}
int main()
{

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(checksum(arr,n))
    {
        cout<<"Yes"<<endl;
    }else
    {
        cout<<"No"<<endl;
    }



    return 0;

}