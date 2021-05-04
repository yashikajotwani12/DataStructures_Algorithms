#include<bits/stdc++.h>
using namespace std;
#define MAX 100

class stacks{
    int top;
    public:
    int a[MAX];

    stacks()
    {
         top=-1; 
    }
        bool push(int x);
        int pop();
        int peek();
        bool isempty();


};
bool stacks:: push(int x)
{
    if(top >= (MAX -1))
    {
        cout<<"Stack overflow";
        return false;

    }
    else{
        a[++top] = x;
        cout<<x<<" pushed into the stack \n";
    }
}
int stacks::pop()
{
    if(top < 0)
    {
        cout<<" Stack underflow\n";
        return 0;
    }else
    {
        int x=a[top--];
        return x;
    }
}
int stacks::peek()
{
    if(top < 0)
    {
        cout<<"stack is empty";
        return 0;
    }else
    {
        int x = a[top];
        return x;
    }
}

bool stacks :: isempty()
{
    return (top < 0);

}
int main()
{
    class stacks s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.pop()<<" popped from stack\n";
    cout<<"Elements present in stack : ";
    while(!s.isempty())
    {
        cout<<s.peek()<<" ";
        s.pop();

    }
    return 0;
}