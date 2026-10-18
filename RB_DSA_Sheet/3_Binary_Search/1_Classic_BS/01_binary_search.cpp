#include<iostream>
#include <vector>
using namespace std;


/*
Leetcode: Problem-704: Binary Search

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 

Constraints:
1 <= nums.length <= 10^4
-10^4 < nums[i], target < 10^4
All the integers in nums are unique.
nums is sorted in ascending order.
*/

int search(vector<int>& nums, int target) {
    int n = nums.size();
    
    int left = 0, right = n-1;
    int mid;

    while(left <= right){
        mid = left+(right-left)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) left = mid+1;
        else right = mid-1;
    }

    return -1;
}


/*
GFG: First Occurrence in Sorted
*****************************************************************************************

Given a sorted array arr[] and an integer k, find the position(0-based indexing) at which k is present in the array using binary search. If k doesn't exist in arr[] return -1. 

Note: If multiple occurrences are there, please return the smallest index.

Examples:
Input: arr[] = [1, 2, 3, 4, 5], k = 4
Output: 3
Explanation: 4 appears at index 3.

Input: arr[] = [11, 22, 33, 44, 55], k = 445
Output: -1
Explanation: 445 is not present.

Input: arr[] = [1, 1, 1, 1, 2], k = 1
Output: 0
Explanation: 1 appears at index 0.


Constraints:
1 ≤ arr.size() ≤ 10^5
1 ≤ arr[i] ≤ 10^6
1 ≤ k ≤ 10^6
*/

int firstSearch(vector<int> &arr, int k) {
    int n = arr.size();
    
    int left = 0, right = n-1;
    int mid;
    
    while(left <= right){
        mid = left+(right-left)/2;
        if(arr[mid] == k){
            while(mid-1 >= 0 && arr[mid-1] == k) mid--;
            return mid;
        }
        else if(arr[mid] < k) left = mid+1;
        else right = mid-1;
    }
    
    return -1;
}

/************************************************************************************** */

int main(void){
    vector<int> nums = {1, 1, 1, 1, 2};

    cout<<search(nums, 1)<<endl;
    cout<<firstSearch(nums, 1);
}