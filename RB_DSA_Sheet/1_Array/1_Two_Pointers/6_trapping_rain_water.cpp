#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/*
Leetcode: Problme-42: Trapping Rain Water
***********************************************************************************************

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:
n == height.length
1 <= n <= 2 * 10⁴
0 <= height[i] <= 10⁵

*/

int trap(vector<int>& height) {
    int n = height.size();
    int left = 0, right = n-1;
    int left_max = height[left], right_max = height[right];
    int water = 0;

    while(left < right){
        if(left_max < right_max){
            left++;
            left_max = max(left_max, height[left]);
            water += left_max - height[left];
        }
        else{
            right--;
            right_max = max(right_max, height[right]);
            water += right_max - height[right];
        }
    }

    return water;
}

//****************************************************************************************

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout<<trap(height);

    return 0;
}