/*
NEXT GREATER ELEMENT I – MONOTONIC STACK

Problem:
• nums1 is subset of nums2
• Find next greater element of nums1 in nums2

Approach:
• Process nums2 using monotonic decreasing stack
• Map each element → its next greater
• While stack not empty and curr > stack.top() → pop & map
• Push current element
• Remaining stack elements → -1
• Build answer for nums1 using map

Stack Type:
• Monotonic Decreasing

Complexity:
• Time: O(n)
• Space: O(n)
*/
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

int main(){
    // question //
    vector<int>nums1 = {4,1,2};
    vector<int>nums2 = {1,3,4,2};

    //answer//
    unordered_map<int,int>m; //nums2[i] , NG //
    /*find nums2 next greater element*/
    stack<int>s;

    for(int i=nums2.size()-1; i>=0; i--){

        while(s.size()>0 && s.top()<=nums2[i]){
            s.pop();
        }

        if(s.empty()){
            m[nums2[i]] = -1;
        }else{
            m[nums2[i]] = s.top();
        }
        s.push(nums2[i]);
    }

    // compare it with nums1[i] as it is subset of nums2[i] //
    vector<int>ans;
    for(int i=0;i<nums1.size();i++){
        ans.push_back(m[nums1[i]]);
        cout<<ans[i]<<" ";
    }cout<<endl;
}

/*
. map is used to store:
. element -> its next greater element

. while processing nums2 using stack,
. once next greater is found, store it in map

. later, nums1 elements are directly searched in map
. to get their next greater element in O(1) time

.map avoids re-scanning nums2 for each nums1 element
*/
