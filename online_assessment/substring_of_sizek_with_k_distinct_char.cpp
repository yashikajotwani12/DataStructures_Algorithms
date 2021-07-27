
// Sithis's avatar
// Sithis
// Moderator
// 17339
// Last Edit: October 20, 2019 4:48 PM

// 53.7K VIEWS

// Given a string s and an int k, return all unique substrings of s of size k with k distinct characters.

// Example 1:

// Input: s = "abcabc", k = 3
// Output: ["abc", "bca", "cab"]
// Example 2:

// Input: s = "abacab", k = 3
// Output: ["bac", "cab"]
// Example 3:

// Input: s = "awaglknagawunagwkwagl", k = 4
// Output: ["wagl", "aglk", "glkn", "lkna", "knag", "gawu", "awun", "wuna", "unag", "nagw", "agwk", "kwag"]
// Explanation: 
// Substrings in order are: "wagl", "aglk", "glkn", "lkna", "knag", "gawu", "awun", "wuna", "unag", "nagw", "agwk", "kwag", "wagl" 
// "wagl" is repeated twice, but is included in the output once.
// Constraints:

// The input string consists of only lowercase English letters [a-z]
// 0 ≤ k ≤ 26
#include<bits/stdc++.h>
#define inf 100000000000000
using namespace std;
#define ll long long int
int dx[4]={0,1,-1,1};
int dy[4]={1,0,0,1};

void find(string s,int k)
{
    int n=s.size();
   string sa;
    set<string>st;
    int hash[26]={0};
    int j=0;
    for(int i=0;i<n;i++)
    {
        hash[s[i]-'a']++;
        if(hash[s[i]-'a']>1)
        {
            while(s[j]!=s[i])
            {
                hash[s[j]-'a']--;
                j++;
            }
            hash[s[j]-'a']--;
            j++;
        }
        if(i-j+1>k)
        {
            hash[s[j]-'a']--;
            j++;
        }
        if(i-j+1==k)
        {
            string sa=s.substr(j,i-j+1);
            if(st.find(sa)==st.end())
            {
                st.insert(sa);
                cout<<sa<<" ";
            }
        }
    }
}
int main()
{
   
        int k;
    string s;
    cin>>s;
    cin>>k;
    find(s,k);
    
    
}