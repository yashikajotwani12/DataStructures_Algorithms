#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
};

Node*sortedlinked(Node*a , Node*b)
{
    if(a==NULL || b==NULL)
    {
        return NULL;
    }

    if(a->data < b->data)
    {
        return sortedlinked(a->next, b);
        
    }
    if(a->data > b->data)
    {
        return sortedlinked(a, b->next);
    }

    Node*temp = new Node();
    temp->data=a->data;
    temp->next =sortedlinked(a->next, b->next);
    return temp;
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
    /* Start with the empty lists */
     Node* a = NULL;
     Node* b = NULL;
     Node* intersect = NULL;
 
    /* Let us create the first sorted
      linked list to test the functions
     Created linked list will be
      1->2->3->4->5->6 */
    push(&a, 6);
    push(&a, 5);
    push(&a, 4);
    push(&a, 3);
    push(&a, 2);
    push(&a, 1);
 
    /* Let us create the second sorted linked list
     Created linked list will be 2->4->6->8 */
    push(&b, 8);
    push(&b, 6);
    push(&b, 4);
    push(&b, 2);
 
    /* Find the intersection two linked lists */
    intersect = sortedlinked(a, b);
 
    printf("\n Linked list containing common items of a & b \n ");
    printlist(intersect);
 
    return 0;
}