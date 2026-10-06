#include<iostream>
using namespace std;

/*
Leetcode: Problem-680: Valid Palindrome II
***************************************************************************************

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:
Input: s = "aba"
Output: true

Example 2:
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.

Example 3:
Input: s = "abc"
Output: false
 

Constraints:
1 <= s.length <= 10^5
s consists of lowercase English letters.
*/

bool isPal(string s, int l, int r){
    while(l < r){
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

bool validPalindrome(string s) {
    int left = 0, right = s.size()-1;

    while(left < right){
        if(s[left] != s[right]){
            return isPal(s, left, right-1) || isPal(s, left+1, right);
        }
        left++;
        right--;
    }

    return true;
}

// similar Problem in GFG

/************************************************************************************* */

int main(void){
    string s = "ebcbbececabbacecbbcbe";

    cout<<validPalindrome(s);
    
}