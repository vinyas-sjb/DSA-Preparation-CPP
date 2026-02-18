/*
MIN STACK – ENCODING TECHNIQUE (SC: O(n))

Idea:
- Use only one stack
- Track minimum using variable minVal

Encoding Rule:
- When new value < minVal:
  store encoded value = 2*val - minVal

Push:
- If stack empty → push val, set minVal
- If val >= minVal → push normally
- If val < minVal → push encoded value, update minVal

Pop:
- If popped value >= minVal → normal pop
- If popped value < minVal → restore old min using:
  oldMin = 2*minVal - encodedVal

getMin:
- Current minimum is always in minVal

Why it works:
- Encoded value stores previous minimum information

Complexity:
- Time: O(1)
- Space: O(n)
*/
#include<iostream>
#include<stack>
using namespace std;

class minStack{
    public:
    stack<long long int>s;
    long long int minVal;
    minStack(){

    }

    void push(int val){
        if(s.empty()){
            s.push(val);
            minVal = val;
        }else{
            if(val <= minVal){
                s.push((long long) 2*val-minVal);
                minVal = val;
            }else{
                s.push(val);
            }
        }
    }

    void pop(){
        if(s.top() <= minVal){
            minVal = 2*minVal - s.top();
        }
        s.pop();
    }

    int top(){
        if(s.top() <= minVal){
            return minVal;
        }
        return s.top();
    }

    int getMin(){
        return minVal;
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

/*
. “We encode values using 2*val - minVal to track minimum with only one stack.”

. Extra stack → Auxiliary Stack Pattern
. No extra stack → Encoding Formula Pattern

. smaller value → encode → update min
*/