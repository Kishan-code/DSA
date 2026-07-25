/**
 * Problem - 9: Longest Consecutive Sequence in an Array:
 * ********************************************************************************
 * 
 * Given an array nums of n integers
 * Return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.
 * 
 * eg:
 * Input: nums = [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explaination:
 * The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order of the elements in the array.
 * ********************************************************************************
 * 
 * Approach - 1: Brute Force:
 * we will check sequence for each element
 * make variable maxLen = 0: it will store the length  of the maximum consecutive sequence.
 * now iterate over the array
 * we use two loops outer and inner
 * outer loop iterate over the elements one by one
 * and the inner loop find the sequence of each ith element of outer loop
 * 
 * TC -> O(n²)
 * SC -> O(1)
 * ********************************************************************************
 */

 #include<iostream>
 #include<vector>
 #include<climits>
 using namespace std;

 int longestConsecutive(vector<int> &v){
    int n = v.size();
    int maxLen = 0;
    int count, j, x;

    for(int i = 0; i < n; i++){
        count = 1;
        x = v[i];
        j = 0;
        while(j < n){
            if(v[j] == x+1){
                count++;
                x++;
                j=0;
            }
            else j++;
        }

        maxLen = max(maxLen, count);
    }

    return maxLen;
 }

 int main(){
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout<<longestConsecutive(nums);
    return 0;
 }