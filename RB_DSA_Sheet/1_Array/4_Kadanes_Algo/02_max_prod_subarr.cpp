#include<iostream>
#include <vector>
using namespace std;

/*
Leetcode: Problem-152: Maximum Product Subarray
********************************************************************************************

Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Note that the product of an array with a single element is the value of that element.

 

​​​​​​​Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:
1 <= nums.length <= 2 * 10^4
-10 <= nums[i] <= 10
The product of any subarray of nums is guaranteed to fit in a 32-bit integer.
*/

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int prefix = 1;
    int sufix = 1;
    int max_prod = -10;

    for(int i = 0; i < n; i++){
        if(prefix == 0) prefix = 1;
        if(sufix == 0) sufix = 1;

        prefix *= nums[i];
        sufix *= nums[n-1-i];

        max_prod = max(max_prod, max(prefix, sufix));
    }

    return max_prod;
}

// similar problem in GFG

/************************************************************************************** */

int main(void){
    vector<int> nums = {2,3,-2,4};

    cout<<maxProduct(nums);
}