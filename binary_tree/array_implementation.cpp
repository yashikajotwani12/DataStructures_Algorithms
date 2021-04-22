#include<bits/stdc++.h>
using namespace std;
char tree[10];
int root(char key)
{
    if(tree[0]!='\0')
    {
        cout<<"tree already had a root\n";
    }else{
        tree[0]=key;
    }
    return 0;
}
int setleft(char key, int parent)
{
    if(tree[parent]=='\0')
    {
        cout<<"cant set child at"<<(parent*2)+1<<", no parent found";

    }else{
        tree[(parent*2)+1]=key;
    }
    return 0;
}
int setright(char key, int parent)
{
    if(tree[parent]=='\0')
    {
        cout<<"cant set child at"<<(parent*2)+2<<", no parent found";

    }else{
        tree[(parent*2)+2]=key;
    }
    return 0;
}
int printtree()
{
    for(int i=0;i<10;i++)
    {
        if(tree[i]!='\0')
        cout<<tree[i];
        else{
            cout<<"-";
        }
    }
    return 0;
}
int main()
{
    root('A');
    setright('C',0);

    setleft('D',1);
     setright('E', 1);
    setright('F', 2);
    printtree();
    return 0;
}
