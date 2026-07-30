#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Leetcode: Problem-2461: Maximum Sum of Distinct Subarrays With Length K
***********************************************************************************

You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions

Example 2:
Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.
 

Constraints:
1 <= k <= nums.length <= 10⁵
1 <= nums[i] <= 10⁵
*/

long long maximumSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;

    int n = nums.size();
    long long maxSum = 0;
    long long sum = 0;
    int i = 0, j = 0;

    while(j < n){
        sum += nums[j];
        mp[nums[j]]++;
        if(j-i+1 > k){
            sum -= nums[i];
            mp[nums[i]]--;
            if(mp[nums[i]] == 0) mp.erase(nums[i]);
            i++;
        }
        if(j-i+1 == k && mp.size() == k){
            maxSum = max(maxSum, sum);
        }
        j++;
    }
    return maxSum;
}

/*
GFG: Max Sum Subarray of size K
*************************************************************************************

Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

Note: A subarray is a contiguous part of any given array.

Examples:
Input: arr[] = [100, 200, 300, 400], k = 2
Output: 700
Explanation: arr2 + arr3 = 700, which is maximum.

Input: arr[] = [1, 4, 2, 10, 23, 3, 1, 0, 20], k = 4
Output: 39
Explanation: arr1 + arr2 + arr3 + arr4 = 39, which is maximum.

Input: arr[] = [100, 200, 300, 400], k = 1
Output: 400
Explanation: arr3 = 400, which is maximum.

Constraints:
1 ≤ arr.size() ≤ 10⁶
0 ≤ arr[i] ≤ 10⁶
1 ≤ k ≤ arr.size()
*/

int maxSubarraySum(vector<int>& arr, int k) {
    int n = arr.size();
    int maxSum = 0;
    int sum = 0;
    int i = 0, j = 0;
    
    while(j < n){
        sum += arr[j];
        
        if(j-i+1 > k){
            sum -= arr[i];
            i++;
        }
        if(j-i+1 == k){
            maxSum = max(maxSum, sum);
        }
        j++;
    }
    return maxSum;
}


/******************************************************************************* */

int main(){
    vector<int> nums = {1,5,4,2,9,9,9};
    int k = 3;
    
    cout<<maximumSubarraySum(nums, k)<<endl;
    
    cout<<maxSubarraySum(nums, k);

    return 0;
}