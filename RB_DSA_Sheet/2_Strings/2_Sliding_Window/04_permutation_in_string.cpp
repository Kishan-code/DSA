#include<iostream>
#include <vector>
using namespace std;

/*
Leetcode: Problem-567: Permutation in String
*****************************************************************************************

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:
1 <= s1.length, s2.length <= 10^4
s1 and s2 consist of lowercase English letters.
*/

bool checkInclusion(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    if(n > m) return false;

    vector<int> arr1(26,0);
    vector<int> arr2(26,0);

    for(auto ch: s1){
        arr1[ch - 'a']++;
    }

    int left = 0;
    for(int right = 0; right < m; right++){
        char right_char = s2[right];
        arr2[right_char - 'a']++;

        if(right-left+1 > n){
            char left_char = s2[left];
            arr2[left_char - 'a']--;
            left++;
        }

        if(arr1 == arr2) return true;
    }

    return false;

}


/*************************************************************************************** */

int main(void){
    cout<<checkInclusion("ab", "eidbaooo");
}