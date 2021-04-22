#include<iostream>
#include<unordered_map>
using namespace std;

int minoperations(int arr[], int n)
{
    unordered_map<int, int>hashed;

    for(int i=0;i<n;i++)
    {
        hashed[arr[i]]++;

    }
    int maxcount=0;
    for(auto i:hashed)
    {
        if(maxcount<i.second)
        maxcount=i.second;

    }

  return (n-maxcount);
}
int main() 
{ 
    int arr[] = {1, 5, 2, 1, 3, 2, 1}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << minoperations(arr, n); 
    return 0; 
}  