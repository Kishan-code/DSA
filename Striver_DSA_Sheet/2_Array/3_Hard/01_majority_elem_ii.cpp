/**
 * Problem - 1: Majority Element II
 * ****************************************************************************
 * 
 * Given an integer array of size n, find all elements that appear more than ⌊n / 3⌋ times.
 * 
 * Example 1:
 * Input: nums = [3,2,3]
 * Output: [3]
 * 
 * Example 2:
 * Input: nums = [1]
 * Output: [1]
 * *****************************************************************************
 * 
 * NOTE: for elements that appear more than ⌊n/k⌋ times. (k-1) maximum 
 * elements can be possible
 * *****************************************************************************
 * 
 * Approach -1: Brute Force
 * we itererate over the array ans check the frequency of each element
 * 
 * if freq of any element becomes greater than ⌊n/3⌋ 
 * then we store that element in the set (for avoiding duplication) and set count to 0.
 * and check  for the next element.
 * 
 * 
 * TC -> O(n²) 
 * SC -> O(1)
 * ***************************************************************************
 * 
 * Approach -2: Better (hashing)
 * in this approach we'll use hashmap for storing the elements with their frequency count.
 * 
 * we know that for ( > ⌊n/3⌋ ) we need minimum (⌊n/3⌋  + 1) frequency count.
 * if any elements frequency is equal to the (⌊n/3⌋  + 1) we add that element to the  answer array and so on.
 * 
 * TC -> O(n)
 * SC -> O(n) (worst case)
 * ****************************************************************************
 * 
 * Approach -3: Optimal (Moore's Voting Algorithm)
 * for more than ⌊n/2⌋ majority element there can be possible only 1 element.
 * for more than ⌊n/3⌋ majority element there can be possible 2 maximum elements.
 * 
 * so we will check for 2 candidates:
 * 
 * First Pass (Find Potential Candidates):
 * for each element x in the array we check these:
 * CASE1: if(x == candidate1):
 *        current element is already a candidate1
 *        then count1++
 * CASE2: if(x == candidate2):
 *        current element is already a candidate1
 *        then count2++
 * CASE3: if(count1 == 0):
 *        slot of candidate1 is empty
 *        then candidate1 = x and count1 = 1
 * CASE4: if(count2 == 0):
 *        slot of candidate2 is empty
 *        then candidate2 = x and count2 = 1
 * CASE5: candidate1, candidate2 and x all are different:
 *        then count1-- and count2--
 * 
 * Second Pass (Verification):
 * first pass only gives Potential Candidates not actual answer.
 * so in this pass we check that selected candidates are valid or not by ieterating over the array and check the selected candidates having the frequency more than ⌊n/3⌋. If yes then we add that candidate to the answer array.
 * 
 * TC -> O(n)
 * SC -> O(1)
 */

#include<iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Brute Force:
vector<int> majorityElement1(vector<int>& nums){
    int n = nums.size();
    int count;
    unordered_set<int> ans;

    for(int i = 0; i < n; i++){
        count = 0;
        for(int j = 0; j < n; j++){
            if(nums[i] == nums[j]) count++;
        }
        if(count > n/3) ans.insert(nums[i]);
    }

    return {ans.begin(), ans.end()};
}

// Better:
vector<int> majorityElement2(vector<int>& nums){
    vector<int> ans;
    unordered_map<int, int> freq;
    int n = nums.size();
    int min = (n/3)+1;
    
    for(int i = 0; i < n; i++){
        freq[nums[i]]++;
        if(freq[nums[i]] == min) ans.push_back(nums[i]);
    }
    return ans;
}

// Optimal
vector<int> majorityElement3(vector<int>& nums){
    int k = nums.size()/3;
    vector<int> ans;
    int candidate1 = nums[0], candidate2 = nums[0];
    int count1 = 0, count2 = 0;

    for(auto x: nums){
        if(x == candidate1) count1++;
        else if(x == candidate2) count2++;
        else if(count1 == 0){
            candidate1 = x;
            count1 = 1;
        }
        else if(count2 == 0){
            candidate2 = x;
            count2 = 1;
        }
        else{
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;

    for(auto x: nums){
        if(x == candidate1) count1++;
        else if(x == candidate2) count2++;
    }

    if(count1 > k) ans.push_back(candidate1);
    if(count2 > k) ans.push_back(candidate2);

    return ans;
}

/********************************************************************** */

int main(){
    vector<int> nums = {3,2,3,3,2,1,2,3};
    
    // vector<int> ans = majorityElement1(nums);
    // vector<int> ans = majorityElement2(nums);
    vector<int> ans = majorityElement3(nums);

    for(auto x: ans) cout<<x<<" ";
    return 0;
}