/*
LARGEST RECTANGLE IN HISTOGRAM – O(n)

Idea:
• For each bar, find nearest smaller bar on LEFT and RIGHT
• Width = rightSmaller - leftSmaller - 1
• Area = height[i] * width

Previous Smaller Element (LEFT):
• Traverse LEFT → RIGHT
• Use monotonic increasing stack
• pop while stack.top() >= current
• top gives nearest smaller on left

Next Smaller Element (RIGHT):
• Traverse RIGHT → LEFT
• Use monotonic increasing stack
• pop while stack.top() >= current
• top gives nearest smaller on right

Why Stack:
• Removes useless bigger bars
• Top always gives nearest smaller

Stack Type:
• Monotonic Increasing Stack

Complexity:
• Time: O(n)
• Space: O(n)

Memory Trick:
• Smaller → Increasing Stack
• Previous → Left to Right
• Next → Right to Left
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangle(vector<int>height){
    int n = height.size();
    vector<int>right(n,0); // to store right smaller element //
    vector<int>left(n,0); // to store left smaller element //
    stack<int>s;

    // Right smaller element //
    for(int i=n-1;i>=0;i--){

        while(s.size()>0 && height[s.top()]>=height[i]){
            s.pop();
        }

        /*short way -> 
        right[i] = s.empty() ? n : s.top() */
        if(s.empty()){
            right[i] = n;
        }else{
            right[i] = s.top();
        }
        s.push(i);
    }

    if(!s.empty()){
        s.pop();
    }

    // left smaller element //
    for(int i=0;i<n;i++){

        while(s.size()>0 && height[s.top()]>=height[i]){
            s.pop();
        }

        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // calculate largest rectangle in histogram //
    int max_area = 0;

    for(int i=0;i<n;i++){
        int width = right[i]-left[i]-1;
        int area = height[i] * width;
        max_area = max(max_area,area);
    }
    return max_area;
}

int main(){
    vector<int>height = {2,1,5,6,2,3};
    int ans = largestRectangle(height);
    cout<<"largest area is : "<<ans<<endl;
}

// Previous Smaller → Left to Right
// Next Smaller → Right to Left
// Stack: Monotonic Increasing
// Width = right - left - 1
// Time: O(n), Space: O(n)

// Monotonic stack removes useless elements so nearest smaller is found in O(n)