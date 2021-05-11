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
void printlist(Node* ptr)
{
    while(ptr!=NULL)
    {
        cout<<"->"<<ptr->data<<" ";
        ptr=ptr->next;


    }
    cout<<" Null "<<endl;
}
void printmiddle(Node* head)
{
    Node*slow=head;
    Node* fast=head;
    if(head!=NULL)
    {
        while(fast!=NULL && fast->next !=NULL)
        {
            
        fast=fast->next->next;
        slow=slow->next;

        }
           cout<<"Middle is "<<slow->data;

    }
 
}
int main() 
{ 
    // Start with the empty list 
    Node* head = NULL; 
      
    // Iterate and add element 
    for (int i=5; i>0; i--) 
    { 
        push(&head, i); 
        printlist(head); 
        printmiddle(head); 
    } 
  
    return 0; 
}