#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    int flag;

};

void push(Node**head, int data)
{
    Node*newnode = new Node();
    newnode->data=data;
    newnode->flag=0;
    newnode->next=*head;
    *head=newnode;

}
// bool detectloop(Node*h)
// {
//     unordered_set<Node*>s;
//     while (h!=NULL)
//     {
//        if(s.find(h)!=s.end())
//        return true;
//          s.insert(h);
//          h=h->next;
//     }
//     return false;

// }
//  method2
bool detectloop(Node *h)
{
    while(h!=NULL)
    {
        if(h->flag==1)
        return true;

        h->flag=1;
        h=h->next;
    }
    return false;
}






int main()
{
    Node*head=NULL;
    
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    /* Create a loop for testing */
    // head->next->next->next = head;
 
    if (detectloop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
 
    return 0;
}