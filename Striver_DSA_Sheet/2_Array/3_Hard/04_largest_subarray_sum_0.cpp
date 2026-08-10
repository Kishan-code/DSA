/**
 * Problem - 4: Largest Subarray with Sum 0
 * *********************************************************************************
 * 
 * You are given an integer array arr of size n which contains both positive and negative integers. Your task is to find the length of the longest contiguous subarray with sum equal to 0.
 * 
 * Return the length of such a subarray. If no such subarray exists, return 0.
 * 
 * Example 1
 * Input: arr = [15, -2, 2, -8, 1, 7, 10, 23]
 * Output: 5
 * Explanation:
 * The subarray [-2, 2, -8, 1, 7] sums up to 0 and has the maximum length among all such subarrays.
 * *********************************************************************************
 * 
 * Approach -1: Brute Force
 * in this approach we iterate over the array and check every possible subarray.
 * the longest subarray whose sum equal to zero will be our answer.
 * 
 * TC -> O(n²)
 * SC -> O(1)
 * **********************************************************************************
 * 
 * Approach -2: Optimal (prefix sum + hashing)
 * in this approach we will use the prefix sum and hashing.
 * we iterate over the array and calculate prefix sum.
 * 
 * if we get same prefix sum at two different positions then the subarray sum between those two indices will always be 0.
 * 
 * if we get three and more positions having same prefix sum then we always consider the first position and the last position where we get the same prefix sum.
 * 
 * the length will always equal to [first positon - last position]
 * 
 * for storing prefix sum to check repetetion we will use hashmap in which the prefix sum will be the key and its index will be the value.
 * 
 * at any point prefix sum becomes 0 then we set maxLen = i+1
 * 
 * TC -> O(n)
 * SC -> O(n)
 */

#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Brute Force
int maxLen1(vector<int>& arr){
    int n = arr.size();
    int maxLen = 0;
    int sum;

    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            if(sum == 0){
                maxLen = max(maxLen, j-i+1);
            }
        }
    }
    return maxLen;
}

// Optimal (using prefix sum and hashing)
int maxLen2(vector<int> &arr){
    int n = arr.size();
    unordered_map<int, int> mp;
    int preSum = 0;
    int maxLen = 0;

    for(int i = 0; i < n; i++){
        preSum += arr[i];
        if(preSum == 0) maxLen = i+1;
        if(mp.find(preSum) == mp.end()) mp[preSum] = i;
        else maxLen = max(maxLen, i - mp[preSum]);
    }
    return maxLen;
}


/******************************************************************************* */

int main(){
    vector<int> nums = {15, -2, 2, -8, 1, 7, 10, 23};

    // cout<<maxLen1(nums);
    cout<<maxLen2(nums);

    return 0;
}