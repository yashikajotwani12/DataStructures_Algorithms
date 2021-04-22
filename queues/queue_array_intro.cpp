#include<iostream>
#include<climits>
using namespace std;
class queue{

    public:
    int front, rear, size;
    unsigned capacity;
    int*array;

};

queue *createQueue(unsigned capacity)
{
    queue* q = new queue();
    q->capacity=capacity;
    q->front=q->size=0;

    q->rear=capacity-1;
    q->array=new int[(q->capacity * sizeof(int))];
    return q;

}

int isfull(queue *q)
{
    return (q->size == q->capacity);
}

int isempty(queue *q)
{
    return (q->size == 0);
}

void enqueue(queue * q, int item)
{
   if(isfull(q))
   return ;

     q->rear=(q->rear+1)%q->capacity;
     q->array[q->rear]=item;
     q->size=q->size+1;
     cout<<item<<" enqueued to queue\n";

}
int dequeue(queue *q)
{
    if(isempty(q))
    return INT_MIN;

    int item=q->array[q->front];
    q->front=(q->front+1) % q->capacity;
    q->size=q->size+1;
    return item;
}
int front(queue*q )
{
    if(isempty(q))
    return INT_MIN;
    return q->array[q->front];

}
int rear(queue*q )
{
    if(isempty(q))
    return INT_MIN;
    return q->array[q->rear];

}
int main()
{
    queue*q=createQueue(10);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    cout<<dequeue(q)<<"dequeued\n";
    cout<<"front"<<front(q)<<endl;
    cout<<"rear"<<rear(q)<<endl;
    return 0;



}