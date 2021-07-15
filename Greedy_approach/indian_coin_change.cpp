#include<bits/stdc++.h>
using namespace std;

int make_change(int coins[], int n, int money)
{
    int ans=0;
    while(money > 0)
    {

    int index = upper_bound(coins,coins+n,money)- 1 - coins;
    // cout<<coins[index]<<"+";
    money = money - coins[index];
    ans++;

    }
    return ans;   
}

int main()
{
    int money;
    cin>>money;
    int coins[]={1,2,5,10,20,50,100,200,1000};
    int t = sizeof(coins)/sizeof(coins[0]);

   cout<<" No of coins needed "<< make_change(coins,t,money);
    return 0;
}