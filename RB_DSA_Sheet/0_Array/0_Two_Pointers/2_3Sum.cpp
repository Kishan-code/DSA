#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Leetcode: problem-15: 3Sum
***************************************************************************************8

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 
Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:
3 <= nums.length <= 3000
-10⁵ <= nums[i] <= 10⁵

*/


vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;

    int n = nums.size();
    int low, high, sum = 0;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n-2; i++){
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        low = i+1;
        high = n-1;
        while(low < high){
            sum = nums[i]+nums[low]+nums[high];
            if(sum ==  0){
                ans.push_back({nums[i], nums[low], nums[high]});
                while(low < high && nums[low] == nums[low+1]) low++;
                while(low < high && nums[high] == nums[high-1]) high--;
                low++;
                high--;
            }
            else if(sum < 0) low++;
            else high--;
        }
    }

    return ans;
}


/*
GFG: Triplet Sum in Array
*************************************************************************************

Given an array arr[] and an integer target, determine if there exists a triplet in the array whose sum equals the given target.
Return true if such a triplet exists, otherwise, return false.

Examples: 
Input: arr[] = [1, 4, 45, 6, 10, 8], target = 13
Output: true 
Explanation: The triplet {1, 4, 8} sums up to 13.

Input: arr[] = [1, 2, 4, 3, 6, 7], target = 10
Output: true 
Explanation: The triplets {1, 3, 6} and {1, 2, 7} both sum to 10. 

Input: arr[] = [40, 20, 10, 3, 6, 7], target = 24
Output: false 
Explanation: No triplet in the array sums to 24.

Constraints:
3 ≤ arr.size() ≤ 5*10³
0 ≤ arr[i], target ≤ 10⁵

*/

bool hasTripletSum(vector<int> &arr, int target) {
    int n = arr.size();
    int low, high;
    int sum;
    
    sort(arr.begin(), arr.end());
    
    for(int i = 0; i < n-2; i++){
        low = i+1;
        high = n-1;
        while(low < high){
            sum = arr[i]+arr[low]+arr[high];
            if(sum == target) return true;
            else if(sum < target) low++;
            else high--;
        }
    }
    
    return false;
}

/****************************************************************************************** */ 

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    
    vector<vector<int>> ans = threeSum(nums);

    for(auto x: ans){
        for(auto el: x){
            cout<<el<<" ";
        }
        cout<<endl;
    }

    cout<<hasTripletSum(nums, 0);

    return 0;
}