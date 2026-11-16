#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Leetcode: Problem-410: Split Array Largest Sum
**********************************************************************************************

Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 
Example 1:
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

Example 2:
Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
 

Constraints:
1 <= nums.length <= 1000
0 <= nums[i] <= 10^6
1 <= k <= min(50, nums.length)
*/

bool canSplit(vector<int> &arr, int k, int sum){
    int ct = 1;
    int s = 0;
    
    for(auto p: arr){
        if(s+p <= sum) s += p;
        else{
            ct++;
            s = p;
        }
    }
    
    return ct <= k;
}

int splitArray(vector<int> &arr, int k) {
    int n = arr.size();
    if(k > n) return -1;
    
    
    int low = *max_element(arr.begin(), arr.end());
    int high = 0;
    
    for(auto x: arr) high += x;
    
    int ans = high;
    int mid;
    
    while(low <= high){
        mid = low+(high-low)/2;
        
        if(canSplit(arr, k, mid)){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    
    return ans;
}

// similar problem in GFG

/******************************************************************************************* */

int main(void){
    vector<int> nums = {7,2,5,10,8};

    cout<<splitArray(nums, 2);
}