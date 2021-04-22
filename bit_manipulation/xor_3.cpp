//swapping two variables without using a temporary variable
//method 1
//using arithmetic operators
#include<iostream>
using namespace std;
// int main()
// {
//     int x=10, y=5;
//     x=x+y;
//     y=x-y;
//     x=x-y;
//     cout<<x<<" "<<y;
// }

//method 2
//by multiplication and division
// int main()
// {
//     int x=1;
//     int y=5;
//     x=x*y;
//     y=x/y;
//     x=x/y;
//     cout<<x<<" "<<y;
// }

//method 3
//using bitwise xor operator
int main()
{
    int x=5;
    int y=34;
    x=x^y;
    y=x^y;
    x=x^y;
    cout<<x<<" "<<y;
}