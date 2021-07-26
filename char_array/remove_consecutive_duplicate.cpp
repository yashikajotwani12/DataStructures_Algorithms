// skip the similiar chars , dont use extra array
// ccoooding ---> coding
#include<bits/stdc++.h>
using namespace std;

void removedup(char a[])
{
    
    int i=0;
    int j=i+1;
    int l = strlen(a);
    if( l ==1 or l==0) return;

    int prev=0;
    for(int curr =1;curr <l;curr++)
    {
        if(a[curr] != a[prev])
        {
            prev++;
            a[prev]= a[curr];
        }

    }
    a[prev+1] ='\0';
    return;

}
int main()
{
    char a[100];
    cin.getline(a,100);
    removedup(a);
    cout<<a<<endl;
    return 0;
}