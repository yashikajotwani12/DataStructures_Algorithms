// priority queue
// minheap:
/*
MinHeap: A Min-Heap is a complete binary tree in which the value in each internal node is smaller than or equal to the values in the children of that node. Mapping the elements of a heap into an array is trivial: if a node is stored at index k, then its left child is stored at index 2k + 1 and its right child at index 2k + 2.

1> Create a min-heap and insert the first element of all the ‘k’ linked lists.

2> As long as the min-heap is not empty, perform the following steps
    a> Remove the top element of the min-heap (which is the current minimum among all the elements in the       min-heap) and add it to the result list.

    b> If there exists an element (in the same linked list) next to the element popped out in previous step, insert it into the min-heap.

3> Return the head node address of the merged list.




Complexity Analysis: 

Time Complexity: O(N * log k) or O(n * k * log k), where, ‘N’ is the total number of elements among all the linked lists, ‘k’ is the total number of lists, and ‘n’ is the size of each linked list.


Insertion and deletion operation will be performed in min-heap for all N nodes.
Insertion and deletion in a min-heap require log k time.

Auxiliary Space: O(k). 
The priority queue will have atmost ‘k’ number of elements at any point of time, hence the additional space required for our algorithm is O(k).
*/

#include<bits/stdc++.h>
using namespace std;


class ListNode{
    public:
    int val;
    ListNode*next;
    ListNode(int val)
    {
        val= val;
        *next = NULL;
    }
};

ListNode* mergeklists(vector<ListNode*> &lists)
{
    ListNode* dummy = new ListNode(0);
    priority_queue<int, vector<int> ,greater<int>>minheap;

    for(auto head: lists)
    {
        while(head)
        {
            minheap.push(head->val);
            head=head->next;
        }
    }
    ListNode* temp = dummy;
    while(!minheap.empty())
    {
        temp->next = new ListNode(minheap.top());
        minheap.pop();
        temp=temp->next;

    }
    return dummy->next;

}