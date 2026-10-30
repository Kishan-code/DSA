#include<iostream>
#include <vector>
using namespace std;

/*
GFG: Count Occurrences in Sorted
*********************************************************************************************

Given a sorted array arr[] and a number target, find the number of occurrences of target in given array. 

Examples:
Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
Output: 4
Explanation: target = 2 occurs 4 times in the given array so the output is 4.

Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
Output: 0
Explanation: target = 4 is not present in the given array so the output is 0.

Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
Output: 3
Explanation: target = 12 occurs 3 times in the given array so the output is 3.


Constraints:
1 ≤ arr.size(), arr[i], target ≤ 10^6
*/

int countFreq(vector<int>& arr, int target) {
    int n = arr.size();
    int first_idx = 0, last_idx = -1;
    int left = 0, right = n-1;
    int mid;
    
    // first Occurrence
    while(left <= right){
        mid = left+(right-left)/2;
        
        if(arr[mid] == target){
            first_idx = mid;
            right = mid-1;
        }
        else if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    
    left = 0, right = n-1;
    
    // last occurrence
    while(left <= right){
        mid = left+(right-left)/2;
        
        if(arr[mid] == target){
            last_idx = mid;
            left = mid+1;
        }
        else if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    
    return last_idx - first_idx + 1;
}

/************************************************************************************** */

int main(void){
    vector<int> nums = {8, 9, 10, 12, 12, 12};

    cout<<countFreq(nums, 12);
}