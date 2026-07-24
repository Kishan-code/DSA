/**
 * Problem - 8: Leaders in an Array:
 * ******************************************************************************
 * 
 * Given an integer array nums, return a list of all the leaders in the array.
 * 
 * A leader in an array is an element whose value is strictly greater than all elements to its right in the given array. The rightmost element is always a leader. The elements in the leader array must appear in the order they appear in the nums array.
 * 
 * eg:
 * Input: nums = [1, 2, 5, 3, 1, 2]
 * Output: [5, 3, 2]
 * Explanation: 2 is the rightmost element, 3 is the largest element in the index range [3, 5], 5 is the largest element in the index range [2, 5]
 * *****************************************************************************
 * 
 * Approach -1: Brute Force
 * check for each element
 * for each ith element check for every jth (i < j < n) element ith element is larger than ith element will be the leader ans add it in the answer array.
 * otherwise move to the next element.
 * 
 * TC -> O(n²)
 * SC -> O(n)
 * 
 */

 #include<iostream>
 #include<vector>
 using namespace std;


 // Brute Force
 vector<int> leaders(vector<int> &v){
    vector<int> ans;
    int n = v.size();

    bool flag;

    for(int i = 0 ; i < n; i++){
        flag = true;
        for(int j = i+1; j < n; j++){
            if(v[i] < v[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            ans.push_back(v[i]);
        }
    }

    return ans;
 }

 int main(){
    vector<int> nums = {-3, 4, 5, 1, -30, -10};

    vector<int> ans = leaders(nums);

    for(auto x: ans) cout<<x<<" ";

    return 0;
 }