#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
};
void deletelist(Node**head)
{
    Node*current = *head;
    Node*next =NULL;
    while(current!=NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *head=NULL;
}
void push(Node**head, int data)
{
    Node *newnode =new Node();
    newnode->data=data;
    newnode->next =*head;
    *head=newnode;
}
int main()
{
    /* Start with the empty list */
    Node* head = NULL;
 
    /* Use push() to construct below list
    1->12->1->4->1 */
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);
 
    cout << "Deleting linked list";
    deletelist(&head);
 
    cout << "\nLinked list deleted";
}
