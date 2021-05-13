#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
};

void reverse(Node**head)
{
    Node*current=*head;
    Node*prev=NULL;
    Node*next=NULL;
    while(current!=NULL)
    {

        next = current->next;
        current->next=prev;
        prev=current;
        current=next;


    }
    *head=prev;
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

void push(Node**head, int data)
{
    Node*newnode= new Node();
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;
}
int main()
{
    /* Start with the empty list */
    Node* head = NULL;
 
    /* Let us create a sample linked list as following
    0->1->4->6->9->10->11 */
 
    push(&head, 11);
    push(&head, 10);
    push(&head, 9);
    push(&head, 6);
    push(&head, 4);
    push(&head, 1);
    push(&head, 0);
 
    printf("\nOriginal Linked list \n");
    printlist(head);
 
    reverse(&head);
 
    printf("\nModified Linked list \n");
    printlist(head);
 
    return 0;
}