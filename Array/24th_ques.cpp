#include<bits/stdc++.h>
using namespace std;

int maxproduct(int arr[], int n)
{
    int max_ending=1;
    int min_ending=1;
    int maxsofar=0;
    int flag=0;

    for(int i=0;i<n;i++){
        if(arr[i] > 0)
        {
            max_ending= max_ending*arr[i];
            min_ending = min(min_ending*arr[i], 1);
            flag=1;

        }else if(arr[i]==0)
        {
            max_ending=1;
            min_ending=1;
        }else{
            int temp= max_ending;
            max_ending= max(min_ending*arr[i], 1);
            min_ending=temp*arr[i];
        }
        if(maxsofar < max_ending)
        {
            maxsofar= max_ending;
        }
       
    }
     if(maxsofar ==0 &&flag==0)
        {
            return 0;
        }


        return maxsofar;

}
int main()
{
    int arr[]={1,-2,-3,0,7,-8,-2};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<" ans is : "<<maxproduct(arr,n);
    return 0;
}