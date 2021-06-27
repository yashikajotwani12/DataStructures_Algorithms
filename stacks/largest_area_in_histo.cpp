#include<bits/stdc++.h>
using namespace std;

int getMaxArea(int hist[], int n)
{
    stack<int>s;
    int maxarea=0;
    int tp;
    int area_with_top;

    int i=0;
    while(i<n)
    {
        if(s.empty() || hist[s.top()] <= hist[i])
        {
            s.push(i++);

        }else
        {
            tp=s.top();
            s.pop();
            area_with_top = hist[tp]*(s.empty()? i : i-s.top()-1);

            if(maxarea < area_with_top)
            {
                maxarea=area_with_top;
            }
        }
    }
    while(s.empty()==false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp]*(s.empty()?i:i-s.top()-1);
        if(maxarea < area_with_top)
            {
                maxarea=area_with_top;
               
            }
    }
    return maxarea;

}

int main()
{
     int hist[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(hist)/sizeof(hist[0]);
    cout << "Maximum area is " << getMaxArea(hist, n);
    return 0;
}