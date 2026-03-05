/*
SLIDING WINDOW MAXIMUM – BRUTE FORCE

Problem:
• Given an array and window size k
• Find the maximum element in every window of size k

Approach:
• Move the window from left → right
• For each window, check all k elements
• Compute the maximum value in that window
• Store the maximum in result vector

Steps:
• Start window at index i
• Traverse elements from i → i+k-1
• Find maximum element
• Push it into answer vector
• Shift window by 1 position

Example:
nums = [1,3,-1,-3,5,3,6,7], k = 3
Output = [3,3,5,5,6,7]

Complexity:
• Time Complexity: O(n * k)
• Space Complexity: O(1) (excluding result vector)

Note:
• This is the brute force approach
• Optimized solution uses Deque with O(n) time
*/
// iterate through each window
// find max element in current window
// store result in ans vector
// move window by 1


#include<iostream>
#include<vector>
using namespace std;

vector<int>slidingwindow(vector<int>arr){
    vector<int>ans;
    int n = arr.size();
    int k=3;

    for(int i=0;i<n;i++){
       int  maxVal = arr[0];
       for(int j=i;j<i+k;j++){
        maxVal = max(maxVal,arr[j]);
       }
       ans.push_back(maxVal);
    }
    return ans;
}

int main(){
    vector<int>arr = {1,3,-1,-3,5,3,6,7};

    cout<<"sliding window maximum is : ";
    vector<int>ans = slidingwindow(arr);
    for(int val : ans){
        cout<<val<<" ";
    }
    
}

// ans inside function is returned and stored in ans of main()//
// & means pass by reference (no copy of vector, saves memory and time) //