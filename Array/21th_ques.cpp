#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
bool subarraysum(int arr[], int n)
{
    unordered_set<int>sumset;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==0 || sumset.find(sum)!=sumset.end())
        {
            return true;

    
        }
        sumset.insert(sum);
    }
    return false;


}
int main()
{
    int arr[]={-3,2,3,1,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    if(subarraysum(arr,n))
    {
        cout<<"Found"<<endl;
    }else{
        cout<<"Not found"<<endl;
    }
    return 0;
}