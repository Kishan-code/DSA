/*
Leetcode: Problem-167: Two Sum II - Input Array Is Sorted
****************************************************************************

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers index1 and index2, each incremented by one, as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

Example 3:
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
 

Constraints:
2 <= numbers.length <= 3 * 10⁴
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000

*/

#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> ans(2,-1);
    int n = numbers.size();
    int i = 0, j = n - 1;
    int sum;
    while(i < j){
        sum = numbers[i] + numbers[j];
        if(sum == target){
            ans[0] = i+1;
            ans[1] = j+1;
            return ans;
        }
        else if(sum < target) i++;
        else j--;
    }

    return ans;
}


/*
GFG: Problem- Counts Pairs with Sum in Sorted
************************************************************************************************

You are given an integer target and an array arr[]. You need to find number of pairs in arr[] which sums up to target. It is given that the elements of the arr[] are in sorted order.

Note:  Pairs should have elements of distinct indexes. 

Examples :
Input: arr[] = [-1, 1, 5, 5, 7], target = 6
Output: 3
Explanation: There are 3 pairs which sum up to 6 : {1, 5}, {1, 5} and {-1, 7}.

Input: arr[] = [1, 1, 1, 1], target = 2
Output: 6
Explanation: There are 6 pairs which sum up to 2 : {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1} and {1, 1}.

Input: arr[] = [-1, 10, 10, 12, 15], target = 125
Output: 0
Explanation: There is no such pair which sums up to 125.


Constraints:
-10⁵ <= target <=10⁵
 2 <= arr.size() <= 10⁵
-10⁵ <= arr[i] <= 10⁵

*/

int countPairs(vector<int> &arr, int target) {
    // Code Here
    unordered_map<int, int> mp;
    int count_pairs = 0;
    
    int n = arr.size();
    
    for(int i = 0; i < n; i++){
        int key = target - arr[i];
        if(mp.count(key)){
            count_pairs += mp[key];
        }
        mp[arr[i]]++;
    }
    
    return count_pairs;
}

int main(){
    vector<int> nums = {-1, 1, 5, 5, 7};
    int target = 6;

    vector<int> ans = twoSum(nums, target);

    for(auto x: ans) cout<<x<<" ";

    cout<<endl;

    cout<<countPairs(nums, target);

    return 0;
}