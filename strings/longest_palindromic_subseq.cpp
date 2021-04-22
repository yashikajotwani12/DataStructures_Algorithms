#include<bits/stdc++.h>
using namespace std;

void printsubstr(string s, int low, int high)
{
    for(int i=low;i<=high;i++)
    {
        cout<<s[i];
    }
}
//dynamic programming
int longestpalsubstr(string s)
{
     int n=s.size();

    bool table[9][9];

    memset(table,0,sizeof(table));
    int maxlen=1;

    for(int i=0;i<n-1;++i)
    {
        table[i][i]=true;
    }
    int start=0;
    for(int i=0;i<n-1;i++)
{
    if(s[i]==s[i+1])
    {
        table[i][i+1]=true;
        start=i;
        maxlen=2;
    }

}
for(int k=3;k<=n;k++)
{
    for(int i=0;i<n-k+1;i++)
    {
        int j=i+k-1;
        if(table[i+1][j-1]&& s[i]==s[j])
        {
            table[i][j]=true;

        
        if (k > maxlen) {
                    start = i;
                    maxlen = k;
                  }
        }
    }
}
 cout << "Longest palindrome substring is: ";
    printsubstr(s, start, start + maxlen - 1);
 
    // return length of LPS
    return maxlen;

}
int main()
{
    string str = "forgeeksskeegfor";
    cout << "\nLength is: "
         << longestpalsubstr(str);
    return 0;
}