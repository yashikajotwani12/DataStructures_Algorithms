#include<bits/stdc++.h>
using namespace std;

int matrix[3][3]={{0,1,0},
                  {0,0,0},
                  {0,1,0}};

int knows(int a, int b)
{
    return matrix[a][b];
}
int main()
{
    int celeb=0;
    int n=3;
    for(int i=0;i<n;i++)
    {
        if(knows(celeb,i)==1)
          celeb=i;

    }
    for(int i=0;i<n;i++)
    {
        if((i!=celeb) and (knows(celeb,i)==1 || knows(i,celeb)!=1))
        {
            cout<<"-1"<<endl;
        }
       
    }
     cout<<celeb<<endl;
    return 0;
}