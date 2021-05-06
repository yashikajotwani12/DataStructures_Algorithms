#include<bits/stdc++.h>
using namespace std;

bool issubset(int arr1[], int arr2[], int m , int n)
{
    set<int> hashset;
    for(int i=0;i<m;i++)
    {
        hashset.insert(arr1[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(hashset.find(arr2[i]) == hashset.end())
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int arr1[]={11,1,13,21,3,7};
    int arr2[]={11,3,7,1};
    int m= sizeof(arr1)/sizeof(arr1[0]);
    int n= sizeof(arr2)/sizeof(arr2[0]);
    if(issubset(arr1,arr2,m ,n ))
    {
        cout<<"arr2 is a subset "<<"\n";
    }else{
          cout<<"arr2 is  not a subset "<<"\n";
        
    }
    return 0;
}