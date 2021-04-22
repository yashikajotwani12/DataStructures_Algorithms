#include<iostream>

#include<stdlib.h>
using namespace std;
class stacks{
   public:
    static const int max=100;
    int arr[max];
    int top;
  
    stacks()
    {top=-1;}
    bool isempty();
    bool isfull();
    int pop();
    void push(int x);   
};

bool stacks :: isfull()
{
    if(top ==max-1)
    return true;

    return false;
}
bool stacks::isempty()
{
    if(top==-1)
    return true;

    return false;
}
int stacks::pop()
{
    if(isempty())
    {
        cout<<"stack underflow";
        abort();
    }
    int x= arr[top];
    top--;
    return x;
}
void stacks::push(int x)
{
    if(isfull())
    {
        cout<<"stack overflow";
        abort();
    }
    top++;
    arr[top]=x;
}
class specialstack : public stacks{
    stacks min;
    public:
    int pop();
    void push(int x);
    int getmin();
};
void specialstack::push(int x)
{
    if(isempty()==true)
    {
        stacks::push(x);
        min.push(x);
    }
    else{
        stacks::push(x);
        int y = min.pop();
        min.push(y);
        if(x<y)
        min.push(x);
        else
        min.push(y);


    }
}
int specialstack::pop()
{
    int x=stacks::pop();
    min.pop();
    return x;
}
int specialstack::getmin()
{
    int x=min.pop();
    min.push(x);
    return x;
}
int main()
{
    specialstack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.getmin() << endl;
    s.push(5);
    cout << s.getmin();
    return 0;
}