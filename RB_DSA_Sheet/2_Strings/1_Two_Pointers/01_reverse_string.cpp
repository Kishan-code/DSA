#include<iostream>
#include <vector>
using namespace std;

/*
Leetcode: Problem-344: Reverse String
***************************************************************************************

Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 
Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:
1 <= s.length <= 10^5
s[i] is a printable ascii character.
*/

void reverseString(vector<char>& s) {
    int i = 0, j = s.size()-1;
    while(i < j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}


/*
GFG: Reverse a String
***************************************************************************************

You are given a string s, and your task is to reverse the string.

Examples:
Input: s = "Geeks"
Output: "skeeG"

Input: s = "for"
Output: "rof"

Input: s = "a"
Output: "a"


Constraints:
1 ≤ s.size() ≤ 10^6
s consists only of English alphabets
*/

string reverseString(string& s) {
    int i = 0, j = s.length()-1;
    while(i < j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    
    return s;
}

/********************************************************************************* */

int main(void){
    vector<char> s = {'H', 'e', 'l', 'l', 'o'};
    reverseString(s);

    for(auto ch: s)
        cout<<ch<<" ";

    string str = "Hello";
    cout<<endl<<reverseString(str);
}