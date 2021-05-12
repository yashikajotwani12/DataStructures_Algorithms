#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

struct Node{
    int data;
    struct Node*next;
};

struct Node*newnode(int data)
{
    Node*temp =new Node;
    temp->data=data;
    temp->next=NULL;
    return temp;
}

void removeduplicates(struct Node*start)
{
    unordered_set<int>seen;
    struct Node* curr =start;
    struct Node*prev=NULL;
    while(curr!=NULL)
    {

        if(seen.find(curr->data)!=seen.end())
        {
            prev->next=curr->next;
            delete(curr);
        }else
        {
            seen.insert(curr->data);
            prev=curr;

        }
        curr= prev->next;
    }
}
void printlist(struct Node*node)
{
    while(node!=NULL)
    {
        cout<<node->data<<" ";
        node=node->next;
    }
}
int main()
{
    /* The constructed linked list is:
     10->12->11->11->12->11->10*/
    struct Node *start = newnode(10);
    start->next = newnode(12);
    start->next->next = newnode(11);
    start->next->next->next = newnode(11);
    start->next->next->next->next = newnode(12);
    start->next->next->next->next->next =
                                    newnode(11);
    start->next->next->next->next->next->next =
                                    newnode(10);
 
    printf("Linked list before removing duplicates : \n");
    printlist(start);
 
    removeduplicates(start);
 
    printf("\nLinked list after removing duplicates : \n");
    printlist(start);
 
    return 0;
}
