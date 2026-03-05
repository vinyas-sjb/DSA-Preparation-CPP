/*
MAXIMUM SUM SUBARRAY OF SIZE K – FIXED SLIDING WINDOW

Problem:
• Given an array and a window size k
• Find the sum of every subarray of size k

Approach:
• Use sliding window technique
• Add element to window sum
• When window size becomes k:
    - store the sum
    - remove the left element
• Slide the window forward

Key Idea:
• Instead of recalculating sum of k elements each time
• Update the sum by:
    add new element
    remove old element

Formula:
• left index = i - k + 1
• windowSum += nums[i]
• windowSum -= nums[i-k+1]

Example:
nums = [2,1,5,1,3,2], k = 3
windows → [2,1,5] [1,5,1] [5,1,3] [1,3,2]
sums    → 8 7 9 6

Complexity:
• Time Complexity: O(n)
• Space Complexity: O(1) (excluding result vector)

Sliding Window Pattern:
• Expand window → add element
• Window size reached → compute answer
• Shrink window → remove left element
*/

// add element to window
// check if window size reached
// store window sum
// remove left element to slide window


#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int>maxSubarray(const vector<int>&nums, int k){
    vector<int>ans;
    int n = nums.size();
    int window_sum = 0;
    int max_sum = INT_MIN;

    for(int i=0;i<n;i++){

        window_sum += nums[i];

        if(i>=k-1){
            max_sum = max(max_sum,window_sum);
            ans.push_back(window_sum);
            window_sum -= nums[i-k+1];
        }
    }
    return ans;
}

int main(){
    vector<int>nums = {2,1,5,1,3,2};
    int k = 3;
    vector<int>ans = maxSubarray(nums,k);
    cout<<"The max subarray with key is : ";
    for(int val : ans){
        cout<<val<<" ";
    } 
    return 0;
}