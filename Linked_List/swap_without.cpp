#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
};

void push(Node**head, int data)
{
    Node* newnode = new Node();
    newnode->data=data;
    newnode->next =*head;
    *head=newnode;

}

void printlist(Node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void swap(Node*& a, Node*& b)
{
    Node* temp=a;
    a=b;
    b=temp;
}
void swapnode(Node**head, int x, int y)
{
    if(x==y)
    return;

    Node**a = NULL;
    Node**b = NULL;

    while(*head)
    {
        if((*head)->data ==x)
        {
        a=head;
        }else if((*head)->data ==y)
        {
            b=head;
        }

        head=&((*head)->next);
    }

    if(a && b)
    {
        swap(*a, *b);
        swap(((*a)->next),((*b)->next));
    }

}
int main()
{
    Node*start =NULL;

    push(&start,7);
    push(&start,6);
    push(&start,5);
    push(&start,4);
    push(&start,3);
    push(&start,2);
    push(&start,1);
  cout<<"linkedlist before";
 printlist(start);
 swapnode(&start, 6, 1);
 cout<<" After";
 printlist(start);
 return 0;




}