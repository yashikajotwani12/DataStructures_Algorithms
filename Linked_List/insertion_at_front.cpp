#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
};

void push(Node** head, int data)
{
    Node* newnode =new Node();
    newnode->data =data;
    newnode->next =(*head);
    (*head) = newnode;

}
void printlist(Node*node)
{
    while(node!=NULL)
    {
        cout<<node->data<<"->";
        node=node->next;
    }
}
int main()
{
    Node*head=NULL;
    push(&head,3);
    push(&head,4);
    push(&head,5);
    push(&head,6);
    push(&head,7);
    push(&head,8);
    printlist(head);
    return 0;
}