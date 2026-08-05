#include<iostream>
#include <vector>
#include <deque>
using namespace std;

/*
Leetcode: Problem-239: Sliding Window Maximum
******************************************************************************

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 
Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:
Input: nums = [1], k = 1
Output: [1]
 

Constraints:
1 <= nums.length <= 10⁵⁴
-10⁴ <= nums[i] <= 10⁴
1 <= k <= nums.length
*/

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> res;
    deque<int> maxi;

    for(int right = 0; right < n; right++){
        while(!maxi.empty() && maxi.front() <= right-k) maxi.pop_front();
        while(!maxi.empty() && nums[maxi.back()] < nums[right]) maxi.pop_back();
        maxi.push_back(right);
        if(right >= k-1) res.push_back(nums[maxi.front()]);
    }
    return res;
}

/************************************************************************** */

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(nums, k);

    for(auto x: ans) cout<<x<<" ";
    
    return 0;
}