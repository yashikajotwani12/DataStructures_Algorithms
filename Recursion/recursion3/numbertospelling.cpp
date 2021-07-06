#include<bits/stdc++.h>
using namespace std;

// problem
// number to spelling
// 2048 --> two zero four eight

char words[][10]={"zero","one","two","three", "four", " five","six","seven","eight","nine"};
void printspellings(int n)
{
    // base case
    if(n==0)
    {
        return;
    }
    // recur case 
    printspellings(n/10);
    
    int digit = n%10;
    cout<< words[digit]<<" ";
    return;


}

int main()
{
    int n;
    cin>>n;
    printspellings(n);
    return 0;
}