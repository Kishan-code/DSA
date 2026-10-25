#include<iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

/*
Leetcode: Problem-496: Next Greater Element I
***************************************************************************************************

The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
 

Constraints:
1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 10^4
All integers in nums1 and nums2 are unique.
All the integers of nums1 also appear in nums2.
*/

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nge;
    vector<int> ans(nums1.size());
    stack<int> st;
    for(int i = 0; i < nums2.size(); i++){
        while(!st.empty() && nums2[i] > st.top()){
            nge[st.top()] = nums2[i];
            st.pop();
        }
        st.push(nums2[i]);
    }
    while(!st.empty()){
        nge[st.top()] = -1;
        st.pop();
    }

    for(int i = 0; i < nums1.size(); i++){
        ans[i] = nge[nums1[i]];
    }

    return ans;
}


/*
GFG: Next Greater Element
*****************************************************************************************************

You are given an array arr[] of integers, the task is to find the next greater for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1.

Examples
Input: arr[] = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
Explanation: The next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4, since it doesn't exist, it is -1.

Input: arr[] = [6, 8, 0, 1, 3]
Output: [8, -1, 1, 3, -1]
Explanation: The next larger element to 6 is 8, for 8 there is no larger elements hence it is -1, for 0 it is 1, for 1 it is 3 and then for 3 there is no larger element on right and hence -1.

Input: arr[] = [1, 2, 3, 5]
Output: [2, 3, 5, -1]
Explanation: For a sorted array, the next element is next greater element also except for the last element.

Input: arr[] = [5, 4, 3, 1]
Output: [-1, -1, -1, -1]
Explanation: There is no next greater element for any of the elements in the array, so all are -1.
Constraints:

1 ≤ arr.size() ≤ 10^6
0 ≤ arr[i] ≤ 10^9
*/

vector<int> nextLargerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    
    stack<int> st;
    
    for(int i = 0; i < n; i++){
        while(!st.empty() && nums[st.top()] < nums[i]) {
            ans[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    
    return ans;
}

/************************************************************************************************ */

int main(void){
    vector<int> nums1 = {4,1,2}, nums2 = {1,3,4,2};

    vector<int> ans1 = nextGreaterElement(nums1, nums2);
    vector<int> ans2 = nextLargerElement(nums2);

    for(auto x: ans1) cout<<x<<" ";
    cout<<endl<<endl;
    for(auto x: ans2) cout<<x<<" ";
}