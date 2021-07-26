#include<bits/stdc++.h>
using namespace std;

bool ispal(char a[])
{
    int i=0;
    int j= strlen(a)-1;

    while(i<j)
    {
        if(a[i]==a[j]) 
        {j--,i++;
        }
        else 
        {return false;}


    }
    return true;
}

int main()
{
    char a[1000];
    cin.getline(a,1000);
    if(ispal(a))
    {
        cout<<"Palindromic"<<endl;
    }else{

        cout<<" not Palindromic"<<endl;
    }
    return 0;
}