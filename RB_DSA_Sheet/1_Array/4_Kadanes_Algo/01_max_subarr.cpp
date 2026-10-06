#include<iostream>
#include <vector>
using namespace std;

/*
Leetcode: Problem-53: Maximum Subarray
**************************************************************************************

Given an integer array nums, find the subarray with the largest sum, and return its sum.

 
Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
*/

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    int maxSum = nums[0];

    for(auto x: nums){
        sum += x;
        maxSum = max(sum, maxSum);
        if(0 > sum) sum = 0;
    }

    return maxSum;
}

//similar problem is on GFG

/************************************************************************************** */

int main(void){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout<<maxSubArray(nums);
}