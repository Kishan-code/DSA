#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Leetcode: Problem-523: Continuous Subarray Sum
***************************************************************************************

Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:

A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
 

Example 1:
Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

Example 2:
Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.

Example 3:
Input: nums = [23,2,6,4,7], k = 13
Output: false
 

Constraints:
1 <= nums.length <= 10⁵
0 <= nums[i] <= 10⁹
0 <= sum(nums[i]) <= 2³¹ - 1
1 <= k <= 2³¹ - 1
*/

bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> mp;
    
    mp[0] = -1;
    int prefixSum = 0;

    for(int i = 0; i < n; i++){
        prefixSum += nums[i];
        if(mp.find(prefixSum % k) != mp.end()){ 
            if(i-mp[prefixSum % k] >= 2)return true;
        }else mp[prefixSum % k] = i;
    }

    return false;
}

/*
GFG: Largest subarray with 0 sum
*************************************************************************************

Given an array arr[] containing both positive and negative integers, the task is to find the length of the longest subarray with a sum equals to 0.

Note: A subarray is a contiguous part of an array, formed by selecting one or more consecutive elements while maintaining their original order.

Examples:
Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation: The longest subarray with sum equals to 0 is [-2, 2, -8, 1, 7].

Input: arr[] = [2, 10, 4]
Output: 0
Explanation: There is no subarray with a sum of 0.

Input: arr[] = [1, 0, -4, 3, 1, 0]
Output: 5
Explanation: The longest subarray with sum equals to 0 is [0, -4, 3, 1, 0]


Constraints:
1 ≤ arr.size() ≤ 10⁶
-10³ ≤ arr[i] ≤ 10³

*/

int maxLength(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> mp;
    int sum = 0;
    int maxLen = 0;
    
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum == 0) maxLen = i+1;
        if(mp.find(sum) == mp.end()) mp[sum] = i;
        else maxLen = max(maxLen, i - mp[sum]);
    }
    return maxLen;
    
}

// ***********************************************************************************

int main(void){
    vector<int> nums = {23,2,6,4,7};
    int k = 13;

    cout<<checkSubarraySum(nums, k)<<endl;

    // *******************************

    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};

    cout<<maxLength(arr);
    return 0;
}