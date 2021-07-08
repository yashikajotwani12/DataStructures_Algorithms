#include<bits/stdc++.h>
using namespace std;

void generatesub(char *in , char*out, int i, int j)
{
    if(in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<" ";
    return;
    }
    out[j]=in[i];
    generatesub(in , out, i+1,j+1);

    generatesub(in,out,i+1,j);

}
int main()
{
    char input[] ="abc";
    char output[10];
    generatesub(input,output,0,0);
    return 0;

}