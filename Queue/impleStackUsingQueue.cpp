/*
Problem: Implement Stack using Queue

Approach:
- Stack follows LIFO (Last In First Out).
- Queue follows FIFO (First In First Out).
- To simulate stack behavior, we use queue operations.

Idea:
- When pushing a new element, move all previous elements
  behind it so that the newest element stays at the front.
- This ensures the last inserted element is removed first.

Operations:
- push(x): Insert element and rotate previous elements.
- pop(): Remove element from the front of the queue.
- top(): Return the front element of the queue.
- empty(): Check if queue is empty.

Time Complexity:
- push(): O(n)
- pop(): O(1)
- top(): O(1)

Space Complexity:
- O(n)
*/
#include<iostream>
#include<queue>
using namespace std;

class stack{
    public:
    queue<int>q1;
    queue<int>q2;

    stack(){
        // default constructor //
    }

    void push(int data){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(data);

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop(){
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top(){
        return q1.front();
    }

    bool empty(){
        return q1.empty();
    }
};

int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout<<"the top element in stack is : "<<s.top()<<endl;

    cout<<"stack elements using queue are : ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }cout<<endl;
    

    cout<<"the top element in stack is : "<<s.top();
    
    return 0;
}

/*
Stack using one queue.

Approach:
Push element and rotate previous elements so that
new element comes to the front of the queue.

Time Complexity:
push -> O(n)
pop -> O(1)

Space Complexity:
O(n)
*/