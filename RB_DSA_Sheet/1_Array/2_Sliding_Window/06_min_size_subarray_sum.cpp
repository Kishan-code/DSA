#include<iostream>
#include <vector>
#include <climits>
using namespace std;

/*
Leetcode: Problem-209: Minimum Size Subarray Sum
****************************************************************************************************

Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 
Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:
1 <= target <= 10⁹
1 <= nums.length <= 10⁵
1 <= nums[i] <= 10⁴
*/

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();

    int minLen = INT_MAX;
    int sum = 0;

    int i = 0, j = 0;

    while(j < n){
        sum += nums[j];
        while(sum >= target){
            minLen = min(minLen, j-i+1);
            sum -= nums[i++];
        }
        j++;
    }
    return minLen != INT_MAX? minLen:0;
}

/************************************************************************************************* */

int main(){
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;

    cout<<minSubArrayLen(target, nums);

    return 0;
}