#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node*next;

};
Node*newNode(int data)
{
    Node*newnode = new Node;
    newnode->data=data;
    newnode->next=NULL;

    return newnode;
}

class compare
{
    public:
    bool operator()(Node* a, Node*b)
    {
        return a->data > b->data;
    }

};
Node*mergeKSortedLists(Node*arr[], int k)
{
    priority_queue<Node*, vector<Node*>,compare>pq;

    for(int i=0;i<k;i++)
    {
        if(arr[i]!=NULL)
        {
            pq.push(arr[i]);
        }
    }
    if(pq.empty())
    {
        return NULL;
            }
    Node*dummy = newNode(0);
    Node*last = dummy;
    while(!pq.empty())
    {
        Node*curr = pq.top();
        pq.pop();


        last->next = curr;
        last = last->next;

        if(curr ->next !=NULL)
        {
            pq.push(curr->next);
        }
    }
return dummy->next;

}
void printList(Node*root)
{
    while (root != NULL) {
        cout << root->data << " ";
        root = root->next;
    }

}
int main()
{
    int k=3;
    int n=4;

    Node* arr[k]; // array of pointers

    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);
 
    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);
 
    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);

    Node* head = mergeKSortedLists(arr, k);
 
    // print the merged list
    printList(head);

return 0;

}