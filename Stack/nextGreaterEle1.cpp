/*
Problem3 : NEXT GREATER ELEMENT – MONOTONIC STACK

Idea:
• Find nearest greater element on RIGHT

Approach:
• Use stack (indices / values)
• Traverse from right to left
• While stack not empty and top <= curr → pop
• If stack empty → answer = -1
• Else → answer = stack.top()
• Push current element

Stack Type:
• Monotonic Decreasing

Complexity:
• Time: O(n)
• Space: O(n)
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    //question//
    vector<int>arr = {6,8,0,1,3};

    //solution//
    vector<int>ans(arr.size(),0);
    stack<int>s;

    for(int i=arr.size()-1;i>=0;i--){ //right -> left //

        while(s.size()>0 && s.top()<=arr[i]){ //monotonic decreasing //
            s.pop();
        }

        if(s.empty()){
            ans[i] = -1;
        }else{
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }

    //print answer//
    for(int val : ans){
        cout<<val<<" ";
    }cout<<endl;

    return 0;
}