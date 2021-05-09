#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
};

void push(Node**head, int data)
{
    Node*newnode =new Node();
    newnode->data= data;
    newnode->next =(*head);
    (*head )= newnode;
}
void deletenode(Node**head, int key)
{
    Node*temp=*head;
    Node*prev=NULL;

    if(temp!=NULL && temp->data == key)
    {
        *head=temp->next;
        delete temp;
        return;
    }else{

        while(temp!=NULL && temp->data==key)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL)
         return;

         prev->next=temp->next;
         delete temp;
    
    }
    
}
void printlist(Node* node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
int main()
{
     
    // Start with the empty list
    Node* head = NULL;
 
    // Add elements in linked list
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
 
    puts("Created Linked List: ");
    printlist(head);
 
    deletenode(&head, 1);
    puts("\nLinked List after Deletion of 1: ");
     
    printlist(head);
     
    return 0;
}