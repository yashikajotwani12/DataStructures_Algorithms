#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
};

void push(Node**head, int data)
{
    Node*newnode= new Node();
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;
}

void segregate(Node**head)
{
    Node*evenstart=NULL;
    Node*oddstart=NULL;
    Node*evenend=NULL;
    Node*oddend=NULL;
    Node* current = *head;

    while(current!=NULL)
    {
        if(evenstart==NULL || oddstart==NULL)
        {
            return;
        }

        int val=current->data;
        if(val%2==0)
        {
            if(evenstart==NULL)
            {
                evenstart=current;
                evenend=evenstart;
            }else{
                evenend->next=current;
                evenend= evenend->next;
            }
        }else
        {
            if(oddstart==NULL){
                oddstart=current;
                oddend=oddstart;

            }else
            {
                oddend->next=current;
                oddend= oddend->next;
            }
        }
        current=current->next;

    }
    evenend->next= oddstart;
    oddend->next=NULL;


    *head=evenstart;
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
 
    segregate(&head);
 
    printf("\nModified Linked list \n");
    printlist(head);
 
    return 0;
}
 