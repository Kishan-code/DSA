#include<iostream>
#include <unordered_map>
#include <climits>
using namespace std;

/*
Leetcode: Problem-76: Minimum Window Substring
***************************************************************************************

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:
m == s.length
n == t.length
1 <= m, n <= 10^5
s and t consist of uppercase and lowercase English letters.
*/

string minWindow(string s, string t) {
    int n = s.size();
    int m = t.size();

    if (m > n) return "";

    unordered_map<char, int> t_map, s_map;

    for (char ch : t) {
        t_map[ch]++;
    }

    int left = 0;
    int count = m;
    
    int start = 0;
    int min_len = INT_MAX;

    for (int right = 0; right < n; right++) {
        char right_char = s[right];
        s_map[right_char]++;

        if (t_map.count(right_char) &&
            s_map[right_char] <= t_map[right_char]) {
            count--;
        }

        while (count == 0) {
            int len = right - left + 1;

            if (len < min_len) {
                min_len = len;
                start = left;
            }

            char left_char = s[left];
            s_map[left_char]--;
            left++;

            if (t_map.count(left_char) &&
                s_map[left_char] < t_map[left_char]) {
                count++;
            }
        }
    }

    if (min_len == INT_MAX) return "";

    return s.substr(start, min_len);
}

// similar problem in GFG

/*************************************************************************************** */

int main(void){
    string s = "ADOBECODEBANC", t = "ABC";
    
    cout<<minWindow(s, t);
}