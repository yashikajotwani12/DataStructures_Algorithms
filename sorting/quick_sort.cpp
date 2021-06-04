#include <bits/stdc++.h>
using namespace std;

int partition_fun(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; i++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[r], arr[i + 1]);

    return i + 1;
}
void quicksort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partition_fun(arr, l, r);
        quicksort(arr, l, pi - 1);
        quicksort(arr, pi + 1, r);
    }
}

int main()
{
    int arr[] = {2, 33, 4, 1, 188, 7, 54, 3, 22};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}