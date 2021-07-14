#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
         int hsh1[26]={0};
         int hsh2[26]={0};
         
         for(int i=0;i<s.length();i++){
             hsh1[s[i]-'a']++;
         }
        
         for(int i=0;i<t.length();i++){
             hsh2[t[i]-'a']++;
         }
        
         for(int i=0;i<26;i++){
            if(hsh1[i] != hsh2[i]){
               return false;
            }
         }
        
        return true;
    }
};