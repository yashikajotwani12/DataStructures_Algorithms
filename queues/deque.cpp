#include<iostream>
#include<queue>
#include<deque>
using namespace std;
void show(deque<int>g)
{
    deque<int>::iterator i;
    for(i=g.begin(); i!=g.end(); ++i)
    {
        cout<<'\t'<<*i;

    }
    cout<<"\n";
}
int main()
{
    deque<int> g;
    g.push_back(10);
    g.push_back(40);
    g.push_front(30);
    g.push_back(16);
g.push_front(23);
cout<<"deque data structure: ";
show(g);
cout << "\ngquiz.size() : " << g.size(); 
    cout << "\ngquiz.max_size() : " << g.max_size(); 
  
    cout << "\ngquiz.at(2) : " << g.at(2); 
    cout << "\ngquiz.front() : " << g.front(); 
    cout << "\ngquiz.back() : " << g.back(); 
  
    cout << "\ngquiz.pop_front() : "; 
    g.pop_front(); 
    show(g); 
  
    cout << "\ngquiz.pop_back() : "; 
    g.pop_back(); 
    show(g); 
  
    return 0; 




}
