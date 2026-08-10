/**
 * Problem - 3: 4Sum
 * ********************************************************************************
 * 
 * Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 * 
 * 0 <= a, b, c, d < n
 * a, b, c, and d are distinct.
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 * You may return the answer in any order.
 * 
 * Example 1:
 * Input: nums = [1,0,-1,0,-2,2], target = 0
 * Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * *********************************************************************************
 * 
 * Approach -1: Brute Force
 * same as 3sum but here we create 4 nested loops and so on.
 * 
 * TC -> O(n⁴) + O(nlogn) [for sorting]
 * SC -> O(k)
 * **********************************************************************************
 * 
 * Approach -2: Better
 * same as 3sum
 * we want sum of three elements equal to 0:
 * => first + second + third + fourth = target
 * => fourth = target - first - second - third
 * => fourth = target -(first + second + third)
 * 
 * TC -> O(n³) + O(logm) [for set] + O(nlogn) [for sorting]
 * SC -> O(n) [using set for hashset] + O(k) [set for storing answers]
 * **********************************************************************************
 * 
 * Approach -3: Optimal
 * same as 3sum
 * 
 * TC -> O(n²) + O(nlogn) [for sorting]
 * SC -> O(1)
 */

#include<iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
using namespace std;


// Brute Force
vector<vector<int>> fourSum1(vector<int>& nums, int target){
    int n = nums.size();
    set<vector<int>> st;

    sort(nums.begin(), nums.end());

    for(int i  = 0; i < n-3; i++){
        for(int j = i+1; j < n-2; j++){
            for(int k = j+1; k < n-1; k++){
                for(int l = k+1; l < n; l++){
                    if(nums[i] + nums[j] + nums[k] + nums[l] == target){
                        st.insert({nums[i], nums[j], nums[k], nums[l]});
                    }
                }
            }
        }
    }

    return {st.begin(), st.end()};
}

// Better (using Hashing)
vector<vector<int>> fourSum2(vector<int>& nums, int target){
    int n = nums.size();

    set<vector<int>> st;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            unordered_set<int> hashset;
            for(int k = j+1; k < n; k++){
                int fourth = target - (nums[i] + nums[j] + nums[k]);
                if(hashset.find(fourth) != hashset.end()){
                    st.insert({nums[i], nums[j], fourth, nums[k]});
                }
                hashset.insert(nums[k]);
            }
        }
    }
    return {st.begin(), st.end()};
}

// Optimal (using Two pointers)
vector<vector<int>> fourSum3(vector<int>& nums, int target){
    vector<vector<int>> res;
    int n = nums.size();

    int sum = 0;
    int low, high;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n-3; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for(int j = i+1; j < n-2; j++){
            if(j > i+1 && nums[j] == nums[j-1]) continue;
            low = j+1;
            high = n-1;
            while(low < high){
                sum = nums[i] + nums[j] + nums[low] + nums[high];
                if(sum == target){
                    res.push_back({nums[i], nums[j], nums[low], nums[high]});
                    while(low < high && nums[low] == nums[low+1]) low++;
                    while(low < high && nums[high] == nums[high-1]) high--;
                    low++;
                    high--;
                }
                else if(sum < target) low++;
                else high--;
            }
        }
    }
    return res;
}

int main(){
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;

    // vector<vector<int>> ans = fourSum1(nums, target);
    // vector<vector<int>> ans = fourSum2(nums, target);
    vector<vector<int>> ans = fourSum3(nums, target);

    for(auto v: ans){
        for(auto x: v)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}