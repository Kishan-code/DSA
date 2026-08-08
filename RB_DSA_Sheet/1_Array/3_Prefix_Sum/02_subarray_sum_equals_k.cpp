#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Leetcode: Problem-560: Subarray Sum Equals K
**********************************************************************************

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 
Example 1:

Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:
1 <= nums.length <= 2 * 10⁴
-1000 <= nums[i] <= 1000
-10⁷ <= k <= 10⁷
*/

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;

    int count = 0;
    int preSum = 0;

    for(auto x: nums){
        preSum += x;
        count += mp[preSum - k];
        mp[preSum]++;
    }
    return count;
}

/******************************************************************************** */

int main(){
    vector<int> nums = {10, 2, -2, -20, 10};
    int k = -10;

    cout << subarraySum(nums, k);
    
    return 0;
}