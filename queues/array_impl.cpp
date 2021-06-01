#include<iostream>
using namespace std;
#define n 10

class queue{
    public:
    int *arr;
    int front,back;
    queue()
    {
        arr = new int[n];
        front =-1;
        back=-1;

    }
    void push(int x)
    {
        if(back==n-1)
        {
            cout<<"queue overflow\n";
            return;
        }
        back++;
        arr[back]=x;

        if(front==-1)
        {
            front++;
        }

    }
    void pop()
    {
        if(front==-1 || front > back)
        {
            cout<<"queue underflow\n";
            return;
        }
        front++;
    }
    int peek()
    {
        if(front==-1 || front > back)
        {
            cout<<"queue underflow\n";
            return -1;
        }
        return arr[front];

    }
    bool empty()
    {
        if(front==-1 || front > back)
        {
            cout<<"queue underflow\n";
            return true;
        }
        return false;
    }
};
int main()
{
    queue q;
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    cout<<q.peek()<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<q.peek()<<endl;
    return 0;



}