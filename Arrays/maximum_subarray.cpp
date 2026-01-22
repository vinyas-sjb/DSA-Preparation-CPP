/*
Problem: maximum subarray of an element
Platform: LeetCode
Approach: Kadane Algorithm
Time Complexity: O(n)
Space Complexity: O(1)

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>nums = {-2,1,-3,4,-1,2,1,-5,4};
    int n=nums.size(),max_sum=INT_MIN;
    int sum=0,i=0;
    for(i=0;i<n;i++){
        sum+=nums[i];
        max_sum=max(max_sum,sum);

        if(sum<0){
            sum=0;
        }
    }
    cout<<"The max sum is : "<<max_sum<<endl;
}

