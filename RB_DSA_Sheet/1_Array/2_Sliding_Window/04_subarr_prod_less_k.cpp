#include<iostream>
#include<vector>
using namespace std;

/*
Leetcode: Problem-713: Subarray Product Less Than K
****************************************************************************************

Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

 
Example 1:
Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

Example 2:
Input: nums = [1,2,3], k = 0
Output: 0
 

Constraints:
1 <= nums.length <= 3 * 10⁴
1 <= nums[i] <= 1000
0 <= k <= 10⁶
*/

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int n = nums.size();

    int count = 0;
    int currProd = 1;

    int i = 0, j = 0;

    while(j < n){
        currProd *= nums[j];
        while(i <= j && currProd >= k) currProd /= nums[i++];
        count += j-i+1;
        j++;
    }
    return count;
}

/********************************************************************************* */

int main(){
    vector<int> nums = {10,5,2,6};
    int k = 100;

    cout<<numSubarrayProductLessThanK(nums, k);

    return 0;
}