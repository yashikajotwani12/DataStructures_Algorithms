#include<bits/stdc++.h>
using namespace std;

// w n e s 
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int r,c;

void printmat(char input[][50])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<input[i][j];

        }
        cout<<endl;
    }
}
void floodfill(char mat[][50], int i, int j , char ch, char color)
{
    // base case
    if(i<0 or j<0 or i>=r or j>=c)
    {
        return;
    }


    //figure boundary condition
    if(mat[i][j]!=ch)
    {
        return;
    } 
    mat[i][j]=color;


    // recursive call

    // four neighbour approach
    for(int k =0;k<4;k++)
    {
        floodfill(mat,i+dx[k],dy[k],ch,color);
    }

}
int main()
{
    cin>>r>>c;
    char input[15][50];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>input[i][j];
        }
    }
    printmat(input);
    floodfill(input,8,13,'.','r');
    printmat(input);
    return 0;
}