#include<bits/stdc++.h>
using namespace std;

class twostack{
    int *arr;
    int size;
    int top1;
    int top2;
    public:
    twostack(int n)
    {
        size=n;
        arr= new int(n);
        top1= n/2+1;
        top2=n/2;
    }
    void push1(int x)
    {
        if(top1 > 0)
        {
            top1--;
            arr[top1]=x;
        }else{
            cout<<"Stack overflow "<<"By element "<<x<<endl;

        }
    }
    void push2(int x)
    {
        if(top1 < size-1)
        {
            top2++;
            arr[top2]=x;
        }else{
            cout<<"Stack overflow "<<"By element "<<x<<endl;

        }
    }
    int pop1()
    {
        if(top1 <=size/2)
        {
            int x=arr[top1];
            top1++;
            return x;
        }else{
            cout<<"Stack Underflow";
            exit(1);
        }
    }
    int pop2()
    {
        if(top2 >=size/2+1)
        {
            int x=arr[top1];
            top1++;
            return x;
        }else{
            cout<<"Stack Underflow";
            exit(1);
        }
    }

};
int main()
{
    twostack ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout<<" POpped element from stack1 is "<<":"<<ts.pop1()<<endl;
    ts.push2(40);
    cout<<" POpped element from stack1 is "<<":"<<ts.pop2()<<endl;
    return 0;
}