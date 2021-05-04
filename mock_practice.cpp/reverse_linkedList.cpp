#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(int data){
        this->data=data;
        next=NULL;
    }
};

struct Linkedlist{
    node*head;
    Linkedlist()
    {
        head=NULL;
    }
    void reverse()
    {
        node*current=head;
        node*prev,*next=NULL;
        while(current!=NULL)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;

        }
        head=prev;

    }
};
void print()
{
    
}