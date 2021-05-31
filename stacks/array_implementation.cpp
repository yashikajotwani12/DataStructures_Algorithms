#include<iostream>
using namespace std;
#define n 7

class Stack{
    int*arr;
    int top;
    public:
    Stack()
    {
        arr= new int[n];
        top=-1;
    }
    void push(int x)
    {
        if(top==n-1)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top]=x;

    }
    int pop()
    {
        if(top==-1)
        {
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        top--;
    }
    int Top()
    {
        if(top==-1)
        {
            cout<<"No element in stack"<<endl;
            return -1;
        }
        return arr[top];

    }
    bool empty()
    {
        return top==-1;
    }


};
int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
   cout<< st.empty();
    return 0;
}
