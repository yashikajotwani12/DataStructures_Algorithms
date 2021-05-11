#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
};

void push(Node**head, int data)
{
    Node*newnode = new Node();
    newnode->data=data;
    newnode->next =*head;
    *head= newnode;
}

int nthnode(Node*head, int index)
{
    int count=0;
    Node*current = head;
    while(current!=NULL)
    {
        if(count == index)
        {
            return (current->data);

        }
        count++;
        current =current->next;

    }
    assert(0);
}
int main()
{
 
    // Start with the
    // empty list
    Node* head = NULL;
 
    // Use push() to construct
    // below list
    // 1->12->1->4->1
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);
 
    // Check the count
    // function
    cout << "Element at index 3 is " << nthnode(head, 3);
    return 0;
}