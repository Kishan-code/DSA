/**
 * Problem - 13: Count subarrays with given sum
 * **************************************************************************************
 * 
 * Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
 * 
 * eg:
 * Input: nums = [1, 1, 1], k = 2
 * Output: 2
 * Explanation: In the given array [1, 1, 1], there are two subarrays that sum up to 2: [1, 1] and [1, 1]. Hence, the output is 2.
 * 
 * **************************************************************************************
 * 
 * Approach -1: Brute Force
 * check all possible subarrays
 * if sum of any subarray is become equa to the k then increase the count by 1
 * 
 * TC -> O(n²)
 * SC -> O(1)
 * **************************************************************************************
 * 
 * Approach -2: Optimal (Prefix sum and hashing)
 * in this approach we will calculate the prefix sum, and store it into the map as key and its frequency as value.
 * 
 * eg: 
 * k = 3
 * nums = [1,2,3]
 * prefixSum = [1, 1+2, 1+2+3] --> [1,3,6]
 * map = {{0,1}, {1,1}, {3,1}, {6,1}} 
 * [NOTE: initially map will contain only {0,1}, it will store the values during the prefixSum calculation and calculating the count]
 * 
 * for prefixSum = 1 --> we check (prefixSum - k) present in map or not
 * If it is present then add its value to the count (count = count + map[prefixSum - k])
 * and store prefixSum as key in the map if not present and increase its value by 1
 * 
 * so: 
 * => map = {{0,1}}
 * 
 * for prefixSum = 1 --> map[prefixSum -k ] --> map[1-3] --> map[-2] not present
 * count = 0
 * => map[prefixSum] = 1 ==> map = {{0,1}, {1,1}}
 * 
 * for prefixSum = 3 --> map[3-3] --> map[0] present map[0] --> 1
 * count = count + map[0] --> count = 0 + 1 --> count = 1
 * => map[2] = 1 ==> map = {{0,1}, {1,1}, {3,1}}
 * 
 * for prefixSum = 6 --> map[6-3] --> map[3] present map[3] --> 1
 * count = 1+1 --> count = 2
 * => map[6] = 1 ==> map = {{0,1}, {1,1}, {3,1}, {6,1}}
 * 
 * return the count i.e., 2:  [1,2] and [3] only two subarrays whose sum equals k.
 * 
 * TC -> O(n)
 * SC -> O(n)
 */

#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

// Brute Force
int subarraySum1(vector<int>& nums, int k) {
    int n = nums.size();

    int count = 0;
    int sum;

    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = i; j < n; j++){
            sum += nums[j];
            if(sum == k) count++;
        }
    }
    return count;
}

// Optimal
int subarraySum2(vector<int>& nums, int k){
    unordered_map<int, int> mp;
    mp[0] = 1;
    int count = 0;
    int prefixSum = 0;

    for(auto el: nums){
        prefixSum += el;
        count += mp[prefixSum-k];
        mp[prefixSum]++;
    }
    return count;
}


/******************************************************************************* */

int main(){
    vector<int> nums = {1,2,3};
    int k = 3;

    // cout<<subarraySum1(nums, k);
    cout<<subarraySum2(nums, k);

    return 0;
}