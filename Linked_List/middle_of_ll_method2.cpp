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
newnode->next =*head;
*head=newnode;
}

void printmiddle(Node*head)
{
    int count=0;
    Node*mid =head;
    while(head!=NULL)
    {
        if(count & 1)
        {
            mid=mid->next;
        }
        ++count;
        head=head->next;
    }
    if(mid!=NULL)
    {
        cout<<"Middle is "<<mid->data;
    }
}
void printlist( Node* ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
  
// Driver code
int main()
{
      
    // Start with the empty list 
    Node* head = NULL;
    int i;
  
    for(i = 5; i > 0; i--) 
    {
        push(&head, i);
        printlist(head);
        printmiddle(head);
    }
    return 0;
}