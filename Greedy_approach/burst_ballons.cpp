#include<bits/stdc++.h>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int i=0,count=0,currend;
        while(i<points.size()){
            currend=points[i][1];
            i++;
            while(i<points.size()&&points[i][0]<=currend){
                currend=min(currend,points[i][1]);
                i++;
            }
            count++;
        }
        return count;
    }