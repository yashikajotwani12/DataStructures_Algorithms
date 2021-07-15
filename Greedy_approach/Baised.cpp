// spoj problem

// Suppose that we already have a ranklist. For each team, compute the distance between their preferred place and their place in the ranklist. The sum of these distances will be called the badness of this ranklist.

// Problem specification
// Given team names and their preferred placements find one ranklist with the minimal possible badness.

// Input specification
// The first line of the input file contains an integer T specifying the number of test cases. Each test case is preceded by a blank line.

// Each test case looks as follows: The first line contains N : the number of teams participating in the competition. Each of the next N lines contains a team name (a string of letters and numbers) and its preferred place (an integer between 1 and N, inclusive). No two team names will be equal.


// Input:
// 2

// 7
// noobz 1
// llamas 2
// Winn3rz 2
// 5thwheel 1
// NotoricCoders 5
// StrangeCase 7
// WhoKnows 7

// 3
// ThreeHeadedMonkey 1
// MoscowSUx13 1
// NeedForSuccess 1

// Output:
// 5
// 3


// 1. noobz
// 2. llamas
// 3. Winn3rz
// 4. 5thwheel
// 5. NotoricCoders
// 6. WhoKnows
// 7. StrangeCase

// #include <bits/stdc++.h>
// using namespace std;
// #define LL long long
// int main()
// {
//     int t;
//     scanf("%d",&t);
//     while(t--)
//     {
//         char name[1000];
//         int n,temp,pos=0;
//         LL sum=0;
//         scanf("%d ",&n);
//         int *arr;
//         arr = (int *)calloc(n+9,sizeof(int));
//         for(int i=0;i<n;i++)
//         {
//             scanf("%s%d",name,&temp);
//             arr[temp]++;
//         }
//         for(int i=1;i<=n;i++)
//         {
//             if(arr[i]){
//                 temp=pos+1;
//                 pos+=arr[i];
//                 while(temp<=pos)
//                 {
//                     sum+=(temp-i)<0?-1*(temp-i):(temp-i);
//                     temp++;
//                 }
//                 if(pos==n)
//                     break;
//             }
//         }
//         printf("%lld\n",sum);
//     }
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[100000]={0};
    int t,n;
    cin>>t;
    while(t--)
    {
        memset(arr,0,sizeof arr);
        string name;
        int n,rank;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>name>>rank;
            arr[rank]++;
        }

        // greedy = nearest rank available

        int actual_rank= 1;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            while(arr[i])
            {
                sum += abs(actual_rank - i);
                arr[i]--;
                actual_rank++;

            }
        }
        cout<<sum<<endl;
    }
}