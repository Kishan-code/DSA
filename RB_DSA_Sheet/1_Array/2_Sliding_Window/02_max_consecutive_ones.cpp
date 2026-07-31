#include<iostream>
#include<vector>
using namespace std;

/*
Leetcode: Problem-485: Max Consecutive Ones
***********************************************************************************

Given a binary array nums, return the maximum number of consecutive 1's in the array.

 
Example 1:
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

Example 2:
Input: nums = [1,0,1,1,0,1]
Output: 2
 

Constraints:
1 <= nums.length <= 10⁵
nums[i] is either 0 or 1.
*/

int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size();

    int maxCt = 0, count = 0;

    int i = 0, j = 0;
    while(j < n){
        if(nums[j] == 1 && nums[i] == 1){
            count++;
        }
        else{
            count = 0;
            i = j+1;
        }
        maxCt = max(maxCt, count);
        j++;
    }

    return maxCt;
}

/*
GFG: Max Consecutive Bit
************************************************************************************

Given an array arr[] consisting of only 0’s and 1’s, return count of the maximum number of consecutive 1’s or 0’s present in the array. 

Examples:
Input: arr[] = [0, 1, 0, 1, 1, 1, 1]
Output: 4
Explanation: The maximum number of consecutive 1’s in the array is 4 from index 3-6.

Input: arr[] = [0, 0, 1, 0, 1, 0]
Output: 2
Explanation: The maximum number of consecutive 0’s in the array is 2 from index 0-1.

Input: arr[] = [0, 0, 0, 0]
Output: 4
Explanation: The maximum number of consecutive 0’s in the array is 4.

Constraints:
1 ≤ arr.size() ≤ 10⁵
0 ≤ arr[i] ≤ 1
*/

int maxConsecBits(vector<int> &arr) {
    int n = arr.size();

    
    int max_ct = 0;
    int ct_1 = 0, ct_0 = 0;
    int i = 0, j = 0;
    
    while(j < n){
        if(arr[j] == 1 && arr[i] == 1){
            ct_1++;
        }
        else if(arr[j] == 0 && arr[i] == 0){
            ct_0++;
        }
        else{
            if(arr[j] == 1){
                ct_1 = 0;
            }
            else{
                ct_0 = 0;                    
            }
            i = j;
            continue;
        }
        max_ct = max(max_ct, ct_1 > ct_0? ct_1:ct_0);
        j++;
    }
    
    return max_ct;
}

/*
int maxConsecBits(int arr[], int n) {
    if (n == 0)
        return 0;

    int maxCount = 0, count = 1;

    // Loop through the array starting from the second element
    for (int i = 1; i < n; i++) {

        // If same as previous, increase count
        if (arr[i] == arr[i - 1]) {
            count++;
        }

        // If different, update maxCount and reset
        else {
            if (count > maxCount)
                maxCount = count;
            count = 1;
        }
    }

    // Return maximum of last streak
    return (count > maxCount) ? count : maxCount;
}
*/

/******************************************************************************** */

int main(){
    vector<int> nums = {1,1,0,1,1,1};

    cout<<findMaxConsecutiveOnes(nums)<<endl;

    cout<<maxConsecBits(nums);
    return 0;
}
