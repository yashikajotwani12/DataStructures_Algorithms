#include<bits/stdc++.h>
using namespace std;

class twostacks{
    int *arr;
    int size;
    int top1,top2;

    public:
    twostacks(int n)
    {
        size=n;
        arr= new int[n];
        top1=-1;
        top2=size;

    }
    void push1(int x)
    {
        if(top1 < top2-1)
        {
            top1++;
            arr[top1]=x;
        }
        else
        {
            cout<<"stack overflow"<<endl;
            exit(1);
        }
    }
    void push2(int x)
    {
        if(top1 < top2-1)
        {
            top2--;
            arr[top2]=x;
        }
        else
        {
            cout<<"stack overflow"<<endl;
            exit(1);
        }
    }
    int pop1()
    {
        if(top1 >=0)
        {
            int x= arr[top1];
        top1--;
        return x;

        }else
        {
            cout<<"Stack underflow"<<endl;
            exit(1);
        }
        


    }
    int pop2()
    {
        if(top2 <size)
        {
            int x= arr[top2];
        top2++;
        return x;

        }else
        {
            cout<<"Stack underflow"<<endl;
            exit(1);
        }

    }

};

int main()
{
    twostacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is "
         << ts.pop1();
    ts.push2(40);
    cout << "\nPopped element from stack2 is "
         << ts.pop2();
    return 0;
}