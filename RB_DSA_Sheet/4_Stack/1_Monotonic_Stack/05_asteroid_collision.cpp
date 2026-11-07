#include<iostream>
#include <vector>
#include <stack>
using namespace std;

/*
Leetcode: Problem-735: Asteroid Collision
****************************************************************************************

We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 
Example 1:
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

Example 2:
Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.

Example 3:
Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

Example 4:
Input: asteroids = [3,5,-6,2,-1,4]​​​​​​​
Output: [-6,2,4]
Explanation: The asteroid -6 makes the asteroid 3 and 5 explode, and then continues going left. On the other side, the asteroid 2 destroys -1. Since 2 and 4 are both moving right, they never collide.
 

Constraints:
2 <= asteroids.length <= 10^4
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
*/

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> ans;
    stack<int> st;

    int n = asteroids.size();

    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && st.top() < 0 && asteroids[i] > 0 && -st.top() < asteroids[i]) st.pop();
        if(!st.empty() && st.top() < 0 && asteroids[i] > 0){
            if(-st.top() == asteroids[i]) st.pop();
        }
        else st.push(asteroids[i]);
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}


/*
GFG: Opposite Sign Pair Reduction
*****************************************************************************************

Given an array arr[] , return the final array by repeatedly apply the following operation from left to right until no more valid operations can be performed.

If two adjacent elements have opposite signs:

If their absolute values are different, remove both elements and insert the one with the greater absolute value, preserving its sign.
If their absolute values are equal, remove both elements without inserting any new element.

Examples : 
Input: arr[] = [10, -5, -8, 2, -5]
Output: [10]
Explanation: 
At Index 0 : Element 10 has positive sign.
At Index 1 : -5  has lesser absolute value than 10. Replace both of them with 10.
At Index 2 : -8  has lesser absolute value than 10. Replace both of them with 10.
At Index 3 : 2 has positive sign. So it will be in the array.
At Index 4 : -5  has greater absolute value than 2. Replace both of them with 5.
Now -5  has lesser absolute value than 10. Replace both of them with 10.

Input: arr[] = [5, -5, -2, -10]
Output: [-2, -10]
Explanation: 1st and 2nd element gets discarded because both elements have same values but opposite sign. 3rd and 4th elements have same sign. So, both will be in the array.
Input: arr[] = [-20, 1, 20]
Output: []
Explanation: 1st and 2nd elements are removed, and -20 is inserted since it has the larger absolute value. Then, the remaining elements [-20, 20] are removed (equal absolute values, opposite signs).


Constraints:
1 ≤ arr.size() ≤ 10^5
-10^4 ≤ arr[i] ≤ 10^4
arr[i] != 0
*/

vector<int> reducePairs(vector<int>& arr) {
    stack<int> st;
    
    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && 
        ((st.top() < 0 && arr[i] > 0) || (st.top() > 0 && arr[i] < 0)) &&
        abs(st.top()) < abs(arr[i])) st.pop();
        
        if(!st.empty() && 
        ((st.top() < 0 && arr[i] > 0) || (st.top() > 0 && arr[i] < 0))){
            if(abs(st.top()) == abs(arr[i])) st.pop();
        }
        else st.push(arr[i]);
    }
    
    vector<int> ans(st.size());
    
    for(int j = st.size()-1; j >= 0; j--){
        ans[j] = st.top();
        st.pop();
    }
    
    return ans;
}

/************************************************************************************* */

int main(void){
    vector<int> nums = {10, -5, -8, 2, -5};

    vector<int> ans1 = asteroidCollision(nums);
    vector<int> ans2 = reducePairs(nums);

    for(auto x: ans1) cout<<x<<" ";
    cout<<endl;
    for(auto x: ans2) cout<<x<<" ";
}