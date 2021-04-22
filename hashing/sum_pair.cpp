#include<iostream>
#include<unordered_set>
using namespace std;
void printpairs(int arr[], int n , int sum)
{
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        int temp =sum-arr[i];
        if(s.find(temp)!=s.end())
        {
            cout<<"Pair with given sum " << sum << " is ( " << arr[i] << "," << temp << ")" << endl;
        }
        else{
            s.insert(arr[i]);
        }

    }
}
int main()
{
    int arr[]={1, 4, 45, 6, 10, 8 };
    int n=6;
    int sum=16;
    printpairs(arr,n,sum);
    return 0;
}