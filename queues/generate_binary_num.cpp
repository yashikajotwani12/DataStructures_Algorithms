#include<bits/stdc++.h>
using namespace std;

vector<string> generate(int n)
{
    vector<string>ans;
    queue<string>q;
    q.push("1");
    for(int i=1;i<=n;i++ )
    {
        string binary = q.front();
        q.pop();
        ans.push_back(binary);
        q.push(binary+"0");
        q.push(binary+"1");

    }
    return ans;
}


int main()
{
    int n=5;
    vector<string>ans = generate(n);
    for (auto i = ans.begin(); i != ans.end(); ++i)
    std::cout << *i << ' ';

return 0;

}