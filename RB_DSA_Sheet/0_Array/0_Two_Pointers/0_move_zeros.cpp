/*
Leetcode: Problem-283: Move Zeroes
*****************************************************************************

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

 
Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]
 

Constraints:
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 
*/

#include<iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int i = 0, j = 0;

    while(i < n){
        if(nums[j] != 0){
            j++;
        }
        else if(nums[j] == 0 && nums[i] != 0){
            swap(nums[j], nums[i]);
            j++;
        }
        else{
            i++;
        }
    }
}

int main(){
    vector<int> nums = {0,1,0,3,12};

    moveZeroes(nums);

    for(auto x: nums)
        cout<<x<<" ";

    return 0;
}