#include<bits/stdc++.h>
using namespace std;
void insertatbottom(stack<int>&st, int element)
{
    if(st.empty())
    {
        st.push(element);
        return;
    }
    int topelement = st.top();
    st.pop();
    insertatbottom(st,element);
    st.push(topelement);
}
void reverse_stack(stack<int>&st)
{
    if(st.empty())
    {
        return ;
    }
    int element=st.top();
    st.pop();
    reverse_stack(st);
    insertatbottom(st,element);


}
int main()
{
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverse_stack(st);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;

}