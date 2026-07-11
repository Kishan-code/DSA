/**
 * Problem - 12: Longest subarray with sum K
 * *******************************************************************
 * Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.
 * 
 * eg: nums = [10, 5, 2, 7, 1, 9],  k=15 -----> 4 : (5+2+7+1)
 * 
 * *******************************************************************
 * 
 * Approach -1: Brute Force:
 * we will generate all subarrays.
 * find the sum of all subarrays and whose sum is equals to k also is the longest subarray.
 * then we return its length;
 * 
 * TC -> O(n²)
 * SC -> O(1)
 * ******************************************************************
 * 
 * Approach -2: Optimal (uisng two pointers):
 * take two pointers left = 0 and right = 0
 * now add element of the array one by one and store in the sum (sum += nums[right]) and increase the right pointer.
 * if sum > k then minus nums[left] from sum ( sum -= nums[left]) and increase the left pointer (left++)
 * if sum == k then check max(longestSubArr, (right - left +1))
 * retrun longestSubArr;
 * 
 * TC -> O(2n)
 * SC -> O(1)
 */

 #include<iostream>
 #include<vector>
 #include<math.h>
 using namespace std;


 // Brute Force:
 int longestSubarray1(vector<int> &v, int k){
    int n = v.size();
    int sum;
    int longestSubArr = 0;
    int count;

    for(int i = 0; i < n-1; i++){
        sum = v[i];
        for(int j = i+1; j < n; j++){
            sum += v[j];
            count = j-i+1;
            if(sum == k && count > longestSubArr){
                longestSubArr = count;
            } 
            else if(sum > k){
                break;
            }
        }
    }
    return longestSubArr;
 }


 // Optimal: (using two pointers):
 int longestSubarray2(vector<int> &v, int k){
    int n = v.size();
    int longestSubArr = 0;
    int sum = 0;
    int left = 0, right = 0;

    while(right < n){
        sum += v[right];
        while(sum > k){
            sum -= v[left++];
        }
        if(sum == k){
            longestSubArr = max(longestSubArr, (right-left+1));
        }
        right++;
    }

    return longestSubArr;
 }



 int main(){
    vector<int> arr = {2,0,0,0,3};
    int k = 3;

    // cout<<longestSubarray1(arr, k);
    cout<<longestSubarray2(arr, k);


    return 0;
 }