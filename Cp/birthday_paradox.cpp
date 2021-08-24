#include<bits/stdc++.h>
using namespace std;
int main()
{
    float x =1.0;
    int people =0;
    float num=365;
    float denom = 365;
    float p ;
    while(x > 1-p)
    {
        // x is less then the threshold
        // p =
        // x>40%
        x = x*(num)/denom;
        num--;
        people++;
        cout<<"People "<<people<<" and "<<x<<endl;
    }


    return 0;
}