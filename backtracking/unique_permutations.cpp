#include<bits/stdc++.h>
using namespace std;

void generator(vector<int> curr, vector<vector<int>> &result, int i, vector<int> A, map<vector<int>,int> &hash){
    if(curr.size()==A.size()){
        if(hash.find(curr)==hash.end()){
            result.push_back(curr);
            hash[curr]=1;
        }
        return;
    }
    else{
        for(int j=i;j<A.size();j++){
            curr.push_back(A[j]);
            swap(A[i],A[j]);
            generator(curr,result,i+1,A,hash);
            curr.pop_back();
        }
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> curr;
    vector<vector<int>> result;
    map<vector<int>,int> hash;
    generator(curr,result,0,A,hash);
    sort(result.begin(),result.end());
    return result;
}

// fast
void swap(vector<int> &A, int i, int j);
void permuteHelper(vector<int> &A,int start, vector<int> &help, vector<vector<int>> &permute);

vector<vector<int> > Solution::permute(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<int>> permute;
    vector<int> help;
    
    //std::sort(A.begin(), A.end());
    
    permuteHelper(A,0, help,permute);
    
    return permute;
}

void permuteHelper(vector<int> &A,int start, vector<int> &help, vector<vector<int>> &permute)
{
    if(start==A.size())
    {
        permute.push_back(help);
        return;
    }
    
    int j;
    bool found=false;
    
    for(int i=start; i<A.size(); i++)
    {
        for(j=start,found=false;j<i;j++)
        {
            if(A[j]==A[i])
            {
                found=true;
                break;
            }
        }
        
        if(found){continue;}
        
        
        help.push_back(A[i]);
        
        swap(A,i,start);
        permuteHelper(A,start+1, help,permute);
        swap(A,i,start);
        
        help.pop_back();
        
        /*while(i+1<A.size() && A[i+1]==A[i])
        {
            i++;
        }*/
    }
}

void swap(vector<int> &A, int i, int j)
{
    int temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}
