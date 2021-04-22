#include<bits/stdc++.h>
using namespace std;
bool findpairs(int arr[], int n)
{
    map<int, pair<int, int>>mapp;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            int sum=arr[i]+arr[j];
            if(mapp.find(sum)==mapp.end())
            {
                mapp[sum]=make_pair(i,j);
            }
            else{
                pair<int , int> pp=mapp[sum];
               cout << "(" << arr[pp.first] << ", " << arr[pp.second] 
                     << ") and (" << arr[i] << ", " << arr[j] << ")\n"; 
                return true; 
            }

        }
    }
    cout << "No pairs found"; 
    return false; 
}
int main() 
{ 
    int arr[] = {3, 4, 7, 1, 2, 9, 8}; 
    int n  =  sizeof arr / sizeof arr[0]; 
    findpairs(arr, n); 
    return 0; 
} 

