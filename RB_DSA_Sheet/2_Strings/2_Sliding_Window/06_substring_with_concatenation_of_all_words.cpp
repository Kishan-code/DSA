#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Leetcode: Problem-30: Substring with Concatenation of All Words
************************************************************************************************

You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.

 

Example 1:
Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation:
The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.

Example 2:
Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []
Explanation:
There is no concatenated substring.

Example 3:
Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
Explanation:
The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].

 

Constraints:
1 <= s.length <= 10^4
1 <= words.length <= 5000
1 <= words[i].length <= 30
s and words[i] consist of lowercase English letters.
*/

vector<int> findSubstring(string s, vector<string>& words) {
    int n = s.size();
    int m = words.size();
    int p = words[0].size();

    vector<int> res;

    unordered_map<string, int> w_map;

    for(auto wrd: words){
        w_map[wrd]++;
    }

    string rt_str, lt_str;

    for(int offset = 0; offset < p; offset++){            
        int left = offset;
        int count = m;
        unordered_map<string, int> s_map;

        for(int right = offset; right+p <= n; right += p){
            rt_str = s.substr(right, p);

            if(!w_map.count(rt_str)){
                s_map.clear();
                count = m;
                left = right + p;
                continue;
            }


            s_map[rt_str]++;
            if(w_map.count(rt_str) && s_map[rt_str] <= w_map[rt_str]) count--;

            while(right - left + 1 > m*p){
                lt_str = s.substr(left, p);

                s_map[lt_str]--;
                if(w_map.count(lt_str) && s_map[lt_str] < w_map[lt_str]) count++;

                if(s_map[lt_str] == 0) s_map.erase(lt_str);

                left += p;
            }

            if(count == 0 && w_map == s_map){
                res.push_back(left);
            }
        }
    }

    return res;
}

/********************************************************************************************* */

int main(void){
    string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    vector<string> words = {"fooo","barr","wing","ding","wing"};

    vector<int> ans = findSubstring(s, words);

    for(auto x: ans) cout<<x<<" ";
}