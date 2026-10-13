#include<iostream>
#include <vector>
#include <climits>
using namespace std;

/*
Leetcode: Problem-1749: Maximum Absolute Sum of Any Subarray
********************************************************************************************

You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.
 

Example 1:
Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.

Example 2:
Input: nums = [2,-5,1,-4,3,-2]
Output: 8
Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.
 

Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4

*/

int kadanes(vector<int> &arr){
    int max_sum = INT_MIN;
    int sum = 0;

    for(auto x: arr){
        sum += x;
        max_sum = max(max_sum, sum);
        if(sum < 0) sum = 0;
    }

    return max_sum;
}

int maxAbsoluteSum(vector<int>& nums) {
    int n = nums.size();
    int max_sum, min_sum;

    max_sum = kadanes(nums);

    for(int i = 0; i < n; i++){
        nums[i] *= -1;
    }

    min_sum = kadanes(nums);

    return abs(max_sum) > abs(min_sum)? abs(max_sum) : abs(min_sum);
}

/**************************************************************************************** */

int main(void){
    vector<int> nums = {2,-5,1,-4,3,-2};

    cout<<maxAbsoluteSum(nums);
}