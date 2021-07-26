#include<bits/stdc++.h>
using namespace std;
void rotate(int a[][1000], int n)
{
    // reverse each row
    for(int row=0;row<n;row++)
    {
        reverse(a[row],a[row]+n);
    }

    // to take transpose
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i<j)
            {
                swap(a[i][j],a[j][i]);
            }
        }
    }
    
}
void display(int a[][1000], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

}
int main()
{
    int a[1000][1000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    rotate(a,n);
    display(a,n);
    return 0;
}