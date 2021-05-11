#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};

void push(Node**head, int data)
{
    Node*newnode = new Node();
    newnode->data=data;
    newnode->next =*head;
    *head = newnode;

}

void nthnode(Node*head, int n)
{
    Node*current = head;
    int len=0,i;
    while(current!=NULL)
    {
        current =current ->next;
        len++;

    }
    if(len < n)
    {
        return;
    }

    current =head;
    for(i=1;i<len - n +1;i++)
    {
        current=current->next;

    }
    cout<<current->data;

}
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    // create linked 35->15->4->20
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);
 
    nthnode(head, 4);
    return 0;
}