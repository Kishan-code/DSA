#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
GFG: Aggressive Cows
****************************************************************************************

Given an integer array arr[], which denotes the positions of stalls. All the positions are distinct. There are k aggressive cows.

Assign the cows to the stalls such that the minimum distance between any two cows is maximized.

Examples:
Input: arr[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at arr[0], the second at arr[2], and the third at arr[3]. The minimum distance between any two cows is 3 (between arr[0] and arr[2]), which is the maximum possible among all valid arrangements.

Input: arr[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at arr[0], the second at arr[1], and the third at arr[4]. In this arrangement, the minimum distance between any two cows is 4 (between arr[1] and arr[4]), which is the maximum possible among all valid arrangements.


Constraints:
arr.size() ≤ 10^6
0 ≤ arr[i] ≤ 10^8
2 ≤ k ≤ arr.size()
*/

bool canTie(vector<int> &arr, int k, int gap){
    int ct = 1;
    int dist = arr[0];
    
    for(int i = 1; i < arr.size(); i++){
        if(abs(arr[i]-dist) >= gap){
            ct++;
            dist = arr[i];
        }
    }
    
    return ct >= k;
}

int aggressiveCows(vector<int> &arr, int k) {
    sort(arr.begin(), arr.end());
    
    int low = 1;
    int high = arr[arr.size()-1] - arr[0];
            
    int min_dist = 0;
    int mid;
    
    
    while(low <= high){
        mid = low+(high-low)/2;
        
        if(canTie(arr, k, mid)){
            min_dist = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    
    return min_dist;
}

/*********************************************************************************** */

int main(void){
    vector<int> nums = {1, 2, 4, 8, 9};

    cout<<aggressiveCows(nums, 3);
}