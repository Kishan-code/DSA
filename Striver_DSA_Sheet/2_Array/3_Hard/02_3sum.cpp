/**
 * Problem - 2: 3Sum
 * *****************************************************************************
 * 
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation: 
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not matter.
 * *********************************************************************************
 * 
 * Approach -1: Brute Force:
 * first we sort the array.
 * and now we find the every possible triplets using 3 nested loops.
 * we store the triplet whose sum equal to 0 in the set so that the duplicates remove from the answer.
 * 
 * TC -> O(n³) + O(nlogn) [for sorting]
 * SC -> O(k)
 * *********************************************************************************
 * 
 * Approach -2: Better (using Hashing):
 * we use hasing in this approach.
 * we want sum of three elements equal to 0:
 *  => first + second + third = 0
 *  => third = (-first) + (-second)
 *  => third = -(first + second)
 * 
 * we use two nested loops for first and second element and use the set for getting the third element.
 * 
 * if (nums[i] + nums[j]) not present in set then we store jth element in the set.
 * and so on...
 * 
 * TC -> O(n²) + O(logm) [for set] + O(nlogn) [for sorting]
 * SC -> O(n) [using set for hashset] + O(k) [set for storing answers]
 * **********************************************************************************
 * 
 * Approach -3: Optimal (using Two pointers)
 * in this approach we will use the two pointers.
 * single loop with two pointers ie., low and high.
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
vector<vector<int>> threeSum(vector<int> &nums){
    set<vector<int>> st;

    int n = nums.size();

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            for(int k = j+1; k < n; k++){
                if(nums[i] + nums[j] + nums[k] == 0){
                    st.insert({nums[i], nums[j], nums[k]});
                }
            }
        }
    }

    return {st.begin(), st.end()};
}

// Better
vector<vector<int>> threeSum2(vector<int> &nums){
    int n = nums.size();
    set<vector<int>> st;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i++){
        unordered_set<int> hashset;
        for(int j = i+1; j < n; j++){
            int third = -(nums[i] + nums[j]);
            if(hashset.find(third) != hashset.end()){
                st.insert({nums[i], third, nums[j]});
            }
            hashset.insert(nums[j]);
        }
    }
    return {st.begin(), st.end()};
}

// Optimal
vector<vector<int>> threeSum3(vector<int> &nums){
    vector<vector<int>> ans;
    int n = nums.size();

    int low, high;
    int sum = 0;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n-2; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        low = i+1;
        high = n-1;
        while(low < high){
            sum = nums[i] + nums[low] + nums[high];
            if(sum == 0){
                ans.push_back({nums[i], nums[low], nums[high]});
                while(low < high && nums[low] == nums[low+1]) low++;
                while(high > low && nums[high] == nums[high-1]) high--;
                low++;
                high--;
            }
            else if(sum < 0) low++;
            else high--;
        }
    }
    return ans;
}


/******************************************************************************** */

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};

    // vector<vector<int>> ans = threeSum(nums);
    vector<vector<int>> ans = threeSum2(nums);

    for(auto v: ans){
        for(auto x: v)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}