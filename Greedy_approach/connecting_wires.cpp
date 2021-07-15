#include<bits/stdc++.h>
using namespace std;
int connect(int white[], int black[], int m , int n)
{
    sort(white,white+m);
    sort(black,black+m);

    int i=0,j=0;
    while(i<m and j<n)
    {
        
    }

}

int main()
{
    int white[]={0,4,5};
    int black[]={0,2,3};
    int m = sizeof(white)/sizeof(white[0]);
    int n = sizeof(black)/sizeof(black[0]);
    int ans = connect(white,black, m, n);
    cout<<ans;


    return 0;
}