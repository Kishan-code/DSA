/**
 * Problem - 5: Count subarrays with given xor K
 * ***********************************************************************************
 * 
 * Given an array of integers nums and an integer k, return the total number of subarrays whose XOR equals to k.
 * 
 * Example 1:
 * Input : nums = [4, 2, 2, 6, 4], k = 6
 * Output : 4
 * Explanation : 
 * The subarrays having XOR of their elements as 6 are [4, 2],  [4, 2, 2, 6, 4], [2, 2, 6], and [6] 
 * **********************************************************************************
 * 
 * Approach -1: Brute Force:
 * In this approach we'll check the each subarray. If any subarray whose XOR is equal to K then we increase the count.
 * 
 * TC -> O(n²)
 * SC -> O(1)
 * **********************************************************************************
 * 
 * Approach -2: Optimal:
 * In this approach we will use Hasing and prefix XOR.
 * This problem is just similar as Problem-13 in Medium folder.
 * 
 * TC -> O(n)
 * SC -> O(n)
 */

#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Brute Force
int subarraysWithXorK(vector<int> &nums, int k){
    int n = nums.size();
    int count = 0;
    int xr;

    for(int i = 0; i < n; i++){
        xr = 0;
        for(int j = i; j < n; j++){
            xr ^= nums[j];
            if(xr == k) count++;
        }
    }

    return count;
}

// Optimal
int subarraysWithXorK_Optimal(vector<int> &nums, int k){
    int n = nums.size();

    int xr = 0;
    int count = 0;

    unordered_map<int, int> mp;
    mp[xr]++;

    for(int i = 0; i < n; i++){
        xr ^= nums[i];
        int x = xr ^ k;
        count += mp[x];
        mp[xr]++;
    }

    return count;

}

/************************************************************************************ */

int main(void){
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;

    cout<<subarraysWithXorK(nums, k)<<endl;
    cout<<subarraysWithXorK_Optimal(nums, k);
}