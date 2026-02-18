/*
## 🧱 Min Stack (Extra Space – O(2n))

### Idea
- Use **two stacks**
- One stack stores all values
- Second stack stores minimum values

### How it Works
- On `push(x)`:
  - Push `x` into main stack
  - If min stack is empty OR `x <= minStack.top()`,
    push `x` into min stack
- On `pop()`:
  - If popped element equals `minStack.top()`,
    pop from min stack as well

### getMin()
- Minimum element is always at `minStack.top()`

### Complexity
- Time: O(1) for push, pop, top, getMin
- Space: O(2n)

### Why it Works
- Min stack keeps track of current minimums
- No need to scan entire stack
*/
#include<iostream>
#include<stack>
using namespace std;

class minStack{
    public:
    stack<pair<int,int>>s;

    minStack(){

    }

    void push(int val){
        if(s.empty()){
            s.push({val,val});
        }else{
            int minVal = min(val,s.top().second);
            s.push({val,minVal});
        }
    }

    void pop(){
        s.pop();
    }

    int top(){
        return s.top().first;
    }

    int getMin(){
        return s.top().second;
    }
};

int main(){
    minStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    cout<<"min value is : "<<ms.getMin()<<endl;
    ms.pop();
    cout<<"the top value is : "<<ms.top()<<endl;
    cout<<"min value is : "<<ms.getMin();
    
    return 0;
}