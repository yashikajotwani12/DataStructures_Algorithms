#include<bits/stdc++.h>
using namespace std;

struct node{
    int info;
    node* link =NULL;
    node(){}
    node(int a):info(a){}
};

void deletenode(node*& head, int val)
{
    if(head==NULL)
    {
        cout<<"Element not prsent \n";
    }

    if(head->info ==val)
    {
        node*t =head;
        head =head->link;

        delete(t);
        return;
    }
    deletenode(head->link, val);

}
