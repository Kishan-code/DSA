#include<iostream>
#include <unordered_map>
using namespace std;

/*
Leetcode: Problem-3: Longest Substring Without Repeating Characters
*****************************************************************************************************

Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:
0 <= s.length <= 10^5
s consists of English letters, digits, symbols and spaces.
*/


// int lengthOfLongestSubstring(string s) {
//     int n = s.length();

//     unordered_map<char, int> mp;

//     int maxLen = 0;
//     int left = 0;

//     for(int right = 0; right < n; right++){
//         char ch = s[right];
        
//         if(mp.count(ch)){
//             left = max(left, mp[ch]+1);
//         }

//         mp[ch] = right;
//         maxLen = max(maxLen, right-left+1);
//     }
//     return maxLen;
// }


int lengthOfLongestSubstring(string s) {
    int n = s.length();

    unordered_map<char, int> freq;

    int maxLen = 0;
    int left = 0;
    for(int right = 0; right < n; right++){
        freq[s[right]]++;
        while(freq[s[right]] > 1){
            freq[s[left]]--;
            left++;
        }
        maxLen = max(maxLen, right-left+1);
    }
    return maxLen;
}

// similar problem in GFG

/*************************************************************************************************** */

int main(void){
    cout<<lengthOfLongestSubstring("geeksforgeeks");
}