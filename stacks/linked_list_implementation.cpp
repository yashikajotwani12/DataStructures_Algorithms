#include<iostream>
#include<climits>
using namespace std;

class Stack{
    public:
    int data;
    Stack*next;

};
Stack*newnode(int data)
{
    Stack*node= new Stack();
    node->data=data;
    node->next=NULL;
    return node;
}

int isempty(Stack*root)
{
    return !root;
}
void push(Stack ** root,int data)
{
   Stack*node= newnode(data);
   node->next =*root;
   *root=node;
   cout<<data<<" pushed to stack\n";

}
int pop(Stack ** node){
    if(isempty(*node)) return INT_MIN;

    Stack*temp=*node;
    *node=(*node)->next;
    int popped= temp->data;
    free(temp);

    return popped;

}
int peek(Stack*root)
{
    if(isempty(root))
       return INT_MIN;

    return root->data;
}
int main()
{
    Stack*root=NULL;
    push(&root,10);
    push(&root,20);
    push(&root,30);
    push(&root,40);
    cout<<pop(&root)<<" popped from stack"<<endl;
    cout<<"Top element is "<<peek(root)<<endl;
    cout<<"Elements present are:"<<endl;
    while(!isempty(root))
    {
        cout<<peek(root);
        pop(&root);
        cout<<endl;
    }
    return 0;
}