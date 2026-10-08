#include<iostream>
using namespace std;

/*
Leetcode: Problem-647: Palindromic Substrings
***********************************************************************************************

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Constraints:
1 <= s.length <= 1000
s consists of lowercase English letters.
*/

int expand(string &s, int l, int r){
    int count = 0;
    while(l >= 0 && r < s.size() && s[l] == s[r]){
        l--;
        r++;
        count++;
    }
    return count;
}
int countSubstrings(string s) {
    int n = s.size();
    int count = 0;

    for(int i = 0; i < n; i++){
        int len1 = expand(s, i, i);
        int len2 = expand(s, i, i+1);
        count += len1 + len2;
    }

    return count;
}

// similar problem in GFG

/************************************************************************************* */

int main(void){
    string s = "abbaeae";
    cout<<countSubstrings(s);
}