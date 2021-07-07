// friends pairing problem
// n friends, want to go to teh party on bikes , each guy can go as a single or couple
// find n no of ways in which n friends can go the party

// n=3
// ways =4
// 1 2 3 
// 1  1 1 
// all go alone 1 way

// in couples 3 ways 
// 12 3
// 23 1 
// 13 2
// total 4 ways

// bikes n 
#include<bits/stdc++.h>
using namespace std;

int bikes(int n)
{
    if(n==0) return 1;
    if(n==1) return 1;
    return bikes(n-1)+(bikes(n-2)*(n));
}
int main()
{
    int n;
    cin>>n;
   cout<< bikes(n);
    return 0;
}