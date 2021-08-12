#include<bits/stdc++.h>
using namespace std;
// Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
// Output: 1
// Explanation: 
// - Friend 0 arrives at time 1 and sits on chair 0.
// - Friend 1 arrives at time 2 and sits on chair 1.
// - Friend 1 leaves at time 3 and chair 1 becomes empty.
// - Friend 0 leaves at time 4 and chair 0 becomes empty.
// - Friend 2 arrives at time 4 and sits on chair 0.
// Since friend 1 sat on chair 1, we return 1.

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        int n= times.size();
         // total number of friends
        set<int>s; 
        // use to store the current chair easily
       int f= times[targetFriend][0]; 
       //arival time of the target friend
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        // to get the minimum leaving time at the top so that we can compare that with thr upcoming friends arrival time and if upcoming time > than the leaving time in priority queue so we will pop the friend
        

        sort(times.begin(),times.end()); 
        // first come first server basis

        int n1=0; 
        // chair allocated to the first friend initially


        for(int i=0;i<n;i++)
        {
            int cs;
            // current seat
            int at = times[i][0];
            int lt = times[i][1];

            while(!pq.empty() and pq.top().first <= at)
            {
                s.insert(pq.top().second);
                // minimum element in priority queue top is less than the arrival time of the upcoming frined so we will pop 
                // set -> insert new top

                pq.pop();
            }
            if(s.size()!=0)
            {
              cs =* (s.begin());
              s.erase(s.begin());

            }else
            {
                cs=n1;
                n1++;
            }
            pq.push({lt,cs});
            if(f==at) // arrival time of target friend is equal to arival time 
            {
                return cs;
            }
        }
        return 0;

        
    }
};
