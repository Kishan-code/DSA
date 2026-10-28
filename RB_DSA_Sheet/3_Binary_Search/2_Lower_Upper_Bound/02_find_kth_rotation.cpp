#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Leetcode: Problem-189: Rotate Array
*****************************************************************************************************

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:
1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 10^5
*/

void rotate(vector<int>& nums, int k) {
    int n = nums.size();

    k %= n;

    reverse(nums.begin(), nums.end()-k);
    reverse(nums.end()-k, nums.end());
    reverse(nums.begin(), nums.end());
}

/*
GFG: Find Rotation Count
*****************************************************************************************************

Difficulty: EasyAccuracy: 23.16%Submissions: 382K+Points: 2Average Time: 20m
Given an increasing sorted rotated array arr[] of distinct integers. The array is right-rotated k times. Find the value of k.

Examples:
Input: arr[] = [5, 1, 2, 3, 4]
Output: 1
Explanation: The given array is [5, 1, 2, 3, 4]. The original sorted array is [1, 2, 3, 4, 5]. We can see that the array was rotated 1 times to the right.

Input: arr = [1, 2, 3, 4, 5]
Output: 0
Explanation: The given array is not rotated.

Input: arr = [6, 9, 2, 4]
Output: 2
Explanation: The original array is [2, 4, 6, 9] and we get the above array after two rotations.


Constraints:
1 ≤ arr.size() ≤ 10^5
1 ≤ arr[i] ≤ 10^7
*/

int findKRotation(vector<int> &arr) {
    int n = arr.size();
    int left = 0, right = n-1;
    int mid;

    
    while(left <= right){
        if(arr[left] <= arr[right]) return left;
        
        mid = left + (right-left)/2;
        
        if(arr[mid] > arr[right]) left = mid+1;
        else right = mid;
    }
    
    return left;
}


/************************************************************************************************** */

int main(void){
    vector<int> nums = {1, 2, 3, 4, 5};

    rotate(nums, 3);

    cout<<findKRotation(nums);
}