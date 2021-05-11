// Floyd's Cycle Detection
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
};
void push(Node**head, int data)
{
    Node*newnode = new Node();
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;

}

int countnode(Node*head)
{
    int res=1;
    Node*temp= head;
    while(temp->next!=head)
    {
        res++;
        temp=temp->next;

    }
    return res;
}
int countnodeloop( Node*head)
{
    Node*slow;
    Node*fast;
    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow == fast)
        {
            return countnode(slow);
        }
    }
    return 0;
}
int main()
{
    Node*head=NULL;
    
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    /* Create a loop for testing */
    head->next->next->next = head;
 
   cout<<countnodeloop(head)<<endl;
 
    return 0;
}