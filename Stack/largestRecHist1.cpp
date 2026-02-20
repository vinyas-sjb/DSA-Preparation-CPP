/*
Problem: Largest Rectangle in Histogram (Brute Force)

Approach:
- Fix each bar as the minimum height.
- Extend the rectangle to the right from that bar.
- Keep updating the minimum height in the current range.
- For every range, calculate area = minHeight * width.
- Track the maximum area found.

Why it works:
- Any rectangle in the histogram has a minimum height.
- By fixing each bar as that minimum, all possible rectangles are checked.

Time Complexity:
- O(n^2)
  (Two nested loops: for each bar, expand to the right)

Space Complexity:
- O(1)
  (Only variables used, no extra data structures)

Key Observation:
- Width is calculated as (j - i + 1).
- Minimum height determines the rectangle area.
*/

#include<iostream>
#include<vector>
using namespace std;
int largestRectangle(vector<int>height){
    int n = height.size();
    int min_ht = height[0];
    int max_area = 0;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            min_ht = min(min_ht,height[i]);
            int width = j-1+1;
            int area = width*min_ht;
            max_area = max(max_area,area);
        }
    }
    return max_area;
}

int main(){
    vector<int>height = {2,1,5,6,2,3};
    int ans = largestRectangle(height);
    cout<<"largest area is : "<<ans<<endl;
}