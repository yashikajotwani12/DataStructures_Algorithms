#include<bits/stdc++.h>
using namespace std;

void printb(int num)
{
    for(int i=10;i>=0;i--)
    {
        cout<<((num>>i)&1);
    }
    cout<<endl;
}
int main()
{
    int a=17;
    printb(16);
    printb(a);
    cout<<  __builtin_popcount(16)<<endl;
   if(a &(1<<4))
   {
       cout<<"bit set\n";
   }else{
       cout<<"not set";
   }
   // set bit
    printb(a | (1<<3));
    // bit unset
    printb(a & (~(1<<3)));
    //toggle
    printb(a ^ (1<<8));
    return 0;

}