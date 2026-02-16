/*
Problem : STOCK SPAN 

Idea:
• For each day, count consecutive previous days
  with price <= current price

Approach:
• Use stack of indices
• While stack not empty and price[top] <= price[i] → pop
• Span = i + 1 if stack empty
• Else Span = i - stack.top()
• Push current index

Why stack:
• Nearest greater element on left

Complexity:
• Time: O(n)
• Space: O(n)
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    //stock prices//
    vector<int>price = {100, 80, 60, 70, 60, 75, 85};

    //solution//
    vector<int>ans(price.size(),0);
    stack<int>s;

    for(int i=0;i<price.size();i++){

        while(s.size() > 0 && price[s.top()]<=price[i]){ //stack with high price //
            s.pop();
        }

        if(s.empty()){
            ans[i] = i+1;
        }else{
            ans[i] = i-s.top(); //i-prevhigh//
        }
        s.push(i);
    }

    //print ans//
    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}