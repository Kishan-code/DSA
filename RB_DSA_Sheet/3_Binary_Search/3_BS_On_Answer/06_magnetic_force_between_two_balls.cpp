#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Leetcode: Problem-1552: Magnetic Force Between Two Balls
**************************************************************************************

In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.

 

Example 1:
Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.

Example 2:
Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: We can use baskets 1 and 1000000000.
 

Constraints:
n == position.length
2 <= n <= 10^5
1 <= position[i] <= 10^9
All integers in position are distinct.
2 <= m <= position.length
*/

bool canDist(vector<int>& position, int m, int f){
    int ct = 1;
    int pos = position[0];

    for(int i = 1; i < position.size(); i++){
        if(f <= position[i]-pos){
            ct++;
            pos = position[i];
        }
    }

    return ct >= m;
}

int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());

    int low = 1;
    int high = position[position.size()-1] - position[0];

    int max_force = low;
    int mid;

    while(low <= high){
        mid = low+(high-low)/2;

        if(canDist(position, m, mid)){
            max_force = mid;
            low = mid+1;
        }
        else high = mid-1;
    }

    return max_force;
}

/*********************************************************************************** */

int main(void){
    vector<int> nums = {5,4,3,2,1,1000000000};

    cout<<maxDistance(nums, 2);
}