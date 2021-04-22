#include<iostream>
using namespace std;
struct qnode{
    int data;
    qnode*next;
    qnode(int d)
    {
        data=d;
        next=NULL;

    }
};
struct queue{
   
    qnode*front, *rear;
     queue()
    {
        front=rear=NULL;
    }
    void enqueue(int x)
    {
        qnode*temp=new qnode(x);
        if(rear==NULL)
        {
            front=rear=temp;
            return;
        }
        rear->next=temp;
        rear=temp;
    }
     void dequeue()
     {
         if(front==NULL)
         return;

         qnode*temp=front;
         front=front->next;
         if(front==NULL)
         rear=NULL;

         delete(temp);

     }


};
int main()
{
queue q;
q.enqueue(10);
q.enqueue(20);
q.enqueue(30);
q.dequeue();
q.dequeue();

q.enqueue(40);
q.enqueue(50);
q.enqueue(60);
q.dequeue();
cout<<"queue front "<<(q.front)->data<<endl;
cout<<"queue rear "<<(q.rear)->data<<endl;
}