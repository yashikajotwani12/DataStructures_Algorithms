#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node()
    {
    data=0;
    next=NULL;
    }

};
void push( Node**head , int data)
{
    Node*newnode = new Node();
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;
}
void printlist(Node*node)
{
    while(node!=NULL)
    {
        cout<<node->data<<" ";
        node=node->next;
    }
}

void removeduplicates(Node*head)
{
    unordered_map<int , bool> track;
    Node*temp = head;
    while(temp)
    {
        if(track.find(temp->data)==track.end())
        {
            cout<<temp->data<<" ";
        }
        track[temp->data]=true;
        temp=temp->next;
    }

}
int main()
{
    Node* head = NULL;
 
    /* Created linked list will be
    11->11->11->13->13->20 */
    push(&head, 20);
    push(&head, 13);
    push(&head, 13);
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);
 
    cout << "Linked list before duplicate removal ";
    printlist(head);
 
    cout << "\nLinked list after duplicate removal ";
    removeduplicates(head);
 
    return 0;
}
