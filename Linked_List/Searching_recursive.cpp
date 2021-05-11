#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
     Node *next;
};

void push(Node**head, int data)
{
    Node*newnode =new Node();
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;
}
bool search(Node*head, int x)
{
    if(head==NULL)
    {
        return false;
    }
    if(head->data ==x)
    {
        return true;
    }

    return (head->next, x);
}
int main() 
{ 
    /* Start with the empty list */
     Node* head = NULL; 
    int x = 21; 
  
    /* Use push() to construct below list 
    14->21->11->30->10 */
    push(&head, 10); 
    push(&head, 30); 
    push(&head, 11); 
    push(&head, 21); 
    push(&head, 14); 
  
    search(head, 21)? cout << "Yes" : cout << "No"; 
    return 0; 
} 