#include<iostream>
#include <unordered_map>
using namespace std;

/*
GFG: Longest Substring with K Uniques
*****************************************************************************************************

You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.

Note : If no such substring exists, return -1. 

Examples:
Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.

Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.

Input: s = "aabaaab", k = 2
Output: 7
Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.


Constraints:
1 ≤ s.size() ≤ 10^5
1 ≤ k ≤ 26

*/

int longestKSubstr(string &s, int k) {
    int n = s.size();
    
    unordered_map<char, int> mp;
    int left = 0;
    int max_len = -1;
    
    for(int right = 0; right < n; right++){
        char ch = s[right];
        mp[ch]++;
        
        
        while(mp.size() > k){
            char left_char = s[left];
            mp[left_char]--;
            left++;
            if(mp[left_char] == 0){
                mp.erase(left_char);
            }
        }
        
        if(mp.size() == k) max_len = max(max_len, right-left+1);
    }
    
    return max_len;
}

/****************************************************************************************************** */

int main(void){
    string str = "aabacbebebe";
    cout<<longestKSubstr(str, 3);
}