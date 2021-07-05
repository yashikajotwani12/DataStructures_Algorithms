// inc 1 2 3 4 5 
// dec 5 4 3 2 1 
// write a rec func in which 5 print then 4 3 2 1 is done recursively

#include<bits/stdc++.h>
using namespace std;

void dec(int n)
{
    if(n==0){
        return;
    }
    cout<<n<<" ";
    dec(n-1);

}
void inc(int n)
{
    if(n==0)
    {
        return;
    }
    inc(n-1);
    cout<<n<<" ";
}
int main()
{
    int n;
    cin>>n;
    dec(n);
    cout<<endl;
    inc(n);
    return 0;
}