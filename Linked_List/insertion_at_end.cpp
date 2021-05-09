#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;


};

void printlist(Node*node)
{
    while(node!=NULL){
        cout<<node->data<<" ";
        node=node->next;

    }
}
void append(Node**head, int data)
{
    Node* newnode= new Node();
    Node*last = *head;
    newnode->data=data;
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }
    while(last->next ==NULL)
    {
        last =last->next;
    }
    
    last->next =newnode;
    return;

}

int main() 
{ 
    /* Start with the empty list */
    Node* head = NULL; 
      
    // Insert 6. So linked list becomes 6->NULL 
    append(&head, 6); 
    append(&head, 7); 
      
    // Insert 7 at the beginning. 
    // So linked list becomes 7->6->NULL 
    // push(&head, 7); 
      
    // Insert 1 at the beginning. 
    // So linked list becomes 1->7->6->NULL 
    // push(&head, 1); 
      
    // Insert 4 at the end. So 
    // linked list becomes 1->7->6->4->NULL 
    append(&head, 4); 
      
    // Insert 8, after 7. So linked 
    // list becomes 1->7->8->6->4->NULL 
    // insertAfter(head->next, 8); 
      
    cout<<"Created Linked list is: "; 
    printlist(head); 
      
    return 0; 
} 