/*
Problem: reverse no of array
Platform: LeetCode
Approach: two pointer
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
#include<vector>
using namespace std;

int main() {
    vector<int>arr={1,2,3,4,5};
    int n=arr.size();
    int l=0,r=n-1;
    while(l<r){
        swap(arr[l],arr[r]);
        l++;
        r--;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
