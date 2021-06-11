#include<bits/stdc++.h>
using namespace std;
int doublehelix(int arr1[], int arr2[], int n1, int n2)
{
    int ma=0;
    int s1=0,s2=0;
    int i=0,j=0;
    while(i<n1 and j<n2)
    {
        if(arr1[i] < arr2[j])
        {
            s1+=arr1[i];
            i++;
        }else if(arr2[j] < arr1[i])
        {
            s2+=arr2[j];
            j++;
        }else{

            ma= ma+max(s1,s2)+arr1[i];
            s1=0;
            s2=0;
            i++;
            j++;

        }
        while( i<n1)
        {
             s1+=arr1[i];
            i++;

        }
        while(j<n2)
        {
            s2+=arr2[j];
            j++;

        }
        ma = max(s1,s2) + ma;
    }
    return ma;

}
int main()
{
    int arr1[]={3,5,7,9,20,25,30,40,55,56,57,60,62};
    int arr2[]={1,4,7,11,14,25,44,47,55,57,100};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
   cout<< doublehelix(arr1,arr2,n1,n2)<<endl;
    return 0;
}