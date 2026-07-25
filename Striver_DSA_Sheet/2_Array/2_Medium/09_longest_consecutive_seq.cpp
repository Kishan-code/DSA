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
 * 
 * Approach -2: Better
 * first we sort the array
 * and we will keep the track of lastSmaller number
 * iterate over the array and
 * if(nums[i] == lastSmaller+1)
 *  then we increase the count by 1 (count++)
 *  and put nums[i] in lastSmaller: (lastSmaller = nums[i])
 * else if(nums[i] != lastSmaller)
 *  then we set count to 1: (count = 1)
 *  and put lastSmaller = nums[i]
 * else we put maxLen = max(maxLen, count)
 * 
 * after the end of the loop return maxLen
 * 
 * TC ->  O(n) + O(nlogn) [nlogn for sorting the array]
 * SC -> O(1)
 */

 #include<iostream>
 #include<vector>
 #include<algorithm>
 #include<climits>
 using namespace std;

 // Brute Force
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

 // Better
 int longestConsecutive1(vector<int> &v){
    int n = v.size();
    int maxLen = 0;
    int count = 0;
    int lastSmaller = INT_MIN;

    sort(v.begin(), v.end()); //{0,0,1,2,3,4,5,6,7,8}

    for(int i = 0; i < n; i++){
        if(v[i] == lastSmaller+1){
            count++;
            lastSmaller = v[i];
        }
        else if(v[i] != lastSmaller){
            count = 1;
            lastSmaller = v[i];
        }
        maxLen = max(maxLen, count);
    }

    return maxLen;
 }

 int main(){
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    // cout<<longestConsecutive(nums);
    cout<<longestConsecutive1(nums);
    return 0;
 }