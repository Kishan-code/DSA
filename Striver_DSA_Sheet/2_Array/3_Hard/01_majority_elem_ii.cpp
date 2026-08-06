/**
 * Problem - 1: Majority Element II
 * ****************************************************************************
 * 
 * Given an integer array of size n, find all elements that appear more than ⌊n / 3⌋ times.
 * 
 * Example 1:
 * Input: nums = [3,2,3]
 * Output: [3]
 * 
 * Example 2:
 * Input: nums = [1]
 * Output: [1]
 * *****************************************************************************
 * 
 * NOTE: for elements that appear more than ⌊n/k⌋ times. (k-1) maximum 
 * elements can be possible
 * *****************************************************************************
 * 
 * Approach -1: Brute Force
 * we itererate over the array ans check the frequency of each element
 * 
 * if freq of any element becomes greater than ⌊n/3⌋ 
 * then we store that element in the set (for avoiding duplication) and set count to 0.
 * and check  for the next element.
 * 
 * 
 * TC -> O(n²) 
 * SC -> O(1)
 */

#include<iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Brute Force:
vector<int> majorityElement1(vector<int>& nums){
    int n = nums.size();
    int count;
    unordered_set<int> ans;

    for(int i = 0; i < n; i++){
        count = 0;
        for(int j = 0; j < n; j++){
            if(nums[i] == nums[j]) count++;
        }
        if(count > n/3) ans.insert(nums[i]);
    }

    return {ans.begin(), ans.end()};
}


/********************************************************************** */

int main(){
    vector<int> nums = {3,2,3,3,2,1,2,3};
    
    vector<int> ans = majorityElement1(nums);

    for(auto x: ans) cout<<x<<" ";
    return 0;
}