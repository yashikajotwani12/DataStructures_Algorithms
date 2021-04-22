// #include<bits/stdc++.h>
// using namespace std;
// void greatestproduct(int arr[], int n )
// {
//     unordered_map<int , int>map;
//     for(int i=0;i<n;i++)
//     {
//         map[arr[i]]++;
//     }
//     sort(arr,arr+n);
//     for(int i=n-1;i>1;i--)
//     {
//         for(int j=0;j<i && arr[j]<=sqrt(arr[i]);j++)
//         {
//             if(arr[i]%arr[j]==0)
//             {
//                 int result=arr[i]/arr[j];

//                 if(result!=arr[j] && map[result]>0)
//                 // return arr[i];
//                 // else if(result==arr[j] &&map[result]>1)
//                 // return arr[i];
//             // }
//         }

//     }
//     // return -1;
// }
// int main() 
// { 
//     int arr[] = {17, 2, 1, 15, 30}; 
//     int n = sizeof(arr)/sizeof(arr[0]); 
//     cout << greatestproduct(arr, n); 
//     return 0; 
// } 