#include<bits/stdc++.h>
using namespace std;
int printint(int arr1[], int arr2[], int n , int m)
{
    int i=0;int j=0;
    while(i<n && j<m)
    {
        if(arr1[i] < arr2[j])
        {
         i++;
        }else if(arr1[i] > arr2[j])
        {
            j++;

        }
        else{
            cout<<arr2[j]<<" ";
            i++;
            j++;
        }
    }

}
// int printunion(int arr1[],int arr2[],  int n, int m)
// {
//     int i=0;
//     int j=0;
//         while(i <n && j <m)
//         {
//             if(arr1[i] < arr2[j])
//             {cout<<arr1[i++]<<" ";

//             }else if(arr1[i] > arr2[j])
//             {
//                 cout<<arr2[j++]<<" ";
//             }else{
//                 cout<<arr2[j++]<<" ";
//                 i++;
//             }
//         }
    
//     while(i<n)
//     {
//         cout<<arr1[i++]<<" ";

//     }
//     while(j<m)
//     {
//         cout<<arr2[j++]<<" ";
//     }

// }
int main()
{
    int arr1[]={1,3,4,5,7};
    int arr2[]={2,3,5,6};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    // printunion(arr1, arr2, n1, n2);
     printint(arr1, arr2, n1, n2);
    return 0;

}