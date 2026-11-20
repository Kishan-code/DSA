#include<iostream>
#include <vector>
#include <stack>
using namespace std;

/*
Leetcode: Problem-84: Largest Rectangle in Histogram
*********************************************************************************************

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 
Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4
 

Constraints:
1 <= heights.length <= 10^5
0 <= heights[i] <= 10^4
*/

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int max_area = 0;

    stack<int> st;
    vector<int> lse(n,0), rse(n,0);
    
    // Left smaller elemetns
    for(int i  = 0; i < n; i++){
        while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
        lse[i] = st.empty()? -1 : st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    // Right smaller elements
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
        rse[i] = st.empty()? n : st.top();
        st.push(i);            
    }

    // calculate area
    for(int i = 0; i < n; i++){
        max_area = max(max_area, heights[i]*(rse[i]-lse[i]-1));
    }


    return max_area;
}

// similar problem on GFG
/******************************************************************************************** */

int main(void){
    vector<int> nums = {2,1,5,6,2,3};

    cout<<largestRectangleArea(nums);
}