#include<iostream>
#include<unordered_map>
using namespace std;

void countfreq(int arr[], int n)
{
    unordered_map<int , int>map;
    for(int i=0;i<n;i++)
    {
        map[arr[i]]++;
    }
    int cumulatives=0;
    for(int i=0;i<n;i++)
    {
        cumulatives+=map[arr[i]];

        if(map[arr[i]])
        {
            cout<<arr[i]<<"->" << cumulatives << endl;
        }
        map[arr[i]]=0;
   }
}
int main() 
{ 
    int a[] = {1, 3, 2, 4, 2, 1}; 
    int n = sizeof(a)/sizeof(a[0]); 
    countfreq(a, n); 
    return 0; 
} 