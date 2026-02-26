/*
Problem: Implement Circular Queue using Array

Approach:
- Use a fixed-size array.
- Maintain two pointers: front and rear.
- Use modulo (%) operation to wrap around the array.
- Queue is full when:
      (rear + 1) % size == front
- Queue is empty when:
      front == -1

Key Idea:
- After reaching the end of the array, reuse empty spaces
  created by dequeue operations.

Operations:
- Enqueue: Insert element at rear and move rear circularly.
- Dequeue: Remove element from front and move front circularly.

Time Complexity:
- Enqueue: O(1)
- Dequeue: O(1)

Space Complexity:
- O(n)

Why Circular Queue?
- Prevents memory wastage seen in Linear Queue.
- Efficient use of fixed-size array.
*/
#include<iostream>
using namespace std;

class CircularQueue{
    int* arr;
    int currSize,capacity;
    int f, r;

    public:
    CircularQueue(int size){
        capacity = size;
        arr = new int[size];
        currSize=0;
        f=0;
        r=-1;
    }

    void push(int data){
        if(currSize == capacity){
            cout<<"Circular queue is Full ";
            return;
        }
        r = (r+1)%capacity;
        arr[r] = data;
        currSize++;
    }

    void pop(){
        if(currSize == 0){
            cout<<"Circular queue is empty ";
            return;
        }
        f = (f+1)%capacity;
        currSize--;
    }

    int front(){
        if(currSize == 0){
            cout<<"Circular queue is empty ";
            return -1;
        }
        return arr[f];
    }

    bool empty(){
        return currSize==0;
    }

    void dispArr(){
        for(int i=0;i<capacity;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

};

int main(){
    CircularQueue cq(3);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    
    cq.pop();
    cq.push(4);
    cq.dispArr();  //display array //
    while(!cq.empty()){
        cout<<cq.front()<<" ";
        cq.pop();
    }cout<<endl;

    return 0;
}

/*
Function: enqueue(int x)

Purpose:
- Inserts an element at the rear of the queue.

Working:
- Check if the queue is full.
- If empty, initialize front to 0.
- Increment rear and insert the element.

Time Complexity: O(1)
*/

/*
Function: dequeue()

Purpose:
- Removes an element from the front of the queue.

Working:
- Check if the queue is empty.
- Move front pointer to the next position.
- If front crosses rear, reset queue to empty state.

Time Complexity: O(1)
*/

/*
Queue Implementation using Array

Operations:
- Enqueue: Insert element at rear (FIFO principle).
- Dequeue: Remove element from front.
- isEmpty: Checks if queue has no elements.
- isFull: Checks if queue is completely filled.

Time Complexity:
- All operations are O(1)

Space Complexity:
- O(n)
*/

/*
Queue vs Stack Operations
🟢 In Queue

Enqueue → Insert element at the rear (back)

Dequeue → Remove element from the front

👉 Queue follows FIFO (First In First Out)
*/