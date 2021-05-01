#include<bits/stdc++.h>
using namespace std;

float getmin(int arr[], int n)
{
    return *min_element(arr, arr+n);
}
float getmax(int arr[], int n)
{
    return *max_element(arr, arr+n);
}
void randc(int arr[], int n)
{
    float min= getmin(arr,n);
    float max= getmax(arr,n);
    float range= max-min;
    float coeff = range/ (max+min);
    cout<<"range is "<<range<<endl;
    cout<<"coefficient is "<<coeff<<endl;
}
int main()
{
    int arr[]={5,10,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    randc(arr,n);
    return 0;

}