#include<iostream>
using namespace std;

/*
Leetcode: Problem-5: Longest Palindromic Substring
************************************************************************************************

Given a string s, return the longest palindromic substring in s.

 

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"
 

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.
*/

int expand(string &s, int l, int r){
    while(l >= 0 && r < s.size() && s[l] == s[r]){
        l--;
        r++;
    }
    return r-l-1;
}

string longestPalindrome(string s) {
    int n = s.size();
    int start = 0, end = 0;

    for(int i = 0; i < n; i++){
        int len1 = expand(s, i, i);
        int len2 = expand(s, i, i+1);
        int len = max(len1, len2);

        if(len > (end - start + 1)){
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substr(start, end-start+1);
}

// similar in GFG

/**************************************************************************************** */

int main(void){
    string s = "bswrhxboawtdfqggqfdtwyypwnssnwpyyaobxhrwsb";
    cout<<longestPalindrome(s);
}