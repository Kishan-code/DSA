#include<iostream>
#include <vector>
using namespace std;

/*
GFG: Ceil in Sorted Array
*********************************************************************************************

Given a sorted array arr[] (which may contain duplicate elements) and an integer x, find the 0-based index of the first element greater than or equal to x. This element is called the ceil of x.

If no such element exists, return -1.

Note: If multiple occurrences of the ceil exist, return the index of its first occurrence.

Examples:
Input: arr[] = [1, 2, 8, 10, 11, 12, 19], x = 5
Output: 2
Explanation: Smallest number greater than 5 is 8, whose index is 2.

Input: arr[] = [1, 2, 8, 10, 11, 12, 19], x = 20
Output: -1
Explanation: No element greater than 20 is found. So output is -1.

Input: arr[] = [1, 1, 2, 8, 10, 11, 12, 19], x = 0
Output: 0
Explanation: Smallest number greater than 0 is 1, whose indices are 0 and 1. The index of the first occurrence is 0.


Constraints:
1 ≤ arr.size(), arr[i] ≤ 10^6
0 ≤ x ≤ 10^6
*/

int findCeil(vector<int>& arr, int x) {
    int n = arr.size();
    int idx = -1;
    
    int left = 0, right = n-1;
    int mid;
    
    while(left <= right){
        mid = left+(right-left)/2;
        
        if(arr[mid] >= x){
            idx = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    
    return idx; 
}

/************************************************************************************** */

int main(void){
    vector<int> nums = {1, 2, 8, 10, 11, 12, 19};

    cout<<findCeil(nums, 5);
}