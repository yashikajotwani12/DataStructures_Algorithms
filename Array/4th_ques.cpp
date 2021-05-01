//selection sort
#include<bits/stdc++.h>
using namespace std;
void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void selectionsort(int arr[], int n){
    int minindex;
    for(int i=0;i<n-1;i++)
    {
         minindex=i;
         for(int j=i+1;j<n;j++)
         {
             if(arr[j] < arr[minindex])
             {
                 minindex=j;
                 
             }
              swap(&arr[minindex],&arr[i]);
            
         }

    }
}
void printarray(int arr[], int n)
{
    for(int i=0;i <n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<" Before \n";
    printarray(arr,n);
    selectionsort(arr,n);
    cout<<"After \n";
    printarray(arr,n);

}