#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
};

void reverse(Node**);
bool camparelist(Node*, Node*);

bool ispalindrome(Node*head)
{
    Node*fast=head;
    Node*slow=head;
    Node*secondhalf;
    Node*prev_of_slow=head;
    Node*midnode=NULL;
    bool res=true;

    if(head!=NULL && head->next==NULL){

        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
           
            prev_of_slow = slow;
            slow=slow->next;
        }

        if(fast!=NULL)
        {
            midnode =slow;
            slow=slow->next;
        }
        secondhalf=slow;
        prev_of_slow->next=NULL;
        reverse(&secondhalf);
        res=camparelist(head,secondhalf);

        if(midnode!=NULL)
        {
            prev_of_slow->next=midnode;
            midnode->next=secondhalf;
        }else
        {
            prev_of_slow->next =secondhalf;
        }

    }
    return res;
}
void reverse(Node**head)
{
    Node*prev=NULL;
    Node*current= *head;
    Node*next;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;
}
bool camparelist(Node* head1, Node*head2)
{
    Node*temp1 =head1;
    Node*temp2= head2;
    while(temp1 && temp2)
    {
        if(temp1->data== temp2->data)
        {
        temp1 = temp1->next;
        temp2 = temp2->next;
        }else
        return 0;
    }
    if (temp1 == NULL && temp2 == NULL)
        return 1;
 
    /* Will reach here when one is NULL
    and other is not */
    return 0;


}
void push(Node** head_ref, char new_data)
{
    /* allocate node */
     Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to pochar to the new node */
    (*head_ref) = new_node;
}
 
// A utility function to print a given linked list
void printList( Node* ptr)
{
    while (ptr != NULL) {
        printf("%c->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
 
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    Node* head = NULL;
    char str[] = "abacaba";
    int i;
 
    for (i = 0; str[i] != '\0'; i++) {
        push(&head, str[i]);
        printList(head);
        ispalindrome(head) ? printf("Is Palindrome\n\n") : printf("Not Palindrome\n\n");
    }
 
    return 0;
}