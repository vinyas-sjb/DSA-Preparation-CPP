/*
PREVIOUS SMALLER ELEMENT – MONOTONIC STACK

Problem:
• For each element, find nearest smaller element on left

Approach:
• Traverse array from left to right
• Use monotonic increasing stack
• While stack not empty and stack.top() >= current → pop
• If stack empty → previous smaller = -1
• Else → stack.top() is previous smaller
• Push current element into stack

Stack Type:
• Monotonic Increasing

Complexity:
• Time: O(n)
• Space: O(n)
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> prevSmaller(vector<int>arr){
    vector<int>ans(arr.size(),0);
    stack<int>s;

    for(int i=0;i<arr.size();i++){

        while(s.size()>0 && s.top()>=arr[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i] = -1;
        }else{
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }
    return ans;
}

int main(){
    // question //
    vector<int>arr = {3,1,0,8,6};

    // answer //
    vector<int>ans = prevSmaller(arr);

    for(int val : ans){
        cout<<val<<" ";
    }cout<<endl;

    return 0;
}