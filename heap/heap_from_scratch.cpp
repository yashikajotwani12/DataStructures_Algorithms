#include<iostream>
using namespace std;

class Maxheap{
    int *harr; // pointer to array 
    int capacity; // max possible size
    int heap_size; //current number of elements in max heap


    public:
    Maxheap(int a[], int n);
    void maxheapify(int i);
    int parent(int i){ return (i-1)/2;}
    int left(int i){
        return (2*i+1);
    }
    int right(int i)
    {
        return (2*i+2);
    }

    int extractmax();
    int getmax(){return harr[0];}
    void replacemax(int x)
    {
        harr[0]=x;
        maxheapify(0);
    }

};
