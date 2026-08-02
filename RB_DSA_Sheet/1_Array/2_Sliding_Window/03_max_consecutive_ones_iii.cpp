#include<iostream>
#include<vector>
using namespace std;

/*
Leetcode: Problem-1004: Max Consecutive Ones III
*****************************************************************************************

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 
Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:
1 <= nums.length <= 10⁵
nums[i] is either 0 or 1.
0 <= k <= nums.length
*/

// Optimal solution of TC -> O(2n)
int maxOnes(vector<int>& arr, int k) {
    int n = arr.size();
    
    int max_ones = 0;
    int count_zeros = 0;
    
    int i = 0, j = 0;
    
    while(j < n){
        if(arr[j] == 0) count_zeros++;
        
        while(count_zeros > k){
            if(arr[i] == 0) count_zeros--;
            i++;
        }
        max_ones = max(max_ones, j-i+1);
        j++;
    }
    return max_ones;
}

// Better solution of TC -> O(n)
int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();

    int count_zeros = 0;
    int i = 0, j = 0;

    while(j < n){
        if(nums[j] == 0) count_zeros++;
        if(count_zeros > k){
            if(nums[i] == 0) count_zeros--;
            i++;
        }
        j++;
    }
    return j-i;
}


/********************************************************************************* */

int main(){
    vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;

    cout<<longestOnes(nums, k);

    return 0;
}