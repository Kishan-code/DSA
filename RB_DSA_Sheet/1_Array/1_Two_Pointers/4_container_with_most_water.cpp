#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Leetcode: Problem-11: Container With Most Water
*****************************************************************************

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 
Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1
 

Constraints:
n == height.length
2 <= n <= 10⁵
0 <= height[i] <= 10⁴

*/

int maxArea(vector<int>& height) {
    int n = height.size();

    int max_water = 0, curr_water = 0;
    int i = 0, j = n-1;

    while(i < j){
        curr_water = min(height[i], height[j])*(j-i);
        max_water = max(max_water, curr_water);

        if(height[i] < height[j]) i++;
        else j--;
    }

    return max_water;
}

/**************************************************************************** */

int main(){
    vector<int> nums = {1,8,6,2,5,4,8,3,7};

    cout<<maxArea(nums);

    return 0;
}