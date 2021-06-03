#include<bits/stdc++.h>
using namespace std;
#define MAX 1000



void deletemiddle(stack<int>& inputstack, int N)
{
    stack<int> tempsatck;
    int count=0;
    while(count < N/2)
    {
        tempsatck.push(inputstack.top());
        inputstack.pop();
        count++;
    }
    inputstack.pop();
    while(!tempsatck.empty())
    {
        inputstack.push(tempsatck.top());
        tempsatck.pop();
    }
}
int main()
{
    stack<int>st;
    st.push(83);
    st.push(74);
    st.push(67);
    st.push(49);
    st.push(8);
    st.push(11);
    st.push(1);
    deletemiddle(st,7);
    for(int i=0;i<7;i++)
    {
         cout<<st.top()<<" ";
         st.pop();


    }
    return 0;
  

}