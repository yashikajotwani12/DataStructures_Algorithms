// Actually, the two sticks in a pair of chopsticks need not be of the same length. A pair of sticks can be used to eat as long as the difference in their length is at most D. The Chef has N sticks in which the ith stick is L[i] units long. A stick can't be part of more than one pair of chopsticks. Help the Chef in pairing up the sticks to form the maximum number of usable pairs of chopsticks.


// 5 2
// 1
// 3
// 3
// 9
// 4

// Output:
// 2

// The 5 sticks have lengths 1, 3, 3, 9 and 4 respectively. The maximum allowed difference in the lengths of two sticks forming a pair is at most 2. It is clear that the 4th stick (length 9) cannot be used with any other stick. The remaining 4 sticks can can be paired as (1st and 3rd) and (2nd and 5th) to form 2 pairs of usable chopsticks.


#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    int i;
   for( i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   sort(arr,arr+n);
   int ans=0;
   for( i=0;i<n-1;i++)
   {
       if(arr[i+1]-arr[i] <= k)
       {

           
           ans++;
           i++;
       }
   }
   cout<<ans<<endl;
   return 0;
}