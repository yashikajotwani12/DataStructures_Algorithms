#include<iostream>
#include<climits>
using namespace std;

class stack{
    public:
    int data;
    stack *next;

};
stack*newnode(int data)
{
    stack*node=new stack();
    node->data=data;
    node->next=NULL;
    return node;
}
int isempty(stack*node)
{
    return !node;
}
void push(stack **root, int data)
{
    stack *node=newnode(data);
    node->next=*root;
    *root=node;
    cout<<data<< "   pushed\n";


}
int pop(stack**root)
{
    if(isempty(*root))
    return INT_MIN;
    stack*temp=*root;
    *root=(*root)->next;
    int popped=temp->data;
    free(temp);
    return popped;
}
int peek(stack*root)
{
    if(isempty(root))
    return INT_MIN;
    return root->data;
}
int main()
{
    stack*root=NULL;
    push(&root,10);
    push(&root,20);
    push(&root,30);
    push(&root,40);
    cout<<pop(&root)<<"   popped\n";
    cout<<"top element "<<peek(root)<<endl;
    return 0;
}