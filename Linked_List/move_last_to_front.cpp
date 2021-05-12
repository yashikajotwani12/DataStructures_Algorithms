#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
};
void movetofront(Node **head)
{
    if(*head==NULL || (*head)->next==NULL)
    {
        return ;
    }

    Node*seclast=NULL;
    Node*last =*head;

    while(last->next!=NULL)
    {
        seclast=last;
        last=last->next;
    }
    seclast->next=NULL;
    last->next=*head;
    *head=last;

}
void push(Node** head_ref, int new_data) 
{ 
    /* allocate node */
    Node* new_node = new Node();
  
    /* put in the data */
    new_node->data = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
} 
void printlist(Node*node)
{
    while(node!=NULL)
    {
        cout<<node->data<<" ";
        node=node->next;
    }
}

int main() 
{ 
    Node *start = NULL; 
  
    /* The constructed linked list is: 
    1->2->3->4->5 */
    push(&start, 5); 
    push(&start, 4); 
    push(&start, 3); 
    push(&start, 2); 
    push(&start, 1); 
  
    cout<<"Linked list before moving last to front\n"; 
    printlist(start); 
  
    movetofront(&start); 
  
    cout<<"\nLinked list after removing last to front\n"; 
    printlist(start); 
  
    return 0; 
} 