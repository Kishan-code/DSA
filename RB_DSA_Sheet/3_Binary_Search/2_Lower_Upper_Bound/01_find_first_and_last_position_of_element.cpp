#include<iostream>
#include <vector>
using namespace std;

/*
Leetcode: Problem-34: Find First and Last Position of Element in Sorted Array
********************************************************************************************************

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non-decreasing array.
-10^9 <= target <= 10^9
*/

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans(2,-1);

    int n = nums.size();
    int l = 0, r = n-1;
    int mid;

    // First Occurrence
    while(l <= r){
        mid = l+(r-l)/2;
        if(nums[mid] == target){
            ans[0] = mid;
            r = mid-1;
        }
        else if(nums[mid] < target) l = mid+1;
        else r = mid-1;
    }

    // Last Occurrence
    l = 0, r = n-1;
    
    while(l <= r){
        mid = l+(r-l)/2;
        if(nums[mid] == target){
            ans[1] = mid;
            l = mid+1;
        }
        else if(nums[mid] < target) l = mid+1;
        else r = mid-1;
    }

    return ans;
}

// similar problem in GFG

/********************************************************************************************** */

int main(void){
    vector<int> nums = {1, 3, 5, 5, 5, 5, 67, 123, 125};

    vector<int> ans = searchRange(nums, 5);

    for(auto x: ans) cout<<x<<" ";
}