/*
Problem: maximum subarray of an element
Platform: LeetCode
Approach: Basic array using for loop
Time Complexity: O(n2)
Space Complexity: O(1)
*/

#include<iostream>
#include<vector>
using namespace std;

int maximunm_array(vector<int>&arr){
    int n=arr.size();
    int max_sum=INT_MIN;
    int i,j;
    for(i=0;i<n;i++){
        int sum=0;
        for(j=i;j<n;j++){
            sum+=arr[j];
            max_sum=max(max_sum,sum);
        }
    }
    return max_sum;
}

int main(){
    vector<int>arr={-1,-2,4,-5,1};
    int result = maximunm_array(arr);
    cout<<"max_sub array of element is : "<<result;
}