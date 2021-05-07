#include <bits/stdc++.h>
using namespace std;

void combination_util(int arr[], int n, int r, int index, int data[], int i);

void printcombination(int arr[], int n, int r)
{
    int data[r];
    combination_util(arr, n, r, 0, data, 0);
}
void combination_util(int arr[], int n, int r, int index, int data[], int i)
{

    if (index == r)
    {
        for (int j = 0; j < r; j++)
        {
            cout << data[j] << " ";
        }
        cout << endl;
        return;
    }
    if(i>=n)
    return;

    data[index]=arr[i];
    combination_util(arr,n,r,index+1,data,i+1);


    combination_util(arr,n,r,index,data,i+1);

}
int main()
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int r=3;
    printcombination(arr,n,r);
    return 0;
}