#include<iostream>
#include <vector>
using namespace std;

/*
Leetcode: Problem-33: Search in Rotated Sorted Array
*******************************************************************************************

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 
Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-10^4 <= target <= 10^4
*/

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int mid;
    int i = 0, j = n-1;

    while(i <= j){
        mid = i+(j-i)/2;
        if(nums[mid] == target) return mid;
        
        if(nums[mid] >= nums[i]){
            if(target >= nums[i] && target < nums[mid]) j = mid-1;
            else i = mid+1;
        }
        else{
            if(target > nums[mid] && target <= nums[j]) i = mid+1;
            else j = mid-1;
        }
    }

    return -1;
}

// similar problem in GFG

/************************************************************************************** */

int main(void){
    vector<int> nums = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int target = 3;

    cout<<search(nums, target);
}