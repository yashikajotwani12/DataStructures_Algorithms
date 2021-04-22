#include<iostream>
#include<unordered_map>
using namespace std;

struct node{
    int data;
    struct node*next;

};
void push(struct node**head, int data)
{
    struct node*newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=(*head);
    (*head)=newnode;
}

void storing(struct node*head1, struct node*head2,unordered_map<int , int>&element )
{
    struct node*ptr1=head1;
    struct node*ptr2=head2;
    while(ptr1!=NULL || ptr2!=NULL)
    {
        if(ptr1!=NULL)
        {
            element[ptr1->data]++;
            ptr1=ptr1->next;

        }
        if(ptr2!=NULL)
        {
            element[ptr2->data]++;
            ptr1=ptr2->next;

        }
    }
}
struct node*getunion(unordered_map<int, int> element)
{
    struct node*result=NULL;
    for(auto it=element.begin();it!=element.end();it++)
    {
        push(&result, it->first);

    }
    return result;
}

struct node*getintersection(unordered_map<int, int>element)
{
    struct node*result=NULL;
    for(auto it=element.begin();it!=element.end();it++)
    {
        if(it->second==2)
        {
            push(&result, it->first);
        }
    }
    return result;
}
void printlist( struct node*head)
{while(head!=NULL)
{
    cout<<head->data<<"\n";
    head=head->next;

}
   

}
void printintersectunion(node*head1, node*head2)
{
     unordered_map<int , int> mp;
    storing(head1,head2,mp);
    node*intersect=getintersection(mp);
    node*unions=getunion(mp);
    printlist(intersect);
    printlist(unions);


}
int main()
{
    struct node*head1=NULL;
    struct node*head2=NULL;
     push(&head1, 1); 
    push(&head1, 2); 
    push(&head1, 3); 
    push(&head1, 4); 
    push(&head1, 5); 
  
    /* create a linked list 8->4->2->10 */
    push(&head2, 1); 
    push(&head2, 3); 
    push(&head2, 5); 
    push(&head2, 6); 
    printf("First list is \n"); 
    printlist(head1); 
  
    printf("\nSecond list is \n"); 
    printlist(head2); 
  
    printintersectunion(head1, head2); 
  
    return 0; 
  
}