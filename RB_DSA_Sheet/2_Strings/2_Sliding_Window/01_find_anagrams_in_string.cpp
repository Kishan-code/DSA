#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Leetcode: Problem-438: Find All Anagrams in a String
**************************************************************************************

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

 

Example 1:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:
1 <= s.length, p.length <= 3 * 10^4
s and p consist of lowercase English letters.
*/

vector<int> findAnagrams(string s, string p) {
    int n = s.size();
    int k = p.size();

    vector<int> res;

    if(n < k) return res;

    unordered_map<char, int> s_map, p_map;

    for(auto ch: p){
        p_map[ch]++;
    }

    int left = 0, count = k;

    for(int right = 0; right < n; right++){
        char ch = s[right];
        s_map[ch]++;

        if(p_map.count(ch) && s_map[ch] <= p_map[ch]){
            count--;
        }

        if(right - left + 1 > k){
            char left_char = s[left];
            if(p_map.count(left_char) && s_map[left_char] <= p_map[left_char]){
                count++;
            }
            s_map[left_char]--;
            left++;
        }
        if(count == 0){
            res.push_back(left);
        }
    } 

    return res;
}

// similar problem in GFG

/************************************************************************************ */

int main(void){
    vector<int> ans = findAnagrams("cbaebabacd", "abc");

    for(auto x: ans) cout<<x<<" ";
}