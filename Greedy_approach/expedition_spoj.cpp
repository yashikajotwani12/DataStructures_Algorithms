// EXPEDI - Expedition
// #greedy

// A group of cows grabbed a truck and ventured on an expedition deep into the jungle. Being rather poor drivers, the cows unfortunately managed to run over a rock and puncture the truck's fuel tank. The truck now leaks one unit of fuel every unit of distance it travels.

// To repair the truck, the cows need to drive to the nearest town (no more than 1,000,000 units distant) down a long, winding road. On this road, between the town and the current location of the truck, there are N (1 <= N <= 10,000) fuel stops where the cows can stop to acquire additional fuel (1..100 units at each stop).

// The jungle is a dangerous place for humans and is especially dangerous for cows. Therefore, the cows want to make the minimum possible number of stops for fuel on the way to the town. Fortunately, the capacity of the fuel tank on their truck is so large that there is effectively no limit to the amount of fuel it can hold. The truck is currently L units away from the town and has P units of fuel (1 <= P <= 1,000,000).

// Determine the minimum number of stops needed to reach the town, or if the cows cannot reach the town at all.

// Input
// The first line of the input contains an integer t representing the number of test cases. Then t test cases follow. Each test case has the follwing form:

// Line 1: A single integer, N
// Lines 2..N+1: Each line contains two space-separated integers describing a fuel stop: The first integer is the distance from the town to the stop; the second is the amount of fuel available at that stop.
// Line N+2: Two space-separated integers, L and P
// Output
// For each test case, output a single integer giving the minimum number of fuel stops necessary to reach the town. If it is not possible to reach the town, output -1.

// Example
// Input:
// 1
// 4
// 4 4
// 5 2
// 11 5
// 15 10
// 25 10

// Output:
// 2

// Input details
// The truck is 25 units away from the town; the truck has 10 units
// of fuel.  Along the road, there are 4 fuel stops at distances 4,
// 5, 11, and 15 from the town (so these are initially at distances
// 21, 20, 14, and 10 from the truck).  These fuel stops can supply
// up to 4, 2, 5, and 10 units of fuel, respectively.

// Output details:
// Drive 10 units, stop to acquire 10 more units of fuel, drive 4 more
// units, stop to acquire 5 more units of fuel, then drive to the town




#include<bits/stdc++.h>
using namespace std;


bool compare(pair<int,int>p1, pair<int,int>p2)
{
    return p1.first > p2.first;
}

int main()
{
    int n, t,x, d, f, D, F, prev=0;
    cin>>t;
    while(t--)
    {
        int flag=0;
        int ans=0;
        // fuel stations with capacity
        vector<pair<int,int>>v;
        // to store the capacity of the fuel
        priority_queue<int>pq;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>d>>f;
            v.push_back(make_pair(d,f));
        }
        // logic
        sort(v.begin(),v.end(),compare);

        cin>>D>>F;

        // update the distance of the fuel station from the truck
        for(int i=0;i<n;i++)
        {
            v[i].first = D - v[i].first;
        }
        //prev denotes the prev city visited
        x= 0; // current city
        while(x < n)
        {
            // if we have enough fuel to go to next city
            if(F >= (v[x].first-prev))
            {
                F=F-(v[x].first - prev);
                pq.push(v[x].second);
                prev= v[x].first;

            }
            else{
                // check if you have some fueling stations 

                if(pq.empty())
                {
                    flag=1;
                    break;

                }
                // otherwise we can refueling stations with higher capacity

                F+= pq.top();
                // remove that station from pq
                pq.pop();
                ans=ans+1;
                continue;
            }
            x++;
           
        }
        // n stations reached
        // what is left you have to reach the town from the last fuel station
        if(flag==1)
        {
            cout<<-1<<endl;
            continue;
        }
        D = D-v[n-1].first;
        if(F>=D)
        {
            cout<<ans<<endl;
            continue;
        }
        while(F<D)
        {
            if(pq.empty())
            {
                flag=1;
                break;
            }

            F+=pq.top();
            pq.pop();
            ans= ans+1;
        }
        if(flag=1)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<ans<<endl;


    }
    return 0;


}