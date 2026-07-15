/**
 * Problem - 4: Maximum Subarray Sum:
 * ****************************************************************
 * 
 * Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.
 * A subarray is a contiguous non-empty sequence of elements within an array.
 * eg:
 * Input: nums = [2, 3, 5, -2, 7, -4]
 * Output: 15 -> The subarray from index 0 to index 4 has the largest sum = 15
 * ***************************************************************
 * 
 * Approach -1: Brute Force:
 * check for all possible subarray
 * and get the sum
 * if sum becomes greater than max then put sum into max (max = sum)
 * otherwise go for next element 
 * do this untill all possible subarrays are not checked
 * 
 * TC -> O(n²)
 * SC -> O(1)
 * ***************************************************************
 * 
 * Approach -2: Optimal (Kadane's Algorithm):
 * in Kadane's algo we iterate over the array and get the sum of elements
 * find max sum: maxSum = max(sum, maxSum)
 * if sum becomes neative, then we initialise it with 0 again (sum = 0)
 * after end of the loop
 * return maxSum
 * 
 * TC -> O(n)
 * SC -> O(1)
 */

 #include<iostream>
 #include<vector>
 #include<climits>
 using namespace std;

 // Brute Force:
 int maxSubArrSum(vector<int> &v){
    int n = v.size();
    int maxSum = INT_MIN;
    int sum, j;

    for(int i = 0; i < n; i++){
        sum = 0;
        j = i;
        while(j < n){
            sum += v[j];
            if(sum > maxSum) maxSum = sum;
            j++;
        }
    }

    return maxSum;
 }

 // Optimal: (Kadane's Algo):
 int KadaneAlgo(vector<int> &v){
    int n = v.size();
    int sum = 0;
    int maxSum = INT_MIN;

    for(int i = 0; i < n; i++){
        sum += v[i];
        maxSum = max(sum, maxSum);
        if(0 > sum) sum = 0;
    }

    return maxSum;
 }

 int main(){
    vector<int> nums = {-2, -3, 4, -1, -2, 1, 5, -3};

    // cout<<maxSubArrSum(nums)<<endl;
    cout<<KadaneAlgo(nums)<<endl;

    return 0;
 }