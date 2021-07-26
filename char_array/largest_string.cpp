// largest string out of n strings
// we will store largest string and we will store the curr string

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    char a[1000];
    char largest[1000];
    int len=0;
    int largestlen=0; 
    cin.get(); // imp 
    for(int i=0;i<n;i++)
    {
        cin.getline(a,1000);
        // cout<<a<<endl;
        len = strlen(a);
        if(len > largestlen)
        {
            largestlen =len;
            strcpy(largest,a);
        }
    }
    cout<<largest<<" and "<<largestlen<<endl;
    return 0;
}
