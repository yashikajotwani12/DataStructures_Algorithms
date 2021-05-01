#include<bits/stdc++.h>
using namespace std;
bool find(int arr[], int k, int x, int n)
{
    int i;
    for( i=0;i<n;i=i+k)
    {
        int j;
        for( j=0;j<k;j++)
        {
            if(arr[i+j] == x)
            {
                break;

            }
              if(j==k)
                return false;

        }

    }
    if(i==n)
    return true;


    int j;
    for(j=i-k;j<n;j++)
    {
        if(arr[j]==x)
        break;
        if(j==n)
        {
            return false;
        }
    }
    return true;
  
}
int main()
{
     int arr[] = { 3, 5, 2, 4, 9, 3, 1, 7, 3, 11, 12, 3 };
    int x = 3, k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    if (find(arr, x, k, n))
        cout << "Yes" << endl;
        
    else
        cout << "No" << endl;
    return 0;

}
