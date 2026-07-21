/**
 * Problem - 6: Rearrange the array in alternative psitive and negative items:
 * ********************************************************************************************
 * 
 * You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
 * You should return the array of nums such that the array follows the given conditions:
 * 1. Every consecutive pair of integers have opposite signs.
 * 2. For all integers with the same sign, the order in which they were present in nums is preserved.
 * 3. The rearranged array begins with a positive integer.
 * 
 * 
 * eg:
 * Input: nums = [3,1,-2,-5,2,-4]
 * Output: [3,-2,1,-5,2,-4]
 * 
 * *********************************************************************************************
 * 
 * Approach -1: Brute Force:
 * create two arrays of size n/2 i.e., pos[] for positie elements ans neg[] for negative elemetns.
 * now iterate a loop over the array and store positve elements in pos[] array ans negative elements in neg[] array.
 * 
 * now iterate a loop from i = 0 to n/2
 * ans store elements in original array in such manner:
 * nums[2*i] = pos[i]
 * nums[2*i+1] = neg[i]
 * 
 * TC - O(2n)
 * SC - O(n)
 */

 #include<iostream>
 #include<vector>
 using namespace std;

 
 void rearrangeArr(vector<int> &v){
    int n = v.size();
    vector<int> pos;
    vector<int> neg;

    for(int i = 0; i < n; i++){
        if(v[i] > 0) pos.push_back(v[i]);
        else neg.push_back(v[i]);
    }

    for(int i = 0; i < n/2; i++){
        v[2*i] = pos[i];
        v[2*i+1] = neg[i];
    }

 }

 int main(){
    vector<int> nums = {3,1,-2,-5,2,-4};

    rearrangeArr(nums);

    for(auto x: nums) cout<<x<<" ";

    return 0;
 }