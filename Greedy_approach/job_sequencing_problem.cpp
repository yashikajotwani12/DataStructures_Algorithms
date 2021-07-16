#include<bits/stdc++.h>
using namespace std;

struct Job{
    char id;
    int deadline;
    int profit;
};
bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

void printJob(Job arr[], int n)
{
    sort(arr,arr+n,compare);
    int result[n]; // store the result
    bool slot[n]; // keeping track of free slots

    // initialize all slots to be free
    for(int i=0;i<n;i++)
    {
        slot[i]=false;
    }
  // iterate through all the jobs
    for(int i=0;i<n;i++)
    {
        for(int j= min(n,arr[i].deadline)-1; j>=0;j--)
        {
            if(slot[j]== false)
            {
                result[i]=i;
                slot[j]=true;
                break;
            }
        }

    }
    for (int i=0; i<n; i++)
       if (slot[i])
         cout << arr[result[i]].id << " ";



}

int main()
{
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs \n";
   
    // Function call
    printJob(arr, n);
    return 0;
}