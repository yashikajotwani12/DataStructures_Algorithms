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
        node= node->next;

    }
}
void push(Node** head_ref, int new_data) 
{ 
    /* 1. allocate node */
    Node* new_node = new Node();
  
    /* 2. put in the data */
    new_node->data = new_data; 
  
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref); 
  
    /* 4. move the head to point to the new node */
    (*head_ref) = new_node; 
} 
void insert(Node* prevnode, int data)
{
    if(prevnode == NULL)
    {
        cout<<"prev node was null";
        return ;

    }

    Node*newnode= new Node();
    newnode->data=data;
    newnode->next = prevnode->next;
    prevnode->next=newnode;

    
}
int main() 
{ 
    /* Start with the empty list */
    Node* head = NULL; 
      
    // Insert 6. So linked list becomes 6->NULL 
    // append(&head, 6); 
      
    // Insert 7 at the beginning. 
    // So linked list becomes 7->6->NULL 
    // push(&head, 7); 
      
    // Insert 1 at the beginning. 
    // So linked list becomes 1->7->6->NULL 
    push(&head, 1); 
      
    // Insert 4 at the end. So 
    // linked list becomes 1->7->6->4->NULL 
    // append(&head, 4); 
      
    // Insert 8, after 7. So linked 
    // list becomes 1->7->8->6->4->NULL 
    insert(head->next, 8); 
      
    cout<<"Created Linked list is: "; 
    printlist(head); 
      
    return 0; 
} 